#include <TFile.h>
#include <TTree.h>
#include <TROOT.h>


// All of the roofit stuff
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooDataHist.h>
#include <RooGaussian.h>
#include <RooHistPdf.h>
#include <RooPlot.h>
#include <RooHistPdf.h>
#include "Inclusion.h"

using namespace RooFit;
using namespace RooStats;

int FitBmNew(){
  
    //-------------------------- Getting the original dataset and extracting a weighted roodatahist-------------------------------------//


  TFile *f = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/Data2015_Strip24r1_MagUp1b2DpMuXBcm.root");
  TTree *tr = (TTree*)f->Get("DecayTree");

  Float_t nsig_sw;
  Float_t B_CM;
  
  Int_t nentries = 0; //Providing initial value
  nentries = tr -> GetEntries();

  tr -> SetBranchAddress("B_CM",&B_CM);
  
  TH1D * B_corr_mass_weighted = new TH1D("B_mass", "B_mass", 100, 2000.0, 10000.0);
  B_corr_mass_weighted -> Sumw2();
  
  // Getting the SWeights
  TFile *fsweights = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/Data2015_Strip24r1_MagUp1sweights.root");
  TTree *trsweights = (TTree*)fsweights->Get("DecayTree");
   
  trsweights -> SetBranchAddress("nsig_sw",&nsig_sw);

  for (int i = 0; i<nentries; i++){
    
    tr -> GetEntry(i);
    trsweights -> GetEntry(i);
    B_corr_mass_weighted -> Fill(B_CM,nsig_sw);
    
  }

   RooRealVar* y = new RooRealVar("y", "y", 2300, 10000);   
   RooDataHist* dataC = new RooDataHist("dataC", "dataset with y", *y, B_corr_mass_weighted); // Corrected B mass weighted
   /*
   tr->Delete();
   f->Close();
   //B_corr_mass_weighted -> Delete();
   f->Delete();
   
   trsweights->Delete();
   fsweights->Close();
   //B_corr_mass_weighted -> Delete();
   fsweights->Delete();
   */

   //-------------------------- Getting the MC Bd dataset and extracting a roodatahist and PDF----------------------------------------//
   
   // OPTION 1
   TFile *f1 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/MC2015Bd_Up1b2DpMuXBcm.root");
   TTree *tr1 = (TTree*)f1->Get("DecayTree");
   

   
   float B_CM1;
   Int_t nentries1 = 0; //Providing initial value
   nentries1 = tr1 -> GetEntries();
   tr1 -> SetBranchAddress("B_CM",&B_CM1);

   TH1D * Bd_mc_mass = new TH1D("Bd_mc_mass", "Bd_mc_mass", 100, 2000.0, 10000.0);
   Bd_mc_mass -> Sumw2();
   

   for (int j = 0; j<nentries1; j++){
    
    tr1 -> GetEntry(j);
    Bd_mc_mass -> Fill(B_CM1);
    
   }

   RooDataHist* Bd_mc= new RooDataHist("Bd_mc", "dataset with y", *y, Bd_mc_mass);
   RooHistPdf* BdPdf_C= new RooHistPdf("BdPdf_C", "BdPdf_C", RooArgSet(*y), *Bd_mc, 0);
   /*
   tr1->Delete();
   f1->Close();
   //Bd_mc_mass -> Delete();
   f1->Delete();
   */
   //--------------------------Getting the MC Bu dataset and extracting a roodatahist and PDF-----------------------------------------//
   TFile *f2 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/MC2015Bu_Up1b2DpMuXBcm.root");
   TTree *tr2 = (TTree*)f2->Get("DecayTree");
   
   
   Float_t B_CM2;
   Int_t nentries2 = 0; //Providing initial value
   nentries2 = tr2 -> GetEntries();
   tr2 -> SetBranchAddress("B_CM",&B_CM2);
   
   TH1D * Bu_mc_mass = new TH1D("Bu_mc_mass", "Bu_mc_mass", 100, 2000.0, 10000.0);
   Bu_mc_mass -> Sumw2();

   for (int k = 0; k<nentries2; k++){
    
     tr2 -> GetEntry(k);
     Bu_mc_mass -> Fill(B_CM2);
    
   }
   
   RooDataHist* Bu_mc= new RooDataHist("Bu_mc", "dataset with y", *y, Bu_mc_mass);
   RooHistPdf* BuPdf_C= new RooHistPdf("BuPdf_C", "BuPdf_C", RooArgSet(*y), *Bu_mc, 0);
   /*
   tr2->Delete();
   f2->Close();
   //Bu_mc_mass -> Delete();
   f2->Delete();
   */
   //---------------------------------Getting the MC sample of the biggest physics background-------------------------------------------//
   
   TFile *f3 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataPBkg/combo1.root");
   TTree *tr3 = (TTree*)f3->Get("DecayTree");

   Float_t B_CM3;
   Int_t nentries3 = 0; //Providing initial value
   nentries3 = tr3 -> GetEntries();
   tr3 -> SetBranchAddress("B_CM",&B_CM3);
   
   TH1D * combo1 = new TH1D("combo1", "combo1", 100, 2000.0, 10000.0);
   combo1 -> Sumw2();
   
   for (int l = 0; l<nentries3; l++){
    
     tr3 -> GetEntry(l);
     combo1 -> Fill(B_CM3);
   
   }
   
   RooDataHist* combo1h = new RooDataHist("combo1h", "combo1h", *y, combo1);
   RooHistPdf* combo1pdf =new RooHistPdf("combo1pdf", "combo1pdf", RooArgSet(*y), *combo1h, 0);
   

   //---------------------------------Getting the MC sample of the second biggest physics background------------------------------------//
   
    TFile *f4 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataPBkg/combo4.root");
   TTree *tr4 = (TTree*)f4->Get("DecayTree");

   Float_t B_CM4;
   Int_t nentries4 = 0; //Providing initial value
   nentries4 = tr4 -> GetEntries();
   tr4 -> SetBranchAddress("B_CM",&B_CM4);
   
   TH1D * combo4 = new TH1D("combo4", "combo4", 100, 2000.0, 10000.0);
   combo4 -> Sumw2();
   
   for (int z = 0; z<nentries4; z++){
    
     tr4 -> GetEntry(z);
     combo4 -> Fill(B_CM4);
   
   }
   
   RooDataHist* combo4h = new RooDataHist("combo4h", "combo4h", *y, combo4);
   RooHistPdf* combo4pdf =new RooHistPdf("combo4pdf", "combo4pdf", RooArgSet(*y), *combo4h, 0);

   /*
   TFile * histograms = new TFile("./histograms.root", "RECREATE");
   TCanvas * c_histograms = new TCanvas("", "", 0,0, 650, 500);
   B_corr_mass_weighted->Scale(1.0/B_corr_mass_weighted->Integral("width"));
   Bd_mc_mass->Scale(1.0/Bd_mc_mass->Integral("width"));
   Bu_mc_mass->Scale(1.0/Bu_mc_mass->Integral("width"));
   c_histograms->cd();
   B_corr_mass_weighted->Draw();
   Bd_mc_mass->SetLineColor(kRed);
   Bd_mc_mass->Draw("same");
   Bu_mc_mass->SetLineColor(kBlue);
   Bu_mc_mass->Draw("same");
   histograms->cd();
   c_histograms->Write();
   Bd_mc_mass->Write();
   Bu_mc_mass->Write();
   B_corr_mass_weighted->Write();
   */
   
   //---------------------------------------------------------Fitting-------------------------------------------------------------------//
   /* Complicated model
   RooRealVar *nBu = new RooRealVar("nBu", "nBu",20.E5, 0., 10.E6);
    RooRealVar *nc4 = new RooRealVar("nc4", "nc4",20.E5, 0., 10.E6);
   RooRealVar *nsig =  new RooRealVar("nsig", "nsig",20.E5, 0., 10.E6); 	

   RooRealVar *FracCombo1Bu = new RooRealVar("FracCombo1Bu","FracCombo1Bu",0.1,0.05,0.15);
   RooAddPdf* Combo1AndBuPdf = new RooAddPdf("Combo1AndBuPdf","Combo1AndBuPdf",RooArgList(*combo1pdf, *BuPdf_C),RooArgList(*FracCombo1Bu)); // Adding combo 1 and the Bu pdf together with calculated ratios since their shapes are very similar

   RooAddPdf* peaking_C= new RooAddPdf("peaking_C","peaking_C",RooArgList(*BdPdf_C, *Combo1AndBuPdf, *combo4pdf),RooArgList(*nsig,*nBu,*nc4));
   */
   
   // Simple model (only Bu and Bd)
    RooRealVar *nBu = new RooRealVar("nBu", "nBu",3.E4, 3.E4, 3.E4);
   RooRealVar *nsig =  new RooRealVar("nsig", "nsig",20.E5, 0., 10.E6); 
   
   RooAddPdf* peaking_C= new RooAddPdf("peaking_C","peaking_C",RooArgList(*BdPdf_C, *BuPdf_C),RooArgList(*nsig,*nBu));
   
   peaking_C->fitTo(*dataC, SumW2Error(kTRUE), PrintLevel(1));
   
   //---------------------------------------------------------Plotting------------------------------------------------------------------//

  
   
   TCanvas* c_Cmass_fit = new TCanvas("c_Cmass_fit", "c_Cmass_fit", 0, 650, 650, 550);
   c_Cmass_fit -> cd();
   RooPlot* Cmesframe = y->frame(Title("B Corrected Mass;MeV/c^2"));

   dataC -> plotOn(Cmesframe, Name("Data")); 
   peaking_C->plotOn(Cmesframe,Name("Peaking Curve"),LineColor(4)); 
     
   peaking_C->plotOn(Cmesframe,Components("BdPdf_C"),LineStyle(kDashed),LineColor(2));   
   //peaking_C->plotOn(Cmesframe,Components("Combo1AndBuPdf"),LineStyle(kDashed),LineColor(3)); 
   peaking_C->plotOn(Cmesframe,Components("BuPdf_C"),LineStyle(kDashed),LineColor(3));     


   RooHist* hpull = Cmesframe->pullHist("Data","Peaking Curve") ;
     RooPlot* pull_frame = y -> frame(Title("Pull Distribution")) ;
     pull_frame->addPlotable(hpull,"P");
     peaking_C->paramOn(Cmesframe, Parameters(RooArgList(*nBu, *nsig)), Layout(.64, .89, .8));
     //c_Cmass_fit -> GetPad(1) -> SetLogy();
     c_Cmass_fit->Divide(2) ;
     c_Cmass_fit->cd(1) ;gPad -> SetLogy(); gPad->SetLeftMargin(0.15) ; Cmesframe->GetYaxis()->SetTitleOffset(1.6) ; Cmesframe->Draw() ;
     c_Cmass_fit->cd(2) ; gPad->SetLeftMargin(0.15) ; pull_frame->GetYaxis()->SetTitleOffset(1.6) ; pull_frame->Draw() ;
     
  return 0;

}
