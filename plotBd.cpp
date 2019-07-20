#include <TFile.h>                                                                                                                        
#include <TTree.h>                                                                                                                        
#include <TROOT.h>

#include "Inclusion.h"

int plotBd(){
  TFile *f = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/DTT_2015_MC_Up_Bd2Dpmunu_118740421b2DpMuXBcm.root");
  TTree *tr = (TTree*)f->Get("DecayTree");

  Float_t B_CM;

  Int_t nentries = 0; //Providing initial value
  nentries = tr -> GetEntries();

  tr -> SetBranchAddress("B_CM",&B_CM);

  TH1D * B_corr_mass = new TH1D("B_mass_2016", "DTT_2015_MC_Up_Bd2Dpmunu_118740421", 100, 2000.0, 10000.0);
  
  for (int i = 0; i<nentries; i++){
    
    tr -> GetEntry(i);
    B_corr_mass -> Fill(B_CM);
    
  }


  TFile *f1 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/MC2015Bd_Up1b2DpMuXBcm.root");
   TTree *tr1 = (TTree*)f1->Get("DecayTree");
   

   
   float B_CM1;
   Int_t nentries1 = 0; //Providing initial value
   nentries1 = tr1 -> GetEntries();
   tr1 -> SetBranchAddress("B_CM",&B_CM1);

   TH1D * Bd_mc_mass = new TH1D("Bd_mc_mass", "MC2015Bd_Up", 100, 2000.0, 10000.0);
   Bd_mc_mass -> Sumw2();
   

   for (int j = 0; j<nentries1; j++){
    
    tr1 -> GetEntry(j);
    Bd_mc_mass -> Fill(B_CM1);
    
   }
   Bd_mc_mass -> SetLineWidth(6);
    Bd_mc_mass-> DrawNormalized("HIST");
    B_corr_mass -> SetLineColor(kRed);
    B_corr_mass -> SetLineStyle(2);
    B_corr_mass -> SetLineWidth(6);
    B_corr_mass -> DrawNormalized("SAME HIST");


    gPad -> BuildLegend();
    return 1;

}
