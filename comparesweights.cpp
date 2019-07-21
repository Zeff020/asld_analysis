#include <RooDataHist.h>
#include <RooGaussian.h>
#include <RooHistPdf.h>
#include <RooPlot.h>
#include <RooHistPdf.h>

#include "Inclusion.h"

using namespace std;

int comparesweights(){
   TFile *f2 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/Data2015_Strip24r1_MagUp1b2DpMuXBcm.root");
  TTree *tr2 = (TTree*)f2->Get("DecayTree");


  Float_t nsig_sw2;
  Float_t B_CM2;
  
  Int_t nentries2 = 0; //Providing initial value
  nentries2 = tr2 -> GetEntries();

  tr2 -> SetBranchAddress("B_CM",&B_CM2);
  
  TH1D * B_corr_mass_weighted2 = new TH1D("B_mass_2015", "B mass 2015 dataset", 100, 2000.0, 10000.0);
  B_corr_mass_weighted2 -> Sumw2();
  

  TH1D * B_corr_mass_weighted21 = new TH1D("B_mass_2015", "B mass 2015 dataset", 100, 2000.0, 10000.0);
  
  // Getting the SWeights
  TFile *fsweights2 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/Data2015_Strip24r1_MagUp1sweights.root");
  TTree *trsweights2 = (TTree*)fsweights2->Get("DecayTree");
   
  trsweights2 -> SetBranchAddress("nsig_sw",&nsig_sw2);
  
  for (int k = 0; k<nentries2; k++){
    
    tr2 -> GetEntry(k);
    trsweights2 -> GetEntry(k);
    B_corr_mass_weighted2 -> Fill(B_CM2,nsig_sw2);
    
    B_CM2 = nsig_sw2*B_CM2;
    B_corr_mass_weighted21 -> Fill(B_CM2);
    
    
  }

  auto C = new TCanvas();
  B_corr_mass_weighted2 -> DrawNormalized("HIST");
  B_corr_mass_weighted21 -> DrawNormalized("HIST SAME");

  return 0;
}
