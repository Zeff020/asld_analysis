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
  B_corr_mass_weighted -> Sumw2();
  
  // Getting the SWeights
  TFile *fsweights = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/Data2016_Strip28r1_MagUp1sweights.root");
  TTree *trsweights = (TTree*)fsweights->Get("DecayTree");
   
  trsweights -> SetBranchAddress("nsig_sw",&nsig_sw);
  int counter = 0;
  for (int i = 0; i<nentries; i++){
    
    tr -> GetEntry(i);
    trsweights -> GetEntry(i);
    if (nsig_sw <= 0.0){
      nsig_sw = 0.001;
      counter++;
    }
    B_corr_mass_weighted -> Fill(B_CM,nsig_sw);
    
  }
  
    //----------//---------------- Getting the MC Bd dataset and extracting a roodatahist and PDF----------------------------------------//
   
   // OPTION 1
   TFile *f1 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/DTT_2015_MC_Up_Bd2Dpmunu_118740421b2DpMuXBcm.root");
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
  TFile *fsweights2 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/Data2015_Strip24r1_MagUp1sweights.root");
  TTree *trsweights2 = (TTree*)fsweights2->Get("DecayTree");
   
  trsweights2 -> SetBranchAddress("nsig_sw",&nsig_sw2);
  int counter2 = 0;
  for (int k = 0; k<nentries2; k++){
    
    tr2 -> GetEntry(k);
    trsweights2 -> GetEntry(k);
    if (nsig_sw2 <= 0.0){
      nsig_sw2 = 0.1;
      counter2++;
    }
    B_corr_mass_weighted2 -> Fill(B_CM2,nsig_sw2);
    
  }

  //----------------------------Getting the MC Bu dataset and extracting a roodatahist and PDF-----------------------------------------//
   TFile *f3 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/MC2015Bu_Up1b2DpMuXBcm.root");
   TTree *tr3 = (TTree*)f3->Get("DecayTree");
   
   
   Float_t B_CM3;
   Int_t nentries3 = 0; //Providing initial value
   nentries3 = tr3 -> GetEntries();
   tr3 -> SetBranchAddress("B_CM",&B_CM3);
   
   TH1D * Bu_mc_mass = new TH1D("Bu_mc_mass", "Bu monte carlo", 100, 2000.0, 10000.0);
   //Bu_mc_mass -> Sumw2();

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
   //combo1 -> Sumw2();
   
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
   //combo4 -> Sumw2();
   
   for (int z = 0; z<nentries4; z++){
    
     tr4 -> GetEntry(z);
     combo4 -> Fill(B_CM4);
   
   }

   

   //----------------------------------------Getting the histogram with D mass background----------------------------------------------//
   TFile *f5 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/Data2015_Strip24r1_MagUp1b2DpMuXBcmDMbkg.root");
   TH1F *h2Bmass = (TH1F*)f5->Get("h2Bmass");
   h2Bmass -> Rebin(5); //Doing this for now with 2015 and 2016 nondecreased datasets since the binning on the original hist was 250!
   //----------------------------------------------------------------------------------------------------------------------------------//
   
   //--------------------------Getting the same sign data and extracting a roodatahist and PDF-----------------------------------------//
   
   TFile *f32 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/Data2015_Strip24r1_MagUp1b2DpMuX_SSBcm.root"); 
   TTree *tr32 = (TTree*)f3->Get("DecayTree");
   
   Float_t B_CM32;
   Int_t nentries32 = 0; //Providing initial value
   nentries32 = tr32 -> GetEntries();
   tr32 -> SetBranchAddress("B_CM",&B_CM32);
   
   TH1D * Bss_mc_mass = new TH1D("Bss_mc_mass", "Bss_mc_mass", 100, 2000.0, 7000.0);
   Bss_mc_mass -> Sumw2();

   for (int x = 0; x<nentries32; x++){
    
     tr32 -> GetEntry(x);
     Bss_mc_mass -> Fill(B_CM32);
    
   }
   

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
   RooRealVar* y = new RooRealVar("y", "y", 2300, 7000);
   
   RooDataHist* Bss_mc= new RooDataHist("Bss_mc", "dataset with y", *y, Bss_mc_mass);
   RooHistPdf* SSPdf_C=new RooHistPdf("SSPdf_C", "SSPdf_C", RooArgSet(*y), *Bss_mc, 0);

   RooDataHist* combo4h = new RooDataHist("combo4h", "combo4h", *y, combo4);
   RooHistPdf* combo4pdf =new RooHistPdf("combo4pdf", "combo4pdf", RooArgSet(*y), *combo4h, 0);

   RooDataHist* combo1h = new RooDataHist("combo1h", "combo1h", *y, combo1);
   RooHistPdf* combo1pdf =new RooHistPdf("combo1pdf", "combo1pdf", RooArgSet(*y), *combo1h, 0);

   RooDataHist* h2BmassC = new RooDataHist("h2Bmass","D mass sideband",*y, h2Bmass);
   RooHistPdf* h2BmassC_C = new RooHistPdf("h2BmassC_C", "D mass sideband", RooArgSet(*y), *h2BmassC, 0);

   RooDataHist* dataC = new RooDataHist("dataC", "dataset with y", *y, B_corr_mass_weighted2); // Corrected B mass weighted
   RooHistPdf* dataC_C = new RooHistPdf("Data", "Data", RooArgSet(*y), *dataC, 0);

   RooDataHist* Bd_mc= new RooDataHist("Bd_mc", "dataset with y", *y, Bd_mc_mass);
   RooHistPdf* BdPdf_C= new RooHistPdf("BdPdf_C", "BdPdf_C", RooArgSet(*y), *Bd_mc, 0);

   RooDataHist* Bu_mc= new RooDataHist("Bu_mc", "dataset with y", *y, Bu_mc_mass);
   RooHistPdf* BuPdf_C= new RooHistPdf("BuPdf_C", "BuPdf_C", RooArgSet(*y), *Bu_mc, 0);

   //-----------------------------------------------------------------------------------------------------------------------------------//
   
   
   // Plotting the PDF's
   C -> cd();
   /*
   RooPlot* Cmesframe = y->frame(Title("B corrected mass fit components;MeV/c^2; Events (normalized)"  ));
   
   dataC_C -> plotOn(Cmesframe, Name("Data") ,LineColor(1));
   BdPdf_C -> plotOn(Cmesframe, Name("Bd"),LineColor(2));
   BuPdf_C -> plotOn(Cmesframe, Name("Bu"),LineColor(3));
   //combo4pdf -> plotOn(Cmesframe, Name("Combo 4"),LineColor(7));
   combo1pdf -> plotOn(Cmesframe, Name("Combo 1"),LineColor(6));
   h2BmassC_C -> plotOn(Cmesframe, Name("D mass sideband"), LineColor(5));
   Cmesframe->Draw();
   
   TLegend *leg1 = new TLegend(0.65,0.73,0.86,0.87);
   leg1->SetFillColor(kWhite);
   leg1->SetLineColor(kWhite);
   leg1->AddEntry(Cmesframe->findObject("Data"),"Data");
   leg1->AddEntry(Cmesframe->findObject("Bd"),"Signal");
   leg1->AddEntry(Cmesframe->findObject("D mass sideband"),"SB bkg.");
   leg1->AddEntry(Cmesframe->findObject("Bu"),"B^{+} bkg.");
   leg1->AddEntry(Cmesframe->findObject("Combo 1"),"feed-down");
   //leg1->AddEntry(Cmesframe->findObject("Combo 4"),"Combo 4");
   leg1->Draw();
   
   
   */
   //-------------------------------------------------------The fit model--------------------------------------------------------------//
   
   /*
   // Treating every PDF equal with the number of candidates
   RooRealVar *nsig = new RooRealVar("nsig","Number Bd",10.E5,0.0,40.E5);
   RooRealVar *nBu = new RooRealVar("nBu","Number Bu",10.E5,0.0,40.E5);
   RooRealVar *nBkg = new RooRealVar("nBkg","Number Bkg",10.E5,0.0,40.E5);
   RooRealVar *ncombo1 = new RooRealVar("ncombo1","Number combo1",10.E5,0.0,40.E5);
   */
   RooRealVar *ncombo4 = new RooRealVar("ncombo4","Number combo4",10.E5,0.0,40.E5);
   
   
   RooRealVar *nBkg = new RooRealVar("nBkg","Number Bkg",10.E5,0.0,40.E5);
   RooRealVar *nsig = new RooRealVar("nsig","Number Bd",10.E5,0.0,40.E5);
   RooRealVar *nBuAndComb1 = new RooRealVar("nBuAndComb1","Number of combo 1 and Bu",10.E5,0.0,40.E5);
   RooRealVar *frac = new RooRealVar("frac","fraction Bu and Comb 1",0.6, 0.6, 0.6);

   RooAddPdf* BuAndComb1_C = new RooAddPdf("BuAndComb1_C","BuAndComb1_C",RooArgList(*BuPdf_C,*combo1pdf),RooArgList(*frac));

   RooAddPdf* model_C= new RooAddPdf("model_C","model_C",RooArgList(*BdPdf_C, *BuAndComb1_C/*, *h2BmassC_C*/),RooArgList(*nsig,*nBuAndComb1/*,*nBkg*/));
   
   model_C->fitTo(*dataC, SumW2Error(kFALSE), Minimizer("Minuit2","migrad"), PrintLevel(1));
   //-----------------------------------------------Plotting after fit results---------------------------------------------------------//
   
   C -> cd();
   RooPlot* Cmesframe = y->frame(Title("B corrected mass fit;"));
   
   dataC -> plotOn(Cmesframe, Name("Data")); 
   model_C->plotOn(Cmesframe,Name("Model_C"),LineColor(4)); 
   
   model_C->plotOn(Cmesframe,Components("BdPdf_C"),LineStyle(kDashed),Name("BdPdf_C"),LineColor(2));   
   model_C->plotOn(Cmesframe,Components("BuPdf_C"),LineStyle(kDashed),Name("BuPdf_C"),LineColor(3));
   model_C->plotOn(Cmesframe,Components("h2BmassC_C"),LineStyle(kDashed),Name("h2BmassC_C"),LineColor(5));
   //model_C->plotOn(Cmesframe,Components("BuAndComb1_C"),LineStyle(kDashed),LineColor(5));
   model_C->plotOn(Cmesframe,Components("combo1pdf"),LineStyle(kDashed),Name("combo1pdf"),LineColor(6));
   //model_C->plotOn(Cmesframe,Components("combo4pdf"),LineStyle(kDashed),LineColor(7));
   //model_C->plotOn(Cmesframe,Components("SSPdf_C"),LineStyle(kDashed),Name("bkg"),LineColor(7));

   // Calculating absolute value of Bu candidates
   auto fracval = frac -> getVal();
   auto nBuAndComb1val = nBuAndComb1 -> getVal();
   auto nBufl = fracval * nBuAndComb1val;
   std::cout << nBufl << "Number of B+ components"<< endl;
   auto nComb1 = (1-fracval) * nBuAndComb1val;
   std::cout << nComb1 << "Number of combinatorial components" << endl;
   RooRealVar* nBu = new RooRealVar("nBu","Number Bu", nBufl, nBufl, nBufl);
   
   //model_C->paramOn(Cmesframe, Parameters(RooArgList(*nBkg, *nsig, *nBuAndComb1, *frac,*ncombo4 )), Layout(.64, .89, .8));
   
   
   RooPlot* pullframe = y->frame(Title(";MeV/c^2"));
   RooHist* hpull = Cmesframe->pullHist("Data", "Model_C");
   pullframe -> addPlotable(hpull,"P");

   C->Divide(1,2) ;
   C->cd(1) ; gPad->SetLeftMargin(0.15) ;/*gPad->SetLogy()*/; Cmesframe->GetYaxis()->SetTitleOffset(1.6) ; Cmesframe->Draw() ;
   gPad -> SetPad(1.0,0.25,0.0,1.0);
   gPad->SetBottomMargin(0.0);
   // Making the legend
   TLegend *leg1 = new TLegend(0.65,0.73,0.86,0.87);
   leg1->SetFillColor(kWhite);
   leg1->SetLineColor(kWhite);
   leg1->AddEntry(Cmesframe->findObject("Data"),"Data (465 440)");
   leg1->AddEntry(Cmesframe->findObject("BdPdf_C"),"Signal (412 863 #pm 1 074)");
   //leg1->AddEntry(Cmesframe->findObject("h2BmassC_C"),"SB bkg. (1 567 792 #pm 4 331)");
   leg1->AddEntry(Cmesframe->findObject("BuPdf_C"),"B^{+} bkg. (31 546 #pm 535)");
   leg1->AddEntry(Cmesframe->findObject("combo1pdf"),"feed-down (21 031 #pm 357)");
   leg1->Draw();
   

   C->cd(2) ; gPad->SetLeftMargin(0.15) ; pullframe->GetYaxis()->SetTitleOffset(1.6) ; pullframe->Draw();
   gPad -> SetTopMargin(0.0);
   gPad -> SetBottomMargin(0.2);
   gPad -> SetPad(0.0,0.0,1.0,0.25);
   pullframe -> GetXaxis() -> SetLabelSize(0.08);
   pullframe -> GetXaxis() -> SetTitleSize(0.08);
   pullframe -> GetYaxis() -> SetLabelSize(0.08);
   cout << counter<< endl;
   cout << counter2;
   return 0;
   
}
