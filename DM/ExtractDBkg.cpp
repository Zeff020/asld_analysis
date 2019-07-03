#include <TFile.h>
#include <TTree.h>
#include <TROOT.h>
#include <TH1.h>


// All of the roofit stuff
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooDataHist.h>
#include <RooGaussian.h>
#include <RooPlot.h>
#include <RooHistPdf.h>
#include "Inclusion.h"
  
using namespace RooFit;
using namespace RooStats;
  
  
void ExtractDBkg(){
  
  TFile *f = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/Data2016_Strip28r1_MagUpsmall100withcutsbc.root");
  TTree *tr = (TTree*)f->Get("DecayTree");
  
  int nentries=tr->GetEntries();

  Float_t         B_CM;
  Double_t         D_M;
  Float_t         D_M_bkg;
  Float_t         B_DM_bkg;
  

  tr->SetBranchAddress("D_M", &D_M);
  tr->SetBranchAddress("B_CM", &B_CM);

  tr -> SetBranchStatus("*",0);
  tr -> SetBranchStatus("D_M",1);
  tr -> SetBranchStatus("B_CM",1);

  TFile *newf = new TFile("../../data/D_M_bkg500bins.root","recreate");
  TH1* hDM_bkg = new TH1F("h1", "histo with D Mass sidebands", 200, 1800, 1980);
  TH1* hBM_DM_bkg = new TH1F("h2", "histo with the corrected B mass datapoints of the D mass sidebands", 200, 2300,7000);
  

  for (int i = 0; i<nentries; i++){
    tr -> GetEntry(i);

    if ((D_M > 1841) && (D_M <1895)) continue;
    D_M_bkg = D_M;
    B_DM_bkg = B_CM;
    //br_D_M_bkg -> Fill();
    hDM_bkg -> Fill(D_M_bkg);
    hBM_DM_bkg -> Fill(B_DM_bkg);
    
  }
  hDM_bkg -> Write();
  
  //newf -> Write();
  TCanvas* a = new TCanvas("D and B mass Background","D and B mass background");
  a->Divide(1,2);
  a->cd(1);
  hBM_DM_bkg -> DrawNormalized("HIST PLC");
  a->cd(2);
  hDM_bkg-> Draw("PLC");

  // Second sideband cuts

  //TFile *newf = new TFile("../../data/D_M_bkg500bins.root","recreate");
  TH1* hDM_bkg1 = new TH1F("h11", "histo with D Mass sidebands", 200, 1800, 1980);
  TH1* hBM_DM_bkg1 = new TH1F("h21", "histo with the corrected B mass datapoints of the D mass sidebands", 200, 2300,7000);
  

  for (int j = 0; j<nentries; j++){
    tr -> GetEntry(j);

    if ((D_M > 1830) && (D_M <1910)) continue;
    D_M_bkg = D_M;
    B_DM_bkg = B_CM;
    //br_D_M_bkg -> Fill();
    hDM_bkg1 -> Fill(D_M_bkg);
    hBM_DM_bkg1 -> Fill(B_DM_bkg);
    
  }
  //hDM_bkg -> Write();
  
  //newf -> Write();
  a->cd(1);
  hBM_DM_bkg1 -> DrawNormalized("HIST SAME PLC");
  a->cd(2);
  hDM_bkg1-> Draw("SAME PLC");

  TH1* hDM_bkg2 = new TH1F("h12", "histo with D Mass sidebands", 200, 1800, 1980);
  TH1* hBM_DM_bkg2 = new TH1F("h22", "histo with the corrected B mass datapoints of the D mass sidebands", 200, 2300,7000);
 

  for (int h = 0; h<nentries; h++){
    tr -> GetEntry(h);

    if ((D_M > 1820) && (D_M <1920)) continue;
    D_M_bkg = D_M;
    B_DM_bkg = B_CM;
    //br_D_M_bkg -> Fill();
    hDM_bkg2 -> Fill(D_M_bkg);
    hBM_DM_bkg2 -> Fill(B_DM_bkg);
    
  }
  //hDM_bkg -> Write();
  
  //newf -> Write();
  a->cd(1);
  hBM_DM_bkg2 -> DrawNormalized("HIST SAME PLC");
  a->cd(2);
  hDM_bkg2-> Draw("SAME PLC");
}
