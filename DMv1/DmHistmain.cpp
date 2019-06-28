/*


This file turns the tree of the D mass into a histogram


 */



#include <TFile.h>
#include <TTree.h>
#include <iostream>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TApplication.h>
#include <TROOT.h>

#include <Math/Vector3D.h>
#include <Math/Vector4D.h>
#include <Math/Vector4Dfwd.h>
#include "Inclusion.h"

int main(){
  
  const char* filename = "/afs/cern.ch/work/z/zwolffs/public/data/DataRun/Data2016_Strip28r1_MagUp311.root";
  TFile *oldfile = new TFile(filename);
  TTree *oldtree = (TTree*)oldfile->Get("DecayTree");
  int nentries=oldtree->GetEntries();

  Double_t         D_M;

  
  oldtree->SetBranchAddress("D_M", &D_M);

  oldtree->SetBranchStatus("*",0);
  oldtree->SetBranchStatus("D_M",1);

  std::string filename_s(filename);
  std::string root = ".root";
  std::string newfilenamenoroot = filename_s.erase(filename_s.find(".root"));
  std::string DM = "DM";

  std::string newfilename = newfilenamenoroot + DM + root;
  const char *newfilename_c = newfilename.c_str();

  TFile *newfile = new TFile(newfilename_c,"recreate");

  TH1D* D_M_hist = new TH1D("D_M_hist", "histo with D Mass", 300, 1800, 1980);

  for (int i = 0; i<nentries;i++){
    oldtree->GetEntry(i);

    D_M_hist -> Fill(D_M);


  }
  D_M_hist -> Write();
  newfile -> Write();
  return 0;
}
