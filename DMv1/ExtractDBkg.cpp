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
  
  
std::string ExtractDBkg(const char* filename){
  
  TFile *f = new TFile(filename);
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


  // Generating a new file with two histograms, one with the D mass background and one with the B mass background
  std::string filename_s(filename);
  std::string root = ".root";

  std::string newfilenamenoroot = filename_s.erase(filename_s.find(".root"));

  std::string newfilename = newfilenamenoroot + "DMbkg" + root;
  const char *newfilename_c = newfilename.c_str();

  TFile *newf = new TFile(newfilename_c,"recreate");
  TH1* hDM_bkg = new TH1F("h1Dmass", "histo with D Mass sidebands", 500, 1800, 1980); // DEFINE HERE BINNING
  TH1* hBM_DM_bkg = new TH1F("h2Bmass", "histo with the corrected B mass datapoints of the D mass sidebands", 500, 2300,7000); // DEFINE HERE BINNING
  

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
  
  newf -> Write();
  TCanvas* a = new TCanvas("D and B mass Background","D and B mass background");
  a->Divide(1,2);
  a->cd(1);
  hBM_DM_bkg -> Draw();
  a->cd(2);
  hDM_bkg-> Draw();

  return newfilename;
}
