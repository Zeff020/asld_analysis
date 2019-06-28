/*


This file applies the cuts to the 2016 dataset and also is capable of decreasing it in size.


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
#include <string>

#include <Math/Vector3D.h>
#include <Math/Vector4D.h>
#include <Math/Vector4Dfwd.h>
#include "Inclusion.h"

std::string DecreaseTreeSizeAndCuts(char filename[], char dirname[], char decsize[]){

  typedef ROOT::Math::PtEtaPhiMVector MyLorentzVector;

  int idecsize = atoi(decsize);
//Get old file, old tree and set top branch address



TFile *oldfile = new TFile(filename);
TDirectoryFile* dir = (TDirectoryFile*)oldfile->Get(dirname);
TTree *oldtree = (TTree*)dir->Get("DecayTree");
int nentries=oldtree->GetEntries();

// Set variables in tree
   Double_t         B_ETA;
   Double_t         B_M;
   Double_t         B_PHI;
   Double_t         B_PT;
   Double_t         B_ENDVERTEX_X;
   Double_t         B_ENDVERTEX_Y;
   Double_t         B_ENDVERTEX_Z;
   Double_t         B_OWNPV_X;
   Double_t         B_OWNPV_Y;
   Double_t         B_OWNPV_Z;
   Double_t         D_IP;
   Double_t         D_M;
   Double_t         K_ETA;
   Double_t         K_IP;
   Double_t         K_PHI;
   Double_t         K_PIDK;
   Double_t         K_PT;
   Double_t         Pi1_ETA;
   Double_t         Pi1_ISMUON;
   Double_t         Pi1_PHI;
   Double_t         Pi1_PIDK;
   Double_t         Pi1_PIDp;
   Double_t         Pi1_PT;
   Double_t         Pi2_ETA;
   Double_t         Pi2_PHI;
   Double_t         Pi2_PIDK;
   Double_t         Pi2_PIDp;
   Double_t         Pi2_PT;
   Double_t         Mu_ETA;
   Double_t         Mu_PHI;
   Double_t         Mu_PT;
   

   
   Float_t lambda1Mass;   
   Float_t lambda2Mass;   
   Float_t jpsi1Mass;

   static Float_t cLight  = 0.299792458; 
   static Float_t massB   = 5279.58;   
   static Float_t massK   = 493.677;   
   static Float_t massPi  = 139.57 ;   
   static Float_t massP   = 938.27;   
   static Float_t massMu  = 105.658;
   
   bool fLambdaVeto = true;   
   bool fJpsiVeto = true;

   // set Branch addresses

   oldtree->SetBranchAddress("B_ETA", &B_ETA);
   oldtree->SetBranchAddress("B_M", &B_M);
   oldtree->SetBranchAddress("B_PHI", &B_PHI);
   oldtree->SetBranchAddress("B_PT", &B_PT);
   oldtree->SetBranchAddress("B_ENDVERTEX_X", &B_ENDVERTEX_X);
   oldtree->SetBranchAddress("B_ENDVERTEX_Y", &B_ENDVERTEX_Y);
   oldtree->SetBranchAddress("B_ENDVERTEX_Z", &B_ENDVERTEX_Z);
   oldtree->SetBranchAddress("B_OWNPV_X", &B_OWNPV_X);
   oldtree->SetBranchAddress("B_OWNPV_Y", &B_OWNPV_Y);
   oldtree->SetBranchAddress("B_OWNPV_Z", &B_OWNPV_Z);
   oldtree->SetBranchAddress("D_IP", &D_IP);
   oldtree->SetBranchAddress("D_M", &D_M);
   oldtree->SetBranchAddress("K_ETA", &K_ETA);
   oldtree->SetBranchAddress("K_IP", &K_IP);
   oldtree->SetBranchAddress("K_PIDK", &K_PIDK);
   oldtree->SetBranchAddress("K_PT", &K_PT);
   oldtree->SetBranchAddress("K_PHI", &K_PHI);
   oldtree->SetBranchAddress("Pi1_ETA", &Pi1_ETA);
   oldtree->SetBranchAddress("Pi1_ISMUON", &Pi1_ISMUON);
   oldtree->SetBranchAddress("Pi1_PHI", &Pi1_PHI);
   oldtree->SetBranchAddress("Pi1_PIDK", &Pi1_PIDK);
   oldtree->SetBranchAddress("Pi1_PIDp", &Pi1_PIDp);
   oldtree->SetBranchAddress("Pi1_PT", &Pi1_PT);
   oldtree->SetBranchAddress("Pi2_ETA", &Pi2_ETA);
   oldtree->SetBranchAddress("Pi2_PHI", &Pi2_PHI);
   oldtree->SetBranchAddress("Pi2_PIDK", &Pi2_PIDK);
   oldtree->SetBranchAddress("Pi2_PIDp", &Pi2_PIDp);
   oldtree->SetBranchAddress("Pi2_PT", &Pi2_PT);
   oldtree->SetBranchAddress("Mu_ETA", &Mu_ETA);
   oldtree->SetBranchAddress("Mu_PHI", &Mu_PHI);
   oldtree->SetBranchAddress("Mu_PT", &Mu_PT);

   // Turn on branches to clone
   oldtree->SetBranchStatus("*",0);
   oldtree->SetBranchStatus("B_ETA",1);
   oldtree->SetBranchStatus("B_M",1);
   oldtree->SetBranchStatus("B_PHI",1);
   oldtree->SetBranchStatus("B_PT",1);
   oldtree->SetBranchStatus("B_ENDVERTEX_X",1);
   oldtree->SetBranchStatus("B_ENDVERTEX_Y",1);
   oldtree->SetBranchStatus("B_ENDVERTEX_Z",1);
   oldtree->SetBranchStatus("B_OWNPV_Z",1);
   oldtree->SetBranchStatus("B_OWNPV_Y",1);
   oldtree->SetBranchStatus("B_OWNPV_X",1);
   oldtree->SetBranchStatus("D_M",1);
  
   std::string filename_s(filename);
   std::string decsize_s(decsize);
   std::string root = ".root";
   std::string newfilenamenoroot = filename_s.erase(filename_s.find(".root"));
   

   std::string newfilename = newfilenamenoroot + decsize_s + root;
   const char *newfilename_c = newfilename.c_str();
   

   TFile *newfile = new TFile(newfilename_c,"recreate");
   TTree *newtree = oldtree->CloneTree(0);

   // Turn on rest of branches needed in this file
   oldtree->SetBranchStatus("D_IP",1);
   oldtree->SetBranchStatus("K_ETA",1);
   oldtree->SetBranchStatus("K_IP",1);
   oldtree->SetBranchStatus("K_PT",1);
   oldtree->SetBranchStatus("K_PIDK",1);
   oldtree->SetBranchStatus("K_PHI",1);
   oldtree->SetBranchStatus("Pi1_ETA",1);
   oldtree->SetBranchStatus("Pi1_ISMUON",1);
   oldtree->SetBranchStatus("Pi1_PHI",1);
   oldtree->SetBranchStatus("Pi1_PIDK",1);
   oldtree->SetBranchStatus("Pi1_PIDp",1);
   oldtree->SetBranchStatus("Pi1_PT",1);
   oldtree->SetBranchStatus("Pi2_ETA",1);
   oldtree->SetBranchStatus("Pi2_PHI",1);
   oldtree->SetBranchStatus("Pi2_PIDK",1);
   oldtree->SetBranchStatus("Pi2_PIDp",1);
   oldtree->SetBranchStatus("Pi2_PT",1);
   oldtree->SetBranchStatus("Mu_ETA",1);
   oldtree->SetBranchStatus("Mu_PHI",1);
   oldtree->SetBranchStatus("Mu_PT",1);

for (Long64_t i=0;i<(nentries/idecsize); i++) {

      oldtree->GetEntry(i);

      // ------------------------------------- CUTS --------------------------------------------- //   

      // "old" cali cuts
   if ( Mu_PT < 1200. ) continue;
   if ( Pi1_PT < 1200. ) continue ; 
   if ( K_PT < 300. ) continue ;
   if ( Pi2_PT < 300. ) continue ; 
   if ( Mu_PT*cosh(Mu_ETA) < 3000. ) continue ; 
   if ( Pi1_PT*cosh(Pi1_ETA) < 3000. ) continue ; 
   if ( Pi2_PT*cosh(Pi2_ETA) < 3000. ) continue ; 
   if ( K_PT*cosh(K_ETA) < 3000. ) continue ;

   // cali cuts
   if ( Mu_PT*cosh(Mu_ETA) < 6000. ) continue ;
   if ( Pi1_PT*cosh(Pi1_ETA) < 6000. ) continue ;

   // Lorentz vector cuts (Leave them out for now)
   /*
   MyLorentzVector LorentzMuon = MyLorentzVector(Mu_PT,Mu_ETA,Mu_PHI, massMu);       
   float Mu_Px = LorentzMuon.Px();    
   if (( std::fabs(Mu_Px) < (Mu_PT*cosh(Mu_ETA) - 3400.)) && (std::fabs(Mu_Px)< 600. || std::fabs(Mu_Px)> 1100.)) continue;
   */

   // PIDK cuts
   if(K_PIDK < 7)continue;       
   if(Pi2_PIDK > 3)continue;       
   if(Pi1_PIDK > 10)continue;
   
   // Log IP cut
   if ( log(D_IP) < -3.0 ) continue; 
   

   // D mass cut
   if ((D_M < 1800) || (D_M > 1980)) continue; 
   
   // Lambda Veto
   MyLorentzVector vK = MyLorentzVector(K_PT,K_ETA,K_PHI, massK);     
   MyLorentzVector vPi1 = MyLorentzVector(Pi1_PT,Pi1_ETA,Pi1_PHI, massP);       
   MyLorentzVector vPi2 = MyLorentzVector(Pi2_PT,Pi2_ETA,Pi2_PHI, massPi);       
   lambda1Mass = (vK+vPi1+vPi2).M();       
   vPi1.SetM( massPi );       
   vPi2.SetM( massP  );       
   lambda2Mass = (vK+vPi1+vPi2).M();

   // Jpsi veto
   MyLorentzVector vMu = MyLorentzVector(Mu_PT,Mu_ETA,Mu_PHI, massMu);
   vPi1.SetM( massMu );       
   jpsi1Mass = (vMu+vPi1).M();

   if ( fLambdaVeto )
     {
       if( Pi1_PIDp > 10 && lambda1Mass > 2260 && lambda1Mass < 2310 ) continue; 	
       if( Pi2_PIDp > 10 && lambda2Mass > 2260 && lambda2Mass < 2310 ) continue;       
     }       
   if ( fJpsiVeto )
     { 	
       if( Pi1_ISMUON == 1 && jpsi1Mass > 3070 && jpsi1Mass < 3150   ) continue;      
     }

   newtree->Fill();
   // Fill new datapoint in tree if all cuts are accepted          
 }
    
newtree->Print();
newtree->AutoSave();
delete oldfile;
delete newfile;
return newfilename;
}
