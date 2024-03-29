#include <TFile.h>                                                                                                                        
#include <TTree.h>                                                                                                                        
#include <TROOT.h>                                                                                                                        
#include <string> 

#include "Inclusion.h"

using namespace std;

void plotbkg(){
  
// 2015_MC_Up_Bd2DD_DDcocktail_Dpmu

  TFile *f = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataPBkg/2015_MC_Up_Bd2DD_DDcocktail_Dpmu1b2DpMuXBcm.root");
  TTree *tr = (TTree*)f->Get("DecayTree");

  Float_t B_CM;
  
  int nentries = tr -> GetEntries();
  tr -> SetBranchAddress("B_CM",&B_CM);

  TH1D *MC_Up_Bd2DD_DDcocktail_Dpmu = new TH1D("B_mass", "Bd2DD_DDcocktail_Dpmu", 100, 2000.0, 6000.0);


  for (int k = 0; k<nentries; k++){
    
     tr -> GetEntry(k);
     MC_Up_Bd2DD_DDcocktail_Dpmu -> Fill(B_CM);
    
   }
  
  
  // 2015_MC_Up_Bd2Dptaunu

  TFile *f1 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataPBkg/2015_MC_Up_Bd2Dptaunu1b2DpMuXBcm.root");
  TTree *tr1 = (TTree*)f1->Get("DecayTree");

  Float_t B_CM1;
  
  int nentries1 = tr1 -> GetEntries();
  tr1 -> SetBranchAddress("B_CM",&B_CM1);

  TH1D *MC_Up_Bd2Dptaunu = new TH1D("B_mass1", "Bd2Dptaunu", 100, 2000.0, 6000.0);


  for (int l = 0; l<nentries1; l++){
    
     tr1 -> GetEntry(l);
     MC_Up_Bd2Dptaunu -> Fill(B_CM1);
    
   }


   //  2015_MC_Up_Bd2Dstptaunu_Dppi0
  TFile *f2 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataPBkg/2015_MC_Up_Bd2Dstptaunu_Dppi01b2DpMuXBcm.root");
  TTree *tr2 = (TTree*)f2->Get("DecayTree");

  Float_t B_CM2;
  
  int nentries2 = tr2 -> GetEntries();
  tr2 -> SetBranchAddress("B_CM",&B_CM2);

  TH1D *MC_Up_Bd2Dstptaunu_Dppi0 = new TH1D("B_mass2", "Bd2Dstptaunu_Dppi0", 100, 2000.0, 6000.0);


  for (int z = 0; z<nentries2; z++){
    
     tr2 -> GetEntry(z);
     MC_Up_Bd2Dstptaunu_Dppi0 -> Fill(B_CM2);
    
   }

  //  2015_MC_Up_Bd2Dststmunu_DpCocktail
  TFile *f3 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataPBkg/2015_MC_Up_Bd2Dststmunu_DpCocktail1b2DpMuXBcm.root");
  TTree *tr3 = (TTree*)f3->Get("DecayTree");

  Float_t B_CM3;
  
  int nentries3 = tr3 -> GetEntries();
  tr3 -> SetBranchAddress("B_CM",&B_CM3);

  TH1D *MC_Up_Bd2Dststmunu_DpCocktail  = new TH1D("B_mass3", "Bd2Dststmunu_DpCocktail", 100, 2000.0, 6000.0);


  for (int m = 0; m<nentries3; m++){
    
     tr3 -> GetEntry(m);
     MC_Up_Bd2Dststmunu_DpCocktail -> Fill(B_CM3);
    
   }

   //  2015_MC_Up_Bd2Dststmunu_DpCocktailHigher
  TFile *f4 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataPBkg/2015_MC_Up_Bd2Dststmunu_DpCocktailHigher1b2DpMuXBcm.root");
  TTree *tr4 = (TTree*)f4->Get("DecayTree");

  Float_t B_CM4;
  
  int nentries4 = tr4 -> GetEntries();
  tr4 -> SetBranchAddress("B_CM",&B_CM4);

  TH1D *MC_Up_Bd2Dststmunu_DpCocktailHigher  = new TH1D("B_mass4", "Bd2Dststmunu_DpCocktailHigher", 100, 2000.0, 6000.0);


  for (int n = 0; n<nentries4; n++){
    
     tr4 -> GetEntry(n);
     MC_Up_Bd2Dststmunu_DpCocktailHigher -> Fill(B_CM4);
    
   }


      //  2015_MC_Up_Bs2Dsmunu
  TFile *f5 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataPBkg/2015_MC_Up_Bs2Dsmunu1b2DpMuXBcm.root");
  TTree *tr5 = (TTree*)f5->Get("DecayTree");

  Float_t B_CM5;
  
  int nentries5 = tr5 -> GetEntries();
  tr5 -> SetBranchAddress("B_CM",&B_CM5);

  TH1D *MC_Up_Bs2Dsmunu  = new TH1D("B_mass5", "Bs2Dsmunu", 100, 2000.0, 6000.0);


  for (int b = 0; b<nentries5; b++){
    
     tr5 -> GetEntry(b);
     MC_Up_Bs2Dsmunu -> Fill(B_CM5);
    
   }


    // 2015_MC_Up_Bs2Dstaunu
    TFile *f6 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataPBkg/2015_MC_Up_Bs2Dstaunu1b2DpMuXBcm.root");
  TTree *tr6 = (TTree*)f6->Get("DecayTree");

  Float_t B_CM6;
  
  int nentries6 = tr6 -> GetEntries();
  tr6 -> SetBranchAddress("B_CM",&B_CM6);

  TH1D * MC_Up_Bs2Dstaunu = new TH1D("B_mass6", "Bs2Dstaunu", 100, 2000.0, 6000.0);


  for (int v = 0; v<nentries6; v++){
    
     tr6 -> GetEntry(v);
     MC_Up_Bs2Dstaunu -> Fill(B_CM6);
    
   }

    //2015_MC_Up_Bu2DD_DDcocktail_Dpmu

    TFile *f7 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataPBkg/2015_MC_Up_Bu2DD_DDcocktail_Dpmu1b2DpMuXBcm.root");
  TTree *tr7 = (TTree*)f7->Get("DecayTree");

  Float_t B_CM7;
  
  int nentries7 = tr7 -> GetEntries();
  tr7 -> SetBranchAddress("B_CM",&B_CM7);

  TH1D *MC_Up_Bu2DD_DDcocktail_Dpmu  = new TH1D("B_mass7", "Bu2DD_DDcocktail_Dpmu", 100, 2000.0, 6000.0);


  for (int c = 0; c<nentries7; c++){
    
     tr7 -> GetEntry(c);
     MC_Up_Bu2DD_DDcocktail_Dpmu -> Fill(B_CM7);
    
   }


    //2015_MC_Up_Bu2Dststmunu_DpCocktail
    TFile *f8 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataPBkg/2015_MC_Up_Bu2Dststmunu_DpCocktail1b2DpMuXBcm.root");
  TTree *tr8 = (TTree*)f8->Get("DecayTree");

  Float_t B_CM8;
  
  int nentries8 = tr8 -> GetEntries();
  tr8 -> SetBranchAddress("B_CM",&B_CM8);

  TH1D *MC_Up_Bu2Dststmunu_DpCocktail =new TH1D("B_mass8", "Bu2Dststmunu_DpCocktail", 100, 2000.0, 6000.0);


  for (int x = 0; x<nentries8; x++){
    
     tr8 -> GetEntry(x);
     MC_Up_Bu2Dststmunu_DpCocktail -> Fill(B_CM8);
    
   }

    //2015_MC_Up_Lb2LcD
  TFile *f9 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataPBkg/2015_MC_Up_Lb2LcD1b2DpMuXBcm.root");
  TTree *tr9 = (TTree*)f9->Get("DecayTree");

  Float_t B_CM9;
  
  int nentries9 = tr9 -> GetEntries();
  tr9 -> SetBranchAddress("B_CM",&B_CM9);

  TH1D *MC_Up_Lb2LcD =new TH1D("B_mass9", "Lb2LcD", 100, 2000.0, 6000.0);

  for (int a = 0; a<nentries9; a++){
    
     tr9 -> GetEntry(a);
     MC_Up_Lb2LcD-> Fill(B_CM9);
    
   }


  //--------------------------Getting the MC Bu dataset and extracting a roodatahist and PDF-----------------------------------------//
   TFile *f10 = new TFile("/afs/cern.ch/work/z/zwolffs/public/data/DataRun/MC2015Bu_Up1b2DpMuXBcm.root");
   TTree *tr10 = (TTree*)f10->Get("DecayTree");
   
   
   Float_t B_CM10;
   Int_t nentries10 = 0; //Providing initial value
   nentries10 = tr10 -> GetEntries();
   tr10 -> SetBranchAddress("B_CM",&B_CM10);
   
   TH1D * Bu_mc_mass = new TH1D("Bu_mc_mass", "Bu_mc_mass", 100, 2000.0, 6000.0);
   Bu_mc_mass -> Sumw2();

   for (int q = 0; q<nentries10; q++){
    
     tr10 -> GetEntry(q);
     Bu_mc_mass -> Fill(B_CM10);
    
   }
      

    auto C = new TCanvas();
    gStyle->SetOptStat(000000000);
     Bu_mc_mass -> SetTitle("feed-down components; MeV/c^2; Events (normalized)");
    Bu_mc_mass-> DrawNormalized("HIST");
    Bu_mc_mass->SetLineColor(kGreen);
    //MC_Up_Lb2LcD->DrawNormalized("HIST PLC PMC");
    //MC_Up_Bu2DD_DDcocktail_Dpmu->DrawNormalized("HIST PLC PMC");
    //MC_Up_Bs2Dstaunu->DrawNormalized("HIST PLC SAME");
    MC_Up_Bu2Dststmunu_DpCocktail->SetLineColor(kBlue);
    MC_Up_Bu2Dststmunu_DpCocktail->DrawNormalized("HIST SAME");
    //MC_Up_Bs2Dsmunu->DrawNormalized("HIST PLC SAME");
    //MC_Up_Bd2DD_DDcocktail_Dpmu ->DrawNormalized("HIST PLC  SAME");
    //MC_Up_Bd2Dptaunu->DrawNormalized("HIST PLC SAME");
     MC_Up_Bd2Dststmunu_DpCocktail->SetLineColor(kRed);
    MC_Up_Bd2Dststmunu_DpCocktail->DrawNormalized("HIST SAME");
    //MC_Up_Bd2Dstptaunu_Dppi0->DrawNormalized("HIST PLC SAME");
    //MC_Up_Bd2Dststmunu_DpCocktailHigher->DrawNormalized("HIST PLC SAME");
    
    
    
    TLegend *leg1 = new TLegend(0.65,0.73,0.86,0.87);
    leg1->SetFillColor(kWhite);
    leg1->SetLineColor(kWhite);
    leg1->AddEntry(MC_Up_Bu2Dststmunu_DpCocktail,"B^{+} #rightarrow D** decays ","l");
    leg1->AddEntry(MC_Up_Bd2Dststmunu_DpCocktail,"B^{0} #rightarrow D** decays","l");
    //leg1->AddEntry(Cmesframe->findObject("Data"),"Data (4 749 151)");
    leg1->Draw();
    
    
    
}
