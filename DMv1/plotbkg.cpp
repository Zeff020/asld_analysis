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

int plotbkg(){
  

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
   
   tr2->Delete();
   f2->Close();
   //Bu_mc_mass -> Delete();
   f2->Delete();

    //---------------------------------Getting the MC sample of the biggest physics background-------------------------------------------//
   
   TFile *f3 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataPBkg/2015_MC_Up_Bd2Dststmunu_DpCocktail1b2DpMuXBcm.root");
   TTree *tr3 = (TTree*)f3->Get("DecayTree");

   Float_t B_CM3;
   Int_t nentries3 = 0; //Providing initial value
   nentries3 = tr3 -> GetEntries();
   tr3 -> SetBranchAddress("B_CM",&B_CM3);
   
   TH1D * Bd2Dststmunu_DpCocktail = new TH1D("Bd2Dststmunu_DpCocktail", "Bd2Dststmunu_DpCocktail", 100, 2000.0, 10000.0);
   Bd2Dststmunu_DpCocktail -> Sumw2();
   
   for (int l = 0; l<nentries3; l++){
    
     tr3 -> GetEntry(l);
     Bd2Dststmunu_DpCocktail -> Fill(B_CM3);
   
   }
   
   RooDataHist* Bd2Dststmunu_DpCocktailh = new RooDataHist("Bd2Dststmunu_DpCocktailh", "Bd2Dststmunu_DpCocktailh", *y, Bd2Dststmunu_DpCocktail);
   RooHistPdf* Bd2Dststmunu_DpCocktailpdf =new RooHistPdf("Bd2Dststmunu_DpCocktailpdf", "Bd2Dststmunu_DpCocktailpdf", RooArgSet(*y), *Bd2Dststmunu_DpCocktailh, 0);
  

   

  return 0;
}
  
