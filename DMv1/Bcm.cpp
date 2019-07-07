/*

This file calculates the corrected B mass of the B data in a given tree and saves it into a new tree.

*/




#include <TFile.h>
#include <TTree.h>
#include <TROOT.h>
#include <TH1.h>

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


std::string Bcm(const char* filename, const char* dirname){

  typedef ROOT::Math::PtEtaPhiMVector MyLorentzVector;
  typedef ROOT::Math::XYZVector ThreeVector;

  TFile *oldf = new TFile(filename);
  TTree *oldtr = (TTree*)oldf -> Get("DecayTree");


  Double_t         B_M;
  Double_t         B_PHI;
  Double_t         B_ETA;
  Double_t         B_PT;
  Double_t         B_ENDVERTEX_X;
  Double_t         B_ENDVERTEX_Y;
  Double_t         B_ENDVERTEX_Z;
  Double_t         B_OWNPV_X;
  Double_t         B_OWNPV_Y;
  Double_t         B_OWNPV_Z;
  Double_t         D_M;
  
  Float_t B_CM;
  
  static Float_t massB   = 5279.58;
  Int_t nentries=oldtr->GetEntries();
  
  oldtr -> SetBranchAddress("B_M", &B_M);
  oldtr -> SetBranchAddress("B_PT",&B_PT);
  oldtr -> SetBranchAddress("B_ETA", &B_ETA);
  oldtr -> SetBranchAddress("B_PHI", &B_PHI);
  oldtr -> SetBranchAddress("B_OWNPV_X", &B_OWNPV_X);
  oldtr -> SetBranchAddress("B_OWNPV_Y", &B_OWNPV_Y);
  oldtr -> SetBranchAddress("B_OWNPV_Z", &B_OWNPV_Z);
  oldtr -> SetBranchAddress("B_ENDVERTEX_X", &B_ENDVERTEX_X);
  oldtr -> SetBranchAddress("B_ENDVERTEX_Y", &B_ENDVERTEX_Y);
  oldtr -> SetBranchAddress("B_ENDVERTEX_Z", &B_ENDVERTEX_Z);
  oldtr -> SetBranchAddress("D_M", &D_M);  

  oldtr -> SetBranchStatus("*",0);
  oldtr -> SetBranchStatus("D_M",1); // Set branch status such that only D_M is cloned to new tree


  // Making a new file name
  std::string filename_s(filename);
  std::string root = ".root";
  std::string bcm = "Bcm";
  std::string dirname_s(dirname); 
  std::string newfilenamenoroot = filename_s.erase(filename_s.find(".root"));

  

  std::string newfilename = newfilenamenoroot + dirname_s + bcm + root;
  const char *newfilename_c = newfilename.c_str();

  

  TFile *newf = new TFile(newfilename_c, "recreate");
  TTree *newtr = oldtr->CloneTree();

  // Initialize a corrected mass hist
  //TH1F * B_corrected_mass = new TH1F("B_corrected_mass", "B_corrected_mass", 200, 0.0, 12000.0);
  //B_corrected_mass->Sumw2();
  oldtr -> SetBranchStatus("*",1);
  
  auto br_B_CM = newtr -> Branch("B_CM",&B_CM, "B_CM/F");

  for (int i = 0; i<nentries; i++)
    {
    oldtr->GetEntry(i);

      // ----------------------------------------- B CORRECTED------------------------------------------------ //
    MyLorentzVector mom = MyLorentzVector(B_PT,B_ETA,B_PHI, massB);
    ThreeVector threemom = mom.Vect();
    
    
    // DONT UNDERSTAND FROM HERE, ASK LUCIA
    ThreeVector dir;     
    dir.SetCoordinates((B_ENDVERTEX_X - B_OWNPV_X), (B_ENDVERTEX_Y - B_OWNPV_Y), (B_ENDVERTEX_Z - B_OWNPV_Z));     
    double dmag2 = dir.Mag2(); // Magnitude squared
    ThreeVector perp = threemom - dir*(threemom.Dot(dir)/dmag2);     
    double missing_PT = perp.R();
    B_CM = sqrt((B_M*B_M) + (missing_PT*missing_PT)) + missing_PT;
    if (B_CM < 0) {B_CM = 0.001;};
    br_B_CM -> Fill();
    //B_corrected_mass->Fill(B_CM,nsig_sw); // Fill the corrected mass WITH the sweights
    }

  //---------------------------------------------------SAVE---------------------------------------------------//
  newf -> cd();
  newtr->Write();
  newtr->Print();
  //B_corrected_mass->Write();
  delete oldf;
  delete newf;

  return newfilename;
}
