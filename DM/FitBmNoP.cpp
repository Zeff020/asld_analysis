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

void FitBmNoP(){


  //-------------------------- Getting the original dataset and extracting a weighted roodatahist-------------------------------------//
  TFile f("../../data/Data2016_Strip28r1_MagUpsmall300withcutssweightsbc.root");
  TTree *tr = (TTree*)f.Get("DecayTree");
  
  Float_t nsig_sw;
  Float_t B_CM;
  
  Int_t nentries = tr -> GetEntries();

  tr ->SetBranchAddress("nsig_sw",&nsig_sw);
  tr ->SetBranchAddress("B_CM",&B_CM);
  
  TH1D * B_corr_mass_weighted = new TH1D("B_mass", "B_mass", 250, 2000.0, 10000.0);
  B_corr_mass_weighted -> Sumw2();

  
  for (int i = 0; i<nentries; i++){
    
    tr ->GetEntry(i);
    B_corr_mass_weighted -> Fill(B_CM,nsig_sw);
    
  }

   RooRealVar* y = new RooRealVar("y", "y", 2000, 7000);   
   RooDataHist dataC("dataC", "dataset with y", *y, B_corr_mass_weighted); // Corrected B mass weighted
   
   f.Close();
   //B_corr_mass_weighted -> Delete();
   //tr->Delete();
   //f->Delete();
   
   //-------------------------- Getting the MC Bd dataset and extracting a roodatahist and PDF----------------------------------------//
   
   // OPTION 1
   TFile f1("../../data/MC2015Bd_Upwithcutsbc.root");
   TTree *tr1 = (TTree*)f1.Get("DecayTree");
   

   
   float B_CM1;
   Int_t nentries1 = tr1 -> GetEntries();
   tr1 -> SetBranchAddress("B_CM",&B_CM1);

   TH1D * Bd_mc_mass = new TH1D("Bd_mc_mass", "Bd_mc_mass", 250, 2000.0, 7000.0);
   Bd_mc_mass -> Sumw2();
   

   for (int j = 0; j<nentries1; j++){
    
    tr1 -> GetEntry(j);
    Bd_mc_mass -> Fill(B_CM1);
    
   }

   RooDataHist Bd_mc("Bd_mc", "dataset with y", *y, Bd_mc_mass);
   RooHistPdf BdPdf_C("BdPdf_C", "BdPdf_C", RooArgSet(*y), Bd_mc, 0);
   
   f1.Close();
   //Bd_mc_mass -> Delete();
   //tr1->Delete();
   //f1->Delete();
   //--------------------------Getting the MC Bu dataset and extracting a roodatahist and PDF-----------------------------------------//
   TFile f2("../../data/MC2015Bu_Upwithcutsbc.root");
   TTree *tr2 = (TTree*)f2.Get("DecayTree");
   
   
   Float_t B_CM2;
   Int_t nentries2 = tr2 -> GetEntries();
   tr2 -> SetBranchAddress("B_CM",&B_CM2);
   
   TH1D * Bu_mc_mass = new TH1D("Bu_mc_mass", "Bu_mc_mass", 250, 2000.0, 7000.0);
   Bd_mc_mass -> Sumw2();

   for (int k = 0; k<nentries2; k++){
    
     tr2 -> GetEntry(k);
     Bu_mc_mass -> Fill(B_CM2);
    
   }
   
   RooDataHist Bu_mc("Bu_mc", "dataset with y", *y, Bu_mc_mass);
   RooHistPdf BuPdf_C("BuPdf_C", "BuPdf_C", RooArgSet(*y), Bu_mc, 0);
  
   f2.Close();
   //Bu_mc_mass -> Delete();
   //tr2->Delete();
   //f2->Delete();
   //--------------------------Getting the same sign data and extracting a roodatahist and PDF-----------------------------------------//
   TFile f3("../../data/Data2016_Strip28r1_MagUp_SSsmall100withcutsbc.root");
   TTree *tr3 = (TTree*)f3.Get("DecayTree");
   
   Float_t B_CM3;
   Int_t nentries3 = tr3 -> GetEntries();
   tr3 -> SetBranchAddress("B_CM",&B_CM3);
   
   TH1D * Bss_mc_mass = new TH1D("Bss_mc_mass", "Bss_mc_mass", 250, 2000.0, 7000.0);
   Bss_mc_mass -> Sumw2();

   for (int l = 0; l<nentries3; l++){
    
     tr3 -> GetEntry(l);
     Bss_mc_mass -> Fill(B_CM3);
    
   }
   
   RooDataHist Bss_mc("Bss_mc", "dataset with y", *y, Bss_mc_mass);
   RooHistPdf SSPdf_C("SSPdf_C", "SSPdf_C", RooArgSet(*y), Bss_mc, 0);
   
  
   f3.Close();
   //Bss_mc_mass -> Delete();
   //tr3->Delete();
   //f3->Delete();/
   //---------------------------------------------------------Fitting-------------------------------------------------------------------//
   
     RooRealVar frac("frac", "fraction", 0.1, 0.0, 1.0);    
     RooRealVar frac_comb("frac_comb", "fraction_comb", 0.1, 0.0, 1.0);   

     RooFormulaVar Cfrac("Cfrac","1-frac",RooArgSet(frac));   
     RooFormulaVar Cfrac_comb("Cfrac_comb","1-frac_comb",RooArgSet(frac_comb));

     
     RooAddPdf peaking_C("peaking_C","peaking_C",RooArgList(BuPdf_C,BdPdf_C),RooArgList(frac, Cfrac));   
     RooAddPdf model_C("model_C","model_C",RooArgList(SSPdf_C,peaking_C),RooArgList(frac_comb, Cfrac_comb));




   //---------------------------------------------------------Plotting------------------------------------------------------------------//
   
       model_C.fitTo(dataC);   
       TCanvas* c_Cmass_fit = new TCanvas("c_Cmass_fit", "c_Cmass_fit", 0, 650, 650, 550);
       c_Cmass_fit -> cd();
       RooPlot* Cmesframe = y->frame(Title("B Corrected Mass;MeV/c^2")) ;   
       dataC.plotOn(Cmesframe, Name("CmyHist1")); 
       model_C.plotOn(Cmesframe, Name("CmyCurve1"),LineColor(4)); 
       
       Cmesframe->Draw();
       model_C.plotOn(Cmesframe,Components("BdPdf_C"),LineColor(2));   
       model_C.plotOn(Cmesframe,Components("BuPdf_C"),LineColor(3));   
       model_C.plotOn(Cmesframe,Components("SSPdf_C"),LineColor(6));   
       Cmesframe -> Draw();
       
       /*
 
	 TCanvas* Bcm_canvas = new TCanvas("mD_Fit","mD Fit", 0, 650,650,550);
	 Bcm_canvas -> cd();

   
	 RooPlot* Bcm_frame = y -> frame(Title("B Corrected Mass"));

	 dataC.plotOn(Bcm_frame, Name("Data"));
	 Bd_mc.plotOn(Bcm1_frame, Name("Data1"), LineColor(4));
	 Bu_mc.plotOn(Bcm2_frame, Name("Data2"));
	 Bss_mc.plotOn(Bcm3_frame, Name("Data3"));
  
	 Bcm_canvas->Divide(4) ;
	 Bcm_canvas->cd(1) ; gPad->SetLeftMargin(0.15) ; Bcm_frame->GetYaxis()->SetTitleOffset(1.6) ; Bcm_frame->Draw() ;
	 Bcm_canvas->cd(2) ; gPad->SetLeftMargin(0.15) ; Bcm1_frame->GetYaxis()->SetTitleOffset(1.6) ; Bcm1_frame->Draw() ;
	 Bcm_canvas->cd(3) ; gPad->SetLeftMargin(0.15) ; Bcm2_frame->GetYaxis()->SetTitleOffset(1.6) ; Bcm2_frame->Draw() ;
	 Bcm_canvas->cd(4) ; gPad->SetLeftMargin(0.15) ; Bcm3_frame->GetYaxis()->SetTitleOffset(1.6) ; Bcm3_frame->Draw() ;

       */
}
