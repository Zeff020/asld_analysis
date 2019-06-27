/* 


This file plots the corrected B mass and the B mass from the 2016 dataset on a single canvas


 */

#include <TFile.h>
#include <TTree.h>
#include <TROOT.h>

#include <Math/Vector3D.h>
#include <Math/Vector4D.h>
#include <Math/Vector4Dfwd.h>
#include "Inclusion.h"

// All of the roofit stuff
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooDataHist.h>
#include <RooGaussian.h>
#include <RooPlot.h>
#include <RooHistPdf.h>
#include "Inclusion.h"

void plotbm(){
  TFile *f = new TFile("../../data/Data2016_Strip28r1_MagUpsmall300withcutssweightsbc.root");
  TTree *tr = (TTree*)f->Get("DecayTree");

  Double_t         B_M;
  Float_t          B_CM;
  Float_t          B_CM_SB;
  Float_t          B_CM_SR;
  

  tr -> SetBranchAddress("B_M", &B_M);
  tr -> SetBranchAddress("B_CM", &B_CM);
  tr -> SetBranchAddress("B_CM_SB", &B_CM_SB);
  tr -> SetBranchAddress("B_CM_SR", &B_CM_SR);
  
  RooRealVar *mB = new RooRealVar("B_M","mass B",2000,8000, "MeV");
  RooRealVar *mcB = new RooRealVar("B_CM","corrected B mass",2000,8000, "Mev");
  RooRealVar *mcsrB = new RooRealVar("B_CM_SB","signal region of corrected B mass",2000,8000,"MeV"); //Signal region of corrected B mass
  RooRealVar *mcsbB = new RooRealVar("B_CM_SR","sideband region of corrected B mass",2000,8000,"MeV"); //Sideband region of corrected B mass
  
  RooDataSet * roo_B_M = new RooDataSet("mass B","",tr,RooArgList(*mB));
  RooDataSet * roo_B_CM = new RooDataSet("corrected B mass", "",tr, RooArgList(*mcB));
  RooDataSet * roo_B_CM_SR = new RooDataSet("signal region of corrected B mass", "", tr, RooArgList(*mcsrB));
  RooDataSet * roo_B_CM_SB = new RooDataSet("sideband region of corrected B mass", "", tr, RooArgList(*mcsbB));
  
  TCanvas* B_Canvas = new TCanvas("B mass","B mass");
  tr -> Print();


  RooPlot* B_frame = mB -> frame();
  roo_B_M -> plotOn(B_frame, Name("mass B"));
  
  RooPlot* BC_frame = mcB -> frame();
  roo_B_CM -> plotOn(BC_frame, Name("corrected B mass"));
 
  RooPlot* B_CM_SR_frame = mcsrB -> frame();
  roo_B_CM_SR -> plotOn(B_CM_SR_frame, Name("signal region of corrected B mass"));

  RooPlot* B_CM_SB_frame = mcsbB -> frame();
  roo_B_CM_SB -> plotOn(B_CM_SB_frame, Name("sideband region of corrected B mass"));

  B_Canvas->Divide(4) ;
  B_Canvas->cd(1) ; gPad->SetLeftMargin(0.15) ; B_frame->GetYaxis()->SetTitleOffset(1.6) ; B_frame->Draw() ;
  B_Canvas->cd(2) ; gPad->SetLeftMargin(0.15) ; BC_frame->GetYaxis()->SetTitleOffset(1.6) ; BC_frame->Draw() ;
  B_Canvas->cd(3) ; gPad->SetLeftMargin(0.15) ; B_CM_SR_frame->GetYaxis()->SetTitleOffset(1.6) ; B_CM_SR_frame->Draw() ;
  B_Canvas->cd(4) ; gPad->SetLeftMargin(0.15) ; B_CM_SB_frame->GetYaxis()->SetTitleOffset(1.6) ; B_CM_SB_frame->Draw() ;

}
