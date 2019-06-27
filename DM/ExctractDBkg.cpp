#include <TFile.h>
#include <TTree.h>
#include <TROOT.h>


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
  
  TFile *f = new TFile("../../data/Data2016_Strip28r1_MagUpsmall300withcuts.root");
  TTree *tr = (TTree*)f->Get("DecayTree");
  
  int nentries=tr->GetEntries();

  Double_t         B_M;
  Double_t         D_M;
  Double_t         D_M_bkg;

  tr->SetBranchAddress("D_M", &D_M);
  tr->SetBranchAddress("B_M", &B_M);

  TFile *newf = new TFile("../../data/D_M_bkg.root","recreate");
  TTree *newtr = (TTree*)tr->CloneTree();

  newtr -> SetBranchAddress("D_M_bkg",&D_M_bkg);

  for (int i = 0; i<nentries; i++){
    tr -> GetEntry(i);

    if ((i > 1841) && (i <1895)) continue;
    D_M_bkg = D_M;
    newtr -> Fill();

  }

} 
