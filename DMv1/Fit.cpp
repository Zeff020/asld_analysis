/*


This file fits the D mass data from the 2016 dataset, and following this calculates the SWeights and adds them to a new nTuple.


 */
#include <TFile.h>
#include <TTree.h>
#include <TROOT.h>
#include <string>


// All of the roofit stuff
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooDataHist.h>
#include <RooGaussian.h>
#include <RooPlot.h>
#include <typeinfo>
#include <RooHistPdf.h>
#include "Inclusion.h"

using namespace std;
using namespace RooFit;
using namespace RooStats;

std::string Fit(const char* filename,const char* filenamedata){
  
  TFile *f = new TFile(filename);
  TH1D *D_M_hist = static_cast<TH1D *>(f->Get("D_M_hist"));
  D_M_hist -> Rebin(5);
  
  // Define mass boundaries
  RooRealVar *mD = new RooRealVar("D_M","mass D",1800, 1980,"MeV"); 
  // Create RooDataSet from the tree
  RooDataHist * data = new RooDataHist("fitData","fit input dataset",RooArgList(*mD),D_M_hist);	
  
  //----------------------------------------------- FITTING ----------------------------------------------------//
  RooRealVar *FC = new RooRealVar("FC","FC",0.50,0.0,1.0); 	
  RooFormulaVar* fracS = new RooFormulaVar("fracS","(1.0-FC)",RooArgList(*FC)); 
	
  RooRealVar *nsig =  new RooRealVar("nsig", "nsig", 20.E5, 0., 10.E6); 	
  RooRealVar *nbkg =  new RooRealVar("nbkg", "nbkg", 5.E5, 0., 10.E6); 	

  RooRealVar *mean1 = new RooRealVar("mean1","mean1",1866.1,1830.,1900.); 	
  RooRealVar *sigma1 = new RooRealVar("sigma1","sigma1",5.0,3.0,20.0);         
  RooAbsPdf *gauss1 = new RooGaussian("gauss1","gauss(mD, mean1, sigma1)",*mD,*mean1,*sigma1); 	

  RooRealVar *sigma2 = new RooRealVar("sigma2","sigma2",10.0,5.0,25.0);         
  RooAbsPdf *gauss2 = new RooGaussian("#gauss2","gauss(mD, mean1, sigma2)",*mD,*mean1,*sigma2); 
	
  RooAddPdf *Sig_mD = new RooAddPdf("Sig_mD", "Sig_mD", RooArgList(*gauss1, *gauss2), RooArgList(*FC, *fracS)); 
	
  RooRealVar *par = new RooRealVar("par","par",0.0, -1.0, 1.0); 	

  RooChebychev *Bkg_mD = new RooChebychev("Bkg_mD","Bkg_D_M", *mD, RooArgList(*par));  	

  RooAddPdf *model = new RooAddPdf("model", "model", RooArgList(*Sig_mD, *Bkg_mD), RooArgList(*nsig, *nbkg));

  model -> fitTo(*data);


  //-------------------------------------------------PLOTTING-------------------------------------------------//
  TCanvas* mD_canvas = new TCanvas("mD_Fit","mD Fit");
  RooPlot* mD_frame = mD -> frame();
  data -> plotOn(mD_frame, Name("Data"));
  model->plotOn(mD_frame, Name("Model"));
  model->plotOn(mD_frame, Name("Sig"),Components("Sig_mD"),LineStyle(kDashed),LineColor(4)); 	
  model->plotOn(mD_frame, Name("Bkg"),Components("Bkg_mD"),LineStyle(kDashed),LineColor(2)); 
  
  model->paramOn(mD_frame, Parameters(RooArgList(*mean1, *nsig)), Layout(.64, .89, .8)); 	
  data->statOn(mD_frame, What("N"), Layout(.64, .89, .88));
  //mD_frame->Draw();
  

  
  // Pull plot
  RooHist* hpull = mD_frame->pullHist("Data","Model") ;
  RooPlot* pull_frame = mD -> frame(Title("Pull Distribution")) ;
  pull_frame->addPlotable(hpull,"P");


  // Divide the canvas into subplots
  mD_canvas->Divide(2) ;
  mD_canvas->cd(1) ; gPad->SetLeftMargin(0.15) ; mD_frame->GetYaxis()->SetTitleOffset(1.6) ; mD_frame->Draw() ;
  mD_canvas->cd(2) ; gPad->SetLeftMargin(0.15) ; pull_frame->GetYaxis()->SetTitleOffset(1.6) ; pull_frame->Draw() ;
  
  //-------------------------------------------------SPLOT-------------------------------------------------//
  sigma1->setConstant();		
  mean1->setConstant();		
  par->setConstant();		
  FC->setConstant();

  TFile *f1 = new TFile(filenamedata);
  TTree *tr = (TTree*)f1->Get("DecayTree");

  Double_t         D_M;

  tr->SetBranchAddress("D_M", &D_M);

  tr->SetBranchStatus("*",0);
  tr->SetBranchStatus("D_M",1);

  // Create RooDataSet from the tree
  RooDataSet * data1 = new RooDataSet("fitData","fit input dataset",tr,RooArgList(*mD));	
  
  RooStats::SPlot* sDataPlot = new RooStats::SPlot("sData","Data sPlot", *data1, model, RooArgList(*nsig,*nbkg)); // Calculate sweights against original, unbinned data

  
  // RooDataSet * data_sig = new RooDataSet(data->GetName(),data->GetTitle(),data,*data->get(),0,"nsig_sw") ; 	
  // RooDataSet * data_bkg = new RooDataSet(data->GetName(),data->GetTitle(),data,*data->get(),0,"nbkg_sw") ;
  
  nsig->Print();   
  double Nsig = nsig->getValV();   
  double Nall = data1->numEntries();
  cout << Nsig << " signal events; Significance = " << Nsig/sqrt(Nall) << endl;

  
  //---------------------------------------------B CORRECTED------------------------------------------------//
  
  //-------------------------------------------------SAVE---------------------------------------------------//

  std::string filename_s(filename);
  std::string root = ".root";
  std::string DM = "DM";
  std::string newfilenamenoroot = filename_s.erase(filename_s.find(".root"));
  newfilenamenoroot = filename_s.erase(filename_s.find("DM"));

  std::string newfilename = newfilenamenoroot + "sweights" + root;
  const char *newfilename_c = newfilename.c_str();


  // Creating new TFile to save TTree in
  TFile* newf = new TFile(newfilename_c, "recreate");
  
  // Copying the original TTree
  //TTree* trout = new TTree("SweightsTree", "S weights tree");
  TTree *trout = tr -> CloneTree();

  Float_t float_N_sig_sw;
  Float_t float_N_bkg_sw;
  auto br_N_sig_sw = trout -> Branch("nsig_sw",&float_N_sig_sw, "nsig_sw/F");
  auto br_N_bkg_sw = trout -> Branch("nbkg_sw",&float_N_bkg_sw, "nbkg_sw/F");

  int nentries_trout = trout -> GetEntries();
  for (int i = 0; i <nentries_trout; i++)
    {

      tr -> GetEntry(i);
      
      float_N_sig_sw = sDataPlot -> GetSWeight(i, "nsig_sw");
      float_N_bkg_sw = sDataPlot -> GetSWeight(i, "nbkg_sw");


      br_N_sig_sw -> Fill();
      br_N_bkg_sw -> Fill();
    }

  newf -> Write();
  return newfilename;

}


