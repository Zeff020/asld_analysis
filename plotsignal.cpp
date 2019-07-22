#include <TFile.h>                                                                                                                        
#include <TTree.h>                                                                                                                        
#include <TROOT.h>

#include "Inclusion.h"

using namespace std;

int plotsignal(){

//-------------------------- Getting the 2016 dataset and extracting a roodatahist and PDF----------------------------------------//
/*
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

  for (int i = 0; i<nentries; i++){
    
    tr -> GetEntry(i);
    trsweights -> GetEntry(i);
    B_corr_mass_weighted -> Fill(B_CM,nsig_sw);
    
  }
*/
    //-------------------------- Getting the MC Bd dataset and extracting a roodatahist and PDF----------------------------------------//
  
   // OPTION 1
   TFile *f1 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/DTT_2015_MC_Up_Bu2Dststmunu_DpCocktail_128740501b2DpMuXBcm.root");
   TTree *tr1 = (TTree*)f1->Get("DecayTree");
   

   
   float B_CM1;
   Int_t nentries1 = 0; //Providing initial value
   nentries1 = tr1 -> GetEntries();
   tr1 -> SetBranchAddress("B_CM",&B_CM1);

   TH1D * Bd_mc_mass = new TH1D("Bd_mc_mass", "DTT_2015_MC_Up_Bu2Dststmunu_DpCocktail_12874050", 100, 2000.0, 10000.0);
   Bd_mc_mass -> Sumw2();
   

   for (int j = 0; j<nentries1; j++){
    
    tr1 -> GetEntry(j);
    Bd_mc_mass -> Fill(B_CM1);
    
   }

//-------------------------- Getting the 2015 dataset and extracting a roodatahist and PDF----------------------------------------//

TFile *f2 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/DTT_2015_MC_Up_Bd2Dstmunu_128750311b2DpMuXBcm.root");
  TTree *tr2 = (TTree*)f2->Get("DecayTree");


  Float_t nsig_sw2;
  Float_t B_CM2;
  
  Int_t nentries2 = 0; //Providing initial value
  nentries2 = tr2 -> GetEntries();

  tr2 -> SetBranchAddress("B_CM",&B_CM2);
  
  TH1D * B_corr_mass_weighted2 = new TH1D("B_mass_2015", "DTT_2015_MC_Up_Bd2Dstmunu_12875031", 100, 2000.0, 10000.0);
  


  for (int k = 0; k<nentries2; k++){
    
    tr2 -> GetEntry(k);
    B_corr_mass_weighted2 -> Fill(B_CM2);
    
  }

 //--------------------------Getting the MC Bu dataset and extracting a roodatahist and PDF-----------------------------------------//
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

   auto C = new TCanvas();
   gStyle->SetPalette(kRainBow);
   Bd_mc_mass -> SetLineColor(kRed);
   B_corr_mass_weighted2 -> SetLineStyle(kDashed);
   Bd_mc_mass-> DrawNormalized("HIST");
   B_corr_mass_weighted2 -> SetLineColor(kGreen);
   
   B_corr_mass_weighted2 -> DrawNormalized("SAME HIST");
   Bu_mc_mass -> SetLineStyle(kDashed);
   Bu_mc_mass -> SetLineColor(kBlue);
   Bu_mc_mass -> DrawNormalized("SAME HIST");
   gPad -> BuildLegend();


  return 0;
}
