#include <TFile.h>
#include <TTree.h>
#include <iostream>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TApplication.h>
#include <TROOT.h>

// All of the roofit stuff
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooDataHist.h>
#include <RooGaussian.h>
#include <RooPlot.h>
#include <RooHistPdf.h>
#include <Math/Vector3D.h>
#include <Math/Vector4D.h>
#include <Math/Vector4Dfwd.h>
#include "Inclusion.h"

using namespace RooFit;
using namespace RooStats;


  
int AnalysisSimpleroot(){
  
  typedef ROOT::Math::PtEtaPhiMVector MyLorentzVector;

  TDirectoryFile* dir;
  TTree* tr;
  TFile* f;
  
  static Float_t cLight  = 0.299792458; 
  static Float_t massB   = 5279.58;   
  static Float_t massK   = 493.677;   
  static Float_t massPi  = 139.57 ;   
  static Float_t massP   = 938.27;   
  static Float_t massMu  = 105.658;
  
  // Initializing variable types
  
  Double_t        B_D_FD;
   Double_t        B_ETA;
   Double_t        B_ID;
   Double_t        B_M;
   Double_t        B_P;
   Double_t        B_PHI;
   Double_t        B_PT;
   Double_t        B_VCHI2NDOF;
   Double_t        B_ENDVERTEX_X;
   Double_t        B_ENDVERTEX_Y;
   Double_t        B_ENDVERTEX_Z;
   Double_t        B_ENDVERTEX_XERR;
   Double_t        B_ENDVERTEX_YERR;
   Double_t        B_ENDVERTEX_ZERR;
   Double_t        B_ENDVERTEX_CHI2;
   Int_t           B_ENDVERTEX_NDOF;
   Float_t         B_ENDVERTEX_COV_[3][3];
   Double_t        B_OWNPV_X;
   Double_t        B_OWNPV_Y;
   Double_t        B_OWNPV_Z;
   Double_t        B_OWNPV_XERR;
   Double_t        B_OWNPV_YERR;
   Double_t        B_OWNPV_ZERR;
   Double_t        B_OWNPV_CHI2;
   Int_t           B_OWNPV_NDOF;
   Float_t         B_OWNPV_COV_[3][3];
   Double_t        B_IP_OWNPV;
   Double_t        B_IPCHI2_OWNPV;
   Double_t        B_FD_OWNPV;
   Double_t        B_FDCHI2_OWNPV;
   Double_t        B_DIRA_OWNPV;
   Double_t        D_ETA;
   Double_t        D_ID;
   Double_t        D_IP;
   Double_t        D_IPCHI2;
   Double_t        D_M;
   Double_t        D_PHI;
   Double_t        D_PT;
   Double_t        D_VCHI2NDOF;
   Double_t        D_ENDVERTEX_X;
   Double_t        D_ENDVERTEX_Y;
   Double_t        D_ENDVERTEX_Z;
   Double_t        D_ENDVERTEX_XERR;
   Double_t        D_ENDVERTEX_YERR;
   Double_t        D_ENDVERTEX_ZERR;
   Double_t        D_ENDVERTEX_CHI2;
   Int_t           D_ENDVERTEX_NDOF;
   Float_t         D_ENDVERTEX_COV_[3][3];
   Double_t        D_OWNPV_X;
   Double_t        D_OWNPV_Y;
   Double_t        D_OWNPV_Z;
   Double_t        D_OWNPV_XERR;
   Double_t        D_OWNPV_YERR;
   Double_t        D_OWNPV_ZERR;
   Double_t        D_OWNPV_CHI2;
   Int_t           D_OWNPV_NDOF;
   Float_t         D_OWNPV_COV_[3][3];
   Double_t        D_IP_OWNPV;
   Double_t        D_IPCHI2_OWNPV;
   Double_t        D_FD_OWNPV;
   Double_t        D_FDCHI2_OWNPV;
   Double_t        D_DIRA_OWNPV;
   Double_t        D_ORIVX_X;
   Double_t        D_ORIVX_Y;
   Double_t        D_ORIVX_Z;
   Double_t        D_ORIVX_XERR;
   Double_t        D_ORIVX_YERR;
   Double_t        D_ORIVX_ZERR;
   Double_t        D_ORIVX_CHI2;
   Int_t           D_ORIVX_NDOF;
   Float_t         D_ORIVX_COV_[3][3];
   Double_t        D_FD_ORIVX;
   Double_t        D_FDCHI2_ORIVX;
   Double_t        D_DIRA_ORIVX;
   Double_t        K_ETA;
   Double_t        K_GHOSTPROB;
   Double_t        K_ID;
   Double_t        K_IP;
   Double_t        K_IPCHI2;
   Double_t        K_ISMUON;
   Double_t        K_PHI;
   Double_t        K_PIDK;
   Double_t        K_PIDmu;
   Double_t        K_PIDp;
   Double_t        K_PT;
   Double_t        Pi1_ETA;
   Double_t        Pi1_GHOSTPROB;
   Double_t        Pi1_ID;
   Double_t        Pi1_IP;
   Double_t        Pi1_IPCHI2;
   Double_t        Pi1_ISMUON;
   Double_t        Pi1_PHI;
   Double_t        Pi1_PIDK;
   Double_t        Pi1_PIDmu;
   Double_t        Pi1_PIDp;
   Double_t        Pi1_PT;
   Double_t        Pi2_ETA;
   Double_t        Pi2_GHOSTPROB;
   Double_t        Pi2_ID;
   Double_t        Pi2_IP;
   Double_t        Pi2_IPCHI2;
   Double_t        Pi2_ISMUON;
   Double_t        Pi2_PHI;
   Double_t        Pi2_PIDK;
   Double_t        Pi2_PIDmu;
   Double_t        Pi2_PIDp;
   Double_t        Pi2_PT;
   Double_t        Mu_ETA;
   Double_t        Mu_GHOSTPROB;
   Double_t        Mu_ID;
   Double_t        Mu_IP;
   Double_t        Mu_IPCHI2;
   Double_t        Mu_ISMUON;
   Double_t        Mu_PHI;
   Double_t        Mu_PIDK;
   Double_t        Mu_PIDmu;
   Double_t        Mu_PIDp;
   Double_t        Mu_PT;
   UInt_t          nCandidate;
   ULong64_t       totCandidates;
   ULong64_t       EventInSequence;
   Int_t           nPV;
   Float_t         PVX[100];   //[nPV]
   Float_t         PVY[100];   //[nPV]
   Float_t         PVZ[100];   //[nPV]
   Float_t         PVXERR[100];   //[nPV]
   Float_t         PVYERR[100];   //[nPV]
   Float_t         PVZERR[100];   //[nPV]
   Float_t         PVCHI2[100];   //[nPV]
   Float_t         PVNDOF[100];   //[nPV]
   Float_t         PVNTRACKS[100];   //[nPV]
   Int_t CaliCutsOldN;
   Int_t CaliCutsN;
   Int_t VectorCutsN;
   Int_t PIDKcuts;
   Int_t logD_IP;
   
   Float_t lambda1Mass;   
   Float_t lambda2Mass;   
   Float_t jpsi1Mass;
   

   // Determining whether or not to apply the vetoes
   bool fLambdaVeto = true;   
   bool fJpsiVeto = true;

   
   
  //Initializing TApplication
  //TApplication *myapp=new TApplication("myapp",0,0);

  gStyle->SetLabelSize(0.045,"x");
  gStyle->SetLabelSize(0.045,"y");
  gStyle->SetTitleSize(0.05,"x");
  gStyle->SetTitleSize(0.05,"y");
  gStyle->SetOptFit(1);

  // Initializing mass as a TH1D
  TH1D* mass = new TH1D("D_Mass","",1000,1800,1980);
  RooRealVar dmass("dmass","", 1800,1980);
  RooDataSet roomass("d","d",dmass) ;

  f = new TFile("/eos/lhcb/user/l/lgrillo/AsldRunITuples/SLB_ntuplesRunII_v1/Data2016_Strip28r1_MagUp.root");

  // Extracting the directory from the file
  dir = (TDirectoryFile*)f->Get("b2DpMuX");
  
  // Extracting the tree from the directory
  tr = (TTree*)dir->Get("DecayTree");
  

  // Setting the branch addresses
  
   tr->SetBranchAddress("B_D_FD", &B_D_FD);
   tr->SetBranchAddress("B_ETA", &B_ETA);
   tr->SetBranchAddress("B_ID", &B_ID);
   tr->SetBranchAddress("B_M", &B_M);
   tr->SetBranchAddress("B_P", &B_P);
   tr->SetBranchAddress("B_PHI", &B_PHI);
   tr->SetBranchAddress("B_PT", &B_PT);
   tr->SetBranchAddress("B_VCHI2NDOF", &B_VCHI2NDOF);
   tr->SetBranchAddress("B_ENDVERTEX_X", &B_ENDVERTEX_X);
   tr->SetBranchAddress("B_ENDVERTEX_Y", &B_ENDVERTEX_Y);
   tr->SetBranchAddress("B_ENDVERTEX_Z", &B_ENDVERTEX_Z);
   tr->SetBranchAddress("B_ENDVERTEX_XERR", &B_ENDVERTEX_XERR);
   tr->SetBranchAddress("B_ENDVERTEX_YERR", &B_ENDVERTEX_YERR);
   tr->SetBranchAddress("B_ENDVERTEX_ZERR", &B_ENDVERTEX_ZERR);
   tr->SetBranchAddress("B_ENDVERTEX_CHI2", &B_ENDVERTEX_CHI2);
   tr->SetBranchAddress("B_ENDVERTEX_NDOF", &B_ENDVERTEX_NDOF);
   tr->SetBranchAddress("B_ENDVERTEX_COV_", B_ENDVERTEX_COV_);
   tr->SetBranchAddress("B_OWNPV_X", &B_OWNPV_X);
   tr->SetBranchAddress("B_OWNPV_Y", &B_OWNPV_Y);
   tr->SetBranchAddress("B_OWNPV_Z", &B_OWNPV_Z);
   tr->SetBranchAddress("B_OWNPV_XERR", &B_OWNPV_XERR);
   tr->SetBranchAddress("B_OWNPV_YERR", &B_OWNPV_YERR);
   tr->SetBranchAddress("B_OWNPV_ZERR", &B_OWNPV_ZERR);
   tr->SetBranchAddress("B_OWNPV_CHI2", &B_OWNPV_CHI2);
   tr->SetBranchAddress("B_OWNPV_NDOF", &B_OWNPV_NDOF);
   tr->SetBranchAddress("B_OWNPV_COV_", B_OWNPV_COV_);
   tr->SetBranchAddress("B_IP_OWNPV", &B_IP_OWNPV);
   tr->SetBranchAddress("B_IPCHI2_OWNPV", &B_IPCHI2_OWNPV);
   tr->SetBranchAddress("B_FD_OWNPV", &B_FD_OWNPV);
   tr->SetBranchAddress("B_FDCHI2_OWNPV", &B_FDCHI2_OWNPV);
   tr->SetBranchAddress("B_DIRA_OWNPV", &B_DIRA_OWNPV);
   tr->SetBranchAddress("D_ETA", &D_ETA);
   tr->SetBranchAddress("D_ID", &D_ID);
   tr->SetBranchAddress("D_IP", &D_IP);
   tr->SetBranchAddress("D_IPCHI2", &D_IPCHI2);
   tr->SetBranchAddress("D_M", &D_M);
   tr->SetBranchAddress("D_PHI", &D_PHI);
   tr->SetBranchAddress("D_PT", &D_PT);
   tr->SetBranchAddress("D_VCHI2NDOF", &D_VCHI2NDOF);
   tr->SetBranchAddress("D_ENDVERTEX_X", &D_ENDVERTEX_X);
   tr->SetBranchAddress("D_ENDVERTEX_Y", &D_ENDVERTEX_Y);
   tr->SetBranchAddress("D_ENDVERTEX_Z", &D_ENDVERTEX_Z);
   tr->SetBranchAddress("D_ENDVERTEX_XERR", &D_ENDVERTEX_XERR);
   tr->SetBranchAddress("D_ENDVERTEX_YERR", &D_ENDVERTEX_YERR);
   tr->SetBranchAddress("D_ENDVERTEX_ZERR", &D_ENDVERTEX_ZERR);
   tr->SetBranchAddress("D_ENDVERTEX_CHI2", &D_ENDVERTEX_CHI2);
   tr->SetBranchAddress("D_ENDVERTEX_NDOF", &D_ENDVERTEX_NDOF);
   tr->SetBranchAddress("D_ENDVERTEX_COV_", D_ENDVERTEX_COV_);
   tr->SetBranchAddress("D_OWNPV_X", &D_OWNPV_X);
   tr->SetBranchAddress("D_OWNPV_Y", &D_OWNPV_Y);
   tr->SetBranchAddress("D_OWNPV_Z", &D_OWNPV_Z);
   tr->SetBranchAddress("D_OWNPV_XERR", &D_OWNPV_XERR);
   tr->SetBranchAddress("D_OWNPV_YERR", &D_OWNPV_YERR);
   tr->SetBranchAddress("D_OWNPV_ZERR", &D_OWNPV_ZERR);
   tr->SetBranchAddress("D_OWNPV_CHI2", &D_OWNPV_CHI2);
   tr->SetBranchAddress("D_OWNPV_NDOF", &D_OWNPV_NDOF);
   tr->SetBranchAddress("D_OWNPV_COV_", D_OWNPV_COV_);
   tr->SetBranchAddress("D_IP_OWNPV", &D_IP_OWNPV);
   tr->SetBranchAddress("D_IPCHI2_OWNPV", &D_IPCHI2_OWNPV);
   tr->SetBranchAddress("D_FD_OWNPV", &D_FD_OWNPV);
   tr->SetBranchAddress("D_FDCHI2_OWNPV", &D_FDCHI2_OWNPV);
   tr->SetBranchAddress("D_DIRA_OWNPV", &D_DIRA_OWNPV);
   tr->SetBranchAddress("D_ORIVX_X", &D_ORIVX_X);
   tr->SetBranchAddress("D_ORIVX_Y", &D_ORIVX_Y);
   tr->SetBranchAddress("D_ORIVX_Z", &D_ORIVX_Z);
   tr->SetBranchAddress("D_ORIVX_XERR", &D_ORIVX_XERR);
   tr->SetBranchAddress("D_ORIVX_YERR", &D_ORIVX_YERR);
   tr->SetBranchAddress("D_ORIVX_ZERR", &D_ORIVX_ZERR);
   tr->SetBranchAddress("D_ORIVX_CHI2", &D_ORIVX_CHI2);
   tr->SetBranchAddress("D_ORIVX_NDOF", &D_ORIVX_NDOF);
   tr->SetBranchAddress("D_ORIVX_COV_", D_ORIVX_COV_);
   tr->SetBranchAddress("D_FD_ORIVX", &D_FD_ORIVX);
   tr->SetBranchAddress("D_FDCHI2_ORIVX", &D_FDCHI2_ORIVX);
   tr->SetBranchAddress("D_DIRA_ORIVX", &D_DIRA_ORIVX);
   tr->SetBranchAddress("K_ETA", &K_ETA);
   tr->SetBranchAddress("K_GHOSTPROB", &K_GHOSTPROB);
   tr->SetBranchAddress("K_ID", &K_ID);
   tr->SetBranchAddress("K_IP", &K_IP);
   tr->SetBranchAddress("K_IPCHI2", &K_IPCHI2);
   tr->SetBranchAddress("K_ISMUON", &K_ISMUON);
   tr->SetBranchAddress("K_PHI", &K_PHI);
   tr->SetBranchAddress("K_PIDK", &K_PIDK);
   tr->SetBranchAddress("K_PIDmu", &K_PIDmu);
   tr->SetBranchAddress("K_PIDp", &K_PIDp);
   tr->SetBranchAddress("K_PT", &K_PT);
   tr->SetBranchAddress("Pi1_ETA", &Pi1_ETA);
   tr->SetBranchAddress("Pi1_GHOSTPROB", &Pi1_GHOSTPROB);
   tr->SetBranchAddress("Pi1_ID", &Pi1_ID);
   tr->SetBranchAddress("Pi1_IP", &Pi1_IP);
   tr->SetBranchAddress("Pi1_IPCHI2", &Pi1_IPCHI2);
   tr->SetBranchAddress("Pi1_ISMUON", &Pi1_ISMUON);
   tr->SetBranchAddress("Pi1_PHI", &Pi1_PHI);
   tr->SetBranchAddress("Pi1_PIDK", &Pi1_PIDK);
   tr->SetBranchAddress("Pi1_PIDmu", &Pi1_PIDmu);
   tr->SetBranchAddress("Pi1_PIDp", &Pi1_PIDp);
   tr->SetBranchAddress("Pi1_PT", &Pi1_PT);
   tr->SetBranchAddress("Pi2_ETA", &Pi2_ETA);
   tr->SetBranchAddress("Pi2_GHOSTPROB", &Pi2_GHOSTPROB);
   tr->SetBranchAddress("Pi2_ID", &Pi2_ID);
   tr->SetBranchAddress("Pi2_IP", &Pi2_IP);
   tr->SetBranchAddress("Pi2_IPCHI2", &Pi2_IPCHI2);
   tr->SetBranchAddress("Pi2_ISMUON", &Pi2_ISMUON);
   tr->SetBranchAddress("Pi2_PHI", &Pi2_PHI);
   tr->SetBranchAddress("Pi2_PIDK", &Pi2_PIDK);
   tr->SetBranchAddress("Pi2_PIDmu", &Pi2_PIDmu);
   tr->SetBranchAddress("Pi2_PIDp", &Pi2_PIDp);
   tr->SetBranchAddress("Pi2_PT", &Pi2_PT);
   tr->SetBranchAddress("Mu_ETA", &Mu_ETA);
   tr->SetBranchAddress("Mu_GHOSTPROB", &Mu_GHOSTPROB);
   tr->SetBranchAddress("Mu_ID", &Mu_ID);
   tr->SetBranchAddress("Mu_IP", &Mu_IP);
   tr->SetBranchAddress("Mu_IPCHI2", &Mu_IPCHI2);
   tr->SetBranchAddress("Mu_ISMUON", &Mu_ISMUON);
   tr->SetBranchAddress("Mu_PHI", &Mu_PHI);
   tr->SetBranchAddress("Mu_PIDK", &Mu_PIDK);
   tr->SetBranchAddress("Mu_PIDmu", &Mu_PIDmu);
   tr->SetBranchAddress("Mu_PIDp", &Mu_PIDp);
   tr->SetBranchAddress("Mu_PT", &Mu_PT);
   tr->SetBranchAddress("nCandidate", &nCandidate);
   tr->SetBranchAddress("totCandidates", &totCandidates);
   tr->SetBranchAddress("EventInSequence", &EventInSequence);
   tr->SetBranchAddress("nPV", &nPV);
   tr->SetBranchAddress("PVX", PVX);
   tr->SetBranchAddress("PVY", PVY);
   tr->SetBranchAddress("PVZ", PVZ);
   tr->SetBranchAddress("PVXERR", PVXERR);
   tr->SetBranchAddress("PVYERR", PVYERR);
   tr->SetBranchAddress("PVZERR", PVZERR);
   tr->SetBranchAddress("PVCHI2", PVCHI2);
   tr->SetBranchAddress("PVNDOF", PVNDOF);
   tr->SetBranchAddress("PVNTRACKS", PVNTRACKS);
	
   // Getting the number of entries and printing, then filling only 1/nth of the data into histogram(mass) for time benefits
  int nentries=tr->GetEntries();
  
  // Some counters that count cut efficiency of each of the cutting groups
  int resize = 150;

  
  // For loop where we apply the cuts
  for (int i=0; i<nentries/resize; i++){
   
   tr->GetEntry(i);
   

   // Calibration Cuts

   // "Old" calibration cuts

   if ( Mu_PT < 1200. ) continue;
   if ( Pi1_PT < 1200. ) continue ; 
   if ( K_PT < 300. ) continue ;
   if ( Pi2_PT < 300. ) continue ; 
   if ( Mu_PT*cosh(Mu_ETA) < 3000. ) continue ; 
   if ( Pi1_PT*cosh(Pi1_ETA) < 3000. ) continue ; 
   if ( Pi2_PT*cosh(Pi2_ETA) < 3000. ) continue ; 
   if ( K_PT*cosh(K_ETA) < 3000. ) continue ;
   
   CaliCutsOldN++;
   
   // Calibration cuts

   if ( Mu_PT*cosh(Mu_ETA) < 6000. ) continue ;
   if ( Pi1_PT*cosh(Pi1_ETA) < 6000. ) continue ;
   
   CaliCutsN++;
   

   // Lorentz vector cuts!
   
MyLorentzVector LorentzMuon = MyLorentzVector(Mu_PT,Mu_ETA,Mu_PHI, massMu);       
float Mu_Px = LorentzMuon.Px();    
   
 if (( std::fabs(Mu_Px) < (Mu_PT*cosh(Mu_ETA) - 3400.)) && (std::fabs(Mu_Px)< 600. || std::fabs(Mu_Px)> 1100.)) continue;
   
 VectorCutsN++;

 // PIDK cuts!
 if(K_PIDK < 7)	continue;       
 if(Pi2_PIDK > 3)continue;       
 if(Pi1_PIDK > 10)continue;
 
 PIDKcuts++;


 // Add new log IP cut       
 if ( log(D_IP) < -3.0 ) continue; 

 logD_IP++;


 // D mass cut
 
 if ((D_M < 1800) || (D_M > 1980)) continue; 
 
 // Lambda Veto
MyLorentzVector vK = MyLorentzVector(K_PT,K_ETA,K_PHI, massK);     MyLorentzVector vPi1 = MyLorentzVector(Pi1_PT,Pi1_ETA,Pi1_PHI, massP);       
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
 
 dmass =  D_M;
 mass->Fill(D_M);
 roomass.add(dmass);
      
  }

  // New Stuff!
  // y defines the dimensions of the histogram!!!

  RooRealVar* y = new RooRealVar("D Mass", "Mass", 1800, 1980);   
  RooDataHist dataC("dataC", "dataset with D_Mass", *y, mass);

  RooRealVar *FC = new RooRealVar("FC","FC",0.50,0.0,1.0); 	
  RooFormulaVar* fracS = new RooFormulaVar("fracS","(1.0-FC)",RooArgList(*FC)); 

  RooRealVar *nsig =  new RooRealVar ("nsig", "nsig", 20.E5, 0., 10.E6); 	
  RooRealVar *nbkg =  new RooRealVar ("nbkg", "nbkg", 5.E5, 0., 10.E6); 


  RooRealVar *mean1 = new RooRealVar("mean1","mean1",1869.1,1830.,1900.); 	
  RooRealVar *sigma1 = new RooRealVar("sigma1","sigma1",5.0,3.0,20.0);         
  RooAbsPdf *gauss1 = new RooGaussian("gauss1","gauss(mD, mean1, sigma1)",*y,*mean1,*sigma1);

  RooRealVar *sigma2 = new RooRealVar("sigma2","sigma2",10.0,5.0,25.0);         
  RooAbsPdf *gauss2 = new RooGaussian("#gauss2","gauss(mD, mean1, sigma2)",*y,*mean1,*sigma2);

  RooAddPdf *Sig_mD = new RooAddPdf("Sig_mD", "Sig_mD", RooArgList(*gauss1, *gauss2), RooArgList(*FC, *fracS));

  RooRealVar *par = new RooRealVar("par","par",0.0, -1.0, 1.0);

  RooChebychev *Bkg_mD = new RooChebychev("Bkg_mD","Bkg_D_M", *y, RooArgList(*par));

  RooAddPdf *model = new RooAddPdf("model", "model", RooArgList(*Sig_mD, *Bkg_mD), RooArgList(*nsig, *nbkg));

  
  model -> fitTo(dataC);
  
  
  RooPlot* yframe = y -> frame();
  dataC.plotOn(yframe);
  model->plotOn(yframe);
  model->plotOn(yframe, Name("Sig"),Components("Sig_mD"),LineStyle(kDashed),LineColor(4)); 	
  model->plotOn(yframe, Name("Bkg"),Components("Bkg_mD"),LineStyle(kDashed),LineColor(2)); 
  yframe->Draw();
  
  
  // SWeights and SPlot

  FC -> setConstant();
  sigma1->setConstant();		
  mean1->setConstant();		
  par->setConstant();
  sigma2->setConstant();
  
  
  SPlot* sData = new SPlot("sData","Data sPlot", roomass, model, RooArgList(*nsig,*nbkg));
  
  
  /*
  //RooDataSet * data_sig = new RooDataSet(roomass.GetName(),roomass.GetTitle(),roomass,roomass.get(),0,"nsig_sw") ; 	
  //RooDataSet * data_bkg = new RooDataSet(roomass.GetName(),roomass.GetTitle(),roomass,roomass.get(),0,"nbkg_sw") ;
    
  //myapp->Run(true);  

  /* I leave the cut efficiencies out for now
  std::cout<< "Efficiency of CaliCutsOldN cut: " <<(Float_t)(CaliCutsOldN/(nentries/resize))<<endl;
  std::cout<< "Efficiency of Calibration cut: " <<(Float_t)(CaliCutsN/(nentries/resize))<<endl;
  std::cout<< "Efficiency of 4-vector cut: " <<(Float_t)(VectorCutsN/(nentries/resize))<<endl;
  std::cout<< "Efficiency of PIDKcuts cut: " <<(Float_t)(PIDKcuts/(nentries/resize))<<endl;
  std::cout<< "Efficiency of log(D_IP) cut: " <<(Float_t)(logD_IP/(nentries/resize))<<endl;
  
 std:cout << (nentries/resize) - CaliCutsOldN - CaliCutsN - VectorCutsN - PIDKcuts - logD_IP << endl;

  
  std::ostream& os = std::cout;
  
  nsig->Print();
  double Nsig = nsig->getValV();   
  double Nall = roomass.numEntries();
  */
  cout << *nsig << endl;
  
  return 0;

}
