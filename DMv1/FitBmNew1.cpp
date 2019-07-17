#include <TFile.h>                                                                                                                        
#include <TTree.h>                                                                                                                        
#include <TROOT.h>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooDataHist.h>
#include <RooGaussian.h>
#include <RooHistPdf.h>
#include <RooPlot.h>
#include <RooHistPdf.h>

#include "Inclusion.h"

using namespace std;

int FitBmNew1(){

//-------------------------- Getting the 2016 dataset and extracting a roodatahist and PDF----------------------------------------//
  TFile *f = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/Data2016_Strip28r1_MagUp1b2DpMuXBcm.root");
  TTree *tr = (TTree*)f->Get("DecayTree");


  Float_t nsig_sw;
  Float_t B_CM;
  
  Int_t nentries = 0; //Providing initial value
  nentries = tr -> GetEntries();

  tr -> SetBranchAddress("B_CM",&B_CM);
  
  TH1D * B_corr_mass_weighted = new TH1D("B_mass_2016", "B Mass 2016 dataset", 100, 2000.0, 10000.0);
  //B_corr_mass_weighted -> Sumw2();
  
  // Getting the SWeights
  //TFile *fsweights = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/Data2016_Strip28r1_MagUp1sweights.root");
  //TTree *trsweights = (TTree*)fsweights->Get("DecayTree");
   
  //trsweights -> SetBranchAddress("nsig_sw",&nsig_sw);

  for (int i = 0; i<nentries; i++){
    
    tr -> GetEntry(i);
    //trsweights -> GetEntry(i);
    B_corr_mass_weighted -> Fill(B_CM/*,nsig_sw*/);
    
  }
  
    //-------------------------- Getting the MC Bd dataset and extracting a roodatahist and PDF----------------------------------------//
   
   // OPTION 1
   TFile *f1 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/MC2015Bd_Up1b2DpMuXBcm.root");
   TTree *tr1 = (TTree*)f1->Get("DecayTree");
   

   
   float B_CM1;
   Int_t nentries1 = 0; //Providing initial value
   nentries1 = tr1 -> GetEntries();
   tr1 -> SetBranchAddress("B_CM",&B_CM1);

   TH1D * Bd_mc_mass = new TH1D("Bd_mc_mass", "Bd monte carlo", 100, 2000.0, 10000.0);
   //Bd_mc_mass -> Sumw2();
   

   for (int j = 0; j<nentries1; j++){
    
    tr1 -> GetEntry(j);
    Bd_mc_mass -> Fill(B_CM1);
    
   }

   //-------------------------- Getting the 2015 dataset and extracting a roodatahist and PDF----------------------------------------//

   TFile *f2 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/Data2015_Strip24r1_MagUp1b2DpMuXBcm.root");
  TTree *tr2 = (TTree*)f2->Get("DecayTree");


  Float_t nsig_sw2;
  Float_t B_CM2;
  
  Int_t nentries2 = 0; //Providing initial value
  nentries2 = tr2 -> GetEntries();

  tr2 -> SetBranchAddress("B_CM",&B_CM2);
  
  TH1D * B_corr_mass_weighted2 = new TH1D("B_mass_2015", "B mass 2015 dataset", 100, 2000.0, 10000.0);
  //B_corr_mass_weighted2 -> Sumw2();
  
  // Getting the SWeights
  //TFile *fsweights2 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/Data2015_Strip24r1_MagUp1sweights.root");
  //TTree *trsweights2 = (TTree*)fsweights2->Get("DecayTree");
   
  //trsweights2 -> SetBranchAddress("nsig_sw",&nsig_sw2);

  for (int k = 0; k<nentries2; k++){
    
    tr2 -> GetEntry(k);
    //trsweights2 -> GetEntry(k);
    B_corr_mass_weighted2 -> Fill(B_CM2/*,nsig_sw2*/);
    
  }

  //----------------------------Getting the MC Bu dataset and extracting a roodatahist and PDF-----------------------------------------//
   TFile *f3 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/MC2015Bu_Up1b2DpMuXBcm.root");
   TTree *tr3 = (TTree*)f3->Get("DecayTree");
   
   
   Float_t B_CM3;
   Int_t nentries3 = 0; //Providing initial value
   nentries3 = tr3 -> GetEntries();
   tr3 -> SetBranchAddress("B_CM",&B_CM3);
   
   TH1D * Bu_mc_mass = new TH1D("Bu_mc_mass", "Bu monte carlo", 100, 2000.0, 10000.0);
   Bu_mc_mass -> Sumw2();

   for (int m = 0; m<nentries3; m++){
    
     tr3 -> GetEntry(m);
     Bu_mc_mass -> Fill(B_CM3);
    
   }

   //---------------------------------Getting the MC sample of the biggest physics background-------------------------------------------//
   
   TFile *f31 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataPBkg/combo1.root");
   TTree *tr31 = (TTree*)f31->Get("DecayTree");

   Float_t B_CM31;
   Int_t nentries31 = 0; //Providing initial value
   nentries31 = tr31 -> GetEntries();
   tr31 -> SetBranchAddress("B_CM",&B_CM31);
   
   TH1D * combo1 = new TH1D("combo1", "combo1", 100, 2000.0, 10000.0);
   combo1 -> Sumw2();
   
   for (int l = 0; l<nentries31; l++){
    
     tr31 -> GetEntry(l);
     combo1 -> Fill(B_CM31);
   
   }
   

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

   //----------------------------------------Getting the histogram with D mass background----------------------------------------------//
   TFile *f5 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/Data2015_Strip24r1_MagUp1b2DpMuXBcmDMbkg.root");
   TH1F *h2Bmass = (TH1F*)f5->Get("h2Bmass");
   h2Bmass -> Rebin(5); //Doing this for now with 2015 and 2016 nondecreased datasets since the binning on the original hist was 250!
   //----------------------------------------------------------------------------------------------------------------------------------//
   
   auto C = new TCanvas();
   
   // Plotting the histograms!!
   /*
   gStyle->SetPalette(kRainBow);
   Bd_mc_mass -> SetLineColor(kRed);
   Bd_mc_mass-> DrawNormalized("HIST");
   B_corr_mass_weighted -> SetLineColor(kGreen);
   B_corr_mass_weighted -> DrawNormalized("SAME HIST");
   Bu_mc_mass -> SetLineColor(kBlue);
   Bu_mc_mass -> DrawNormalized("SAME HIST");
   combo4 -> SetLineColor(kBlack);
   combo4 -> DrawNormalized("SAME HIST");
   combo1 -> SetLineColor(kYellow);
   combo1 -> DrawNormalized("SAME HIST");
   h2Bmass -> SetLineColor(kOrange);
   h2Bmass -> DrawNormalized("SAME HIST");
  
   gPad -> BuildLegend();
   */
   //----------------------------------------------------Do all the roofit stuff--------------------------------------------------------//
   RooRealVar* y = new RooRealVar("y", "y", 2300, 10000);
   
   RooDataHist* combo4h = new RooDataHist("combo4h", "combo4h", *y, combo4);
   RooHistPdf* combo4pdf =new RooHistPdf("combo4pdf", "combo4pdf", RooArgSet(*y), *combo4h, 0);

   RooDataHist* combo1h = new RooDataHist("combo1h", "combo1h", *y, combo1);
   RooHistPdf* combo1pdf =new RooHistPdf("combo1pdf", "combo1pdf", RooArgSet(*y), *combo1h, 0);

   RooDataHist* h2BmassC = new RooDataHist("h2Bmass","D mass sideband",*y, h2Bmass);
   RooHistPdf* h2BmassC_C = new RooHistPdf("h2BmassC_C", "D mass sideband", RooArgSet(*y), *h2BmassC, 0);

   RooDataHist* dataC = new RooDataHist("dataC", "dataset with y", *y, B_corr_mass_weighted); // Corrected B mass weighted
   RooHistPdf* dataC_C = new RooHistPdf("Data", "Data", RooArgSet(*y), *dataC, 0);

   RooDataHist* Bd_mc= new RooDataHist("Bd_mc", "dataset with y", *y, Bd_mc_mass);
   RooHistPdf* BdPdf_C= new RooHistPdf("BdPdf_C", "BdPdf_C", RooArgSet(*y), *Bd_mc, 0);

   RooDataHist* Bu_mc= new RooDataHist("Bu_mc", "dataset with y", *y, Bu_mc_mass);
   RooHistPdf* BuPdf_C= new RooHistPdf("BuPdf_C", "BuPdf_C", RooArgSet(*y), *Bu_mc, 0);

   //-----------------------------------------------------------------------------------------------------------------------------------//
   
   /*
   // Plotting the PDF's
   C -> cd();
   
   RooPlot* Cmesframe = y->frame(Title("B Corrected Mass;MeV/c^2"));
   
   dataC_C -> plotOn(Cmesframe, Name("Data") ,LineColor(1));
   BdPdf_C -> plotOn(Cmesframe, Name("Bd"),LineColor(2));
   BuPdf_C -> plotOn(Cmesframe, Name("Bu"),LineColor(3));
   combo4pdf -> plotOn(Cmesframe, Name("Combo 4"),LineColor(7));
   combo1pdf -> plotOn(Cmesframe, Name("Combo 1"),LineColor(6));
   h2BmassC_C -> plotOn(Cmesframe, Name("D mass sideband"), LineColor(5));
   Cmesframe->Draw();
   
   TLegend *leg1 = new TLegend(0.65,0.73,0.86,0.87);
   leg1->SetFillColor(kWhite);
   leg1->SetLineColor(kWhite);
   leg1->AddEntry(Cmesframe->findObject("Data"),"Data");
   leg1->AddEntry(Cmesframe->findObject("Bd"),"B down");
   leg1->AddEntry(Cmesframe->findObject("Bu"),"B up");
   leg1->AddEntry(Cmesframe->findObject("Combo 1"),"Combo 1");
   leg1->AddEntry(Cmesframe->findObject("Combo 4"),"Combo 4");
   leg1->AddEntry(Cmesframe->findObject("D mass sideband"),"Sideband D data");
   leg1->Draw();
   */
   //-------------------------------------------------------The fit model--------------------------------------------------------------//
   
   RooRealVar *nsig = new RooRealVar("nsig","Number Bd",10.E5,0.0,40.E5);
   RooRealVar *nBu = new RooRealVar("nBu","Number Bu",10.E5,0.0,40.E5);
   RooRealVar *nBkg = new RooRealVar("nBkg","Number Bkg",10.E5,0.0,40.E5);
   RooRealVar *ncombo1 = new RooRealVar("ncombo1","Number combo1",10.E5,0.0,40.E5);
   RooRealVar *ncombo4 = new RooRealVar("ncombo4","Number combo4",10.E5,0.0,40.E5);
   
   RooAddPdf* peaking_C= new RooAddPdf("peaking_C","peaking_C",RooArgList(*BdPdf_C, *BuPdf_C,*h2BmassC_C, /**combo1pdf,*/ *combo4pdf),RooArgList(*nsig,*nBu,*nBkg,/**ncombo1,*/*ncombo4  ));
   
   peaking_C->fitTo(*dataC, SumW2Error(kTRUE), PrintLevel(1));
   //-----------------------------------------------Plotting after fit results---------------------------------------------------------//
   
   C -> cd();
   RooPlot* Cmesframe = y->frame(Title("B Corrected Mass;MeV/c^2"));
   
   dataC -> plotOn(Cmesframe, Name("Data")); 
   peaking_C->plotOn(Cmesframe,Name("Peaking Curve"),LineColor(4)); 
   
   peaking_C->plotOn(Cmesframe,Components("BdPdf_C"),LineStyle(kDashed),LineColor(2));   
   peaking_C->plotOn(Cmesframe,Components("BuPdf_C"),LineStyle(kDashed),LineColor(3));
   peaking_C->plotOn(Cmesframe,Components("h2BmassC_C"),LineStyle(kDashed),LineColor(5));
   peaking_C->plotOn(Cmesframe,Components("combo1pdf"),LineStyle(kDashed),LineColor(6));
   peaking_C->plotOn(Cmesframe,Components("combo4pdf"),LineStyle(kDashed),LineColor(7));
   peaking_C->paramOn(Cmesframe, Parameters(RooArgList(*nsig,*nBu,*nBkg,*ncombo1, *ncombo4)), Layout(.64, .89, .8));
   
   
   RooPlot* pullframe = y->frame();
   RooHist* hpull = Cmesframe->pullHist("Data", "Peaking Curve");
   pullframe -> addPlotable(hpull,"P");

   C->Divide(2) ;
   C->cd(1) ; gPad->SetLeftMargin(0.15) ; Cmesframe->GetYaxis()->SetTitleOffset(1.6) ; Cmesframe->Draw() ;
   C->cd(2) ; gPad->SetLeftMargin(0.15) ; pullframe->GetYaxis()->SetTitleOffset(1.6) ; pullframe->Draw() ;

  return 0;
   
}
