//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jun 12 11:38:23 2019 by ROOT version 6.16/00
// from TTree DecayTree/DecayTree
// found on file: /eos/lhcb/user/l/lgrillo/AsldRunITuples/SLB_ntuplesRunII_v1/Data2016_Strip28r1_MagUp.root
//////////////////////////////////////////////////////////

#ifndef DecayTree_h
#define DecayTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class DecayTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxB_ENDVERTEX_COV = 1;
   static constexpr Int_t kMaxB_OWNPV_COV = 1;
   static constexpr Int_t kMaxD_ENDVERTEX_COV = 1;
   static constexpr Int_t kMaxD_OWNPV_COV = 1;
   static constexpr Int_t kMaxD_ORIVX_COV = 1;

   // Declaration of leaf types
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

   // List of branches
   TBranch        *b_B_D_FD;   //!
   TBranch        *b_B_ETA;   //!
   TBranch        *b_B_ID;   //!
   TBranch        *b_B_M;   //!
   TBranch        *b_B_P;   //!
   TBranch        *b_B_PHI;   //!
   TBranch        *b_B_PT;   //!
   TBranch        *b_B_VCHI2NDOF;   //!
   TBranch        *b_B_ENDVERTEX_X;   //!
   TBranch        *b_B_ENDVERTEX_Y;   //!
   TBranch        *b_B_ENDVERTEX_Z;   //!
   TBranch        *b_B_ENDVERTEX_XERR;   //!
   TBranch        *b_B_ENDVERTEX_YERR;   //!
   TBranch        *b_B_ENDVERTEX_ZERR;   //!
   TBranch        *b_B_ENDVERTEX_CHI2;   //!
   TBranch        *b_B_ENDVERTEX_NDOF;   //!
   TBranch        *b_B_ENDVERTEX_COV_;   //!
   TBranch        *b_B_OWNPV_X;   //!
   TBranch        *b_B_OWNPV_Y;   //!
   TBranch        *b_B_OWNPV_Z;   //!
   TBranch        *b_B_OWNPV_XERR;   //!
   TBranch        *b_B_OWNPV_YERR;   //!
   TBranch        *b_B_OWNPV_ZERR;   //!
   TBranch        *b_B_OWNPV_CHI2;   //!
   TBranch        *b_B_OWNPV_NDOF;   //!
   TBranch        *b_B_OWNPV_COV_;   //!
   TBranch        *b_B_IP_OWNPV;   //!
   TBranch        *b_B_IPCHI2_OWNPV;   //!
   TBranch        *b_B_FD_OWNPV;   //!
   TBranch        *b_B_FDCHI2_OWNPV;   //!
   TBranch        *b_B_DIRA_OWNPV;   //!
   TBranch        *b_D_ETA;   //!
   TBranch        *b_D_ID;   //!
   TBranch        *b_D_IP;   //!
   TBranch        *b_D_IPCHI2;   //!
   TBranch        *b_D_M;   //!
   TBranch        *b_D_PHI;   //!
   TBranch        *b_D_PT;   //!
   TBranch        *b_D_VCHI2NDOF;   //!
   TBranch        *b_D_ENDVERTEX_X;   //!
   TBranch        *b_D_ENDVERTEX_Y;   //!
   TBranch        *b_D_ENDVERTEX_Z;   //!
   TBranch        *b_D_ENDVERTEX_XERR;   //!
   TBranch        *b_D_ENDVERTEX_YERR;   //!
   TBranch        *b_D_ENDVERTEX_ZERR;   //!
   TBranch        *b_D_ENDVERTEX_CHI2;   //!
   TBranch        *b_D_ENDVERTEX_NDOF;   //!
   TBranch        *b_D_ENDVERTEX_COV_;   //!
   TBranch        *b_D_OWNPV_X;   //!
   TBranch        *b_D_OWNPV_Y;   //!
   TBranch        *b_D_OWNPV_Z;   //!
   TBranch        *b_D_OWNPV_XERR;   //!
   TBranch        *b_D_OWNPV_YERR;   //!
   TBranch        *b_D_OWNPV_ZERR;   //!
   TBranch        *b_D_OWNPV_CHI2;   //!
   TBranch        *b_D_OWNPV_NDOF;   //!
   TBranch        *b_D_OWNPV_COV_;   //!
   TBranch        *b_D_IP_OWNPV;   //!
   TBranch        *b_D_IPCHI2_OWNPV;   //!
   TBranch        *b_D_FD_OWNPV;   //!
   TBranch        *b_D_FDCHI2_OWNPV;   //!
   TBranch        *b_D_DIRA_OWNPV;   //!
   TBranch        *b_D_ORIVX_X;   //!
   TBranch        *b_D_ORIVX_Y;   //!
   TBranch        *b_D_ORIVX_Z;   //!
   TBranch        *b_D_ORIVX_XERR;   //!
   TBranch        *b_D_ORIVX_YERR;   //!
   TBranch        *b_D_ORIVX_ZERR;   //!
   TBranch        *b_D_ORIVX_CHI2;   //!
   TBranch        *b_D_ORIVX_NDOF;   //!
   TBranch        *b_D_ORIVX_COV_;   //!
   TBranch        *b_D_FD_ORIVX;   //!
   TBranch        *b_D_FDCHI2_ORIVX;   //!
   TBranch        *b_D_DIRA_ORIVX;   //!
   TBranch        *b_K_ETA;   //!
   TBranch        *b_K_GHOSTPROB;   //!
   TBranch        *b_K_ID;   //!
   TBranch        *b_K_IP;   //!
   TBranch        *b_K_IPCHI2;   //!
   TBranch        *b_K_ISMUON;   //!
   TBranch        *b_K_PHI;   //!
   TBranch        *b_K_PIDK;   //!
   TBranch        *b_K_PIDmu;   //!
   TBranch        *b_K_PIDp;   //!
   TBranch        *b_K_PT;   //!
   TBranch        *b_Pi1_ETA;   //!
   TBranch        *b_Pi1_GHOSTPROB;   //!
   TBranch        *b_Pi1_ID;   //!
   TBranch        *b_Pi1_IP;   //!
   TBranch        *b_Pi1_IPCHI2;   //!
   TBranch        *b_Pi1_ISMUON;   //!
   TBranch        *b_Pi1_PHI;   //!
   TBranch        *b_Pi1_PIDK;   //!
   TBranch        *b_Pi1_PIDmu;   //!
   TBranch        *b_Pi1_PIDp;   //!
   TBranch        *b_Pi1_PT;   //!
   TBranch        *b_Pi2_ETA;   //!
   TBranch        *b_Pi2_GHOSTPROB;   //!
   TBranch        *b_Pi2_ID;   //!
   TBranch        *b_Pi2_IP;   //!
   TBranch        *b_Pi2_IPCHI2;   //!
   TBranch        *b_Pi2_ISMUON;   //!
   TBranch        *b_Pi2_PHI;   //!
   TBranch        *b_Pi2_PIDK;   //!
   TBranch        *b_Pi2_PIDmu;   //!
   TBranch        *b_Pi2_PIDp;   //!
   TBranch        *b_Pi2_PT;   //!
   TBranch        *b_Mu_ETA;   //!
   TBranch        *b_Mu_GHOSTPROB;   //!
   TBranch        *b_Mu_ID;   //!
   TBranch        *b_Mu_IP;   //!
   TBranch        *b_Mu_IPCHI2;   //!
   TBranch        *b_Mu_ISMUON;   //!
   TBranch        *b_Mu_PHI;   //!
   TBranch        *b_Mu_PIDK;   //!
   TBranch        *b_Mu_PIDmu;   //!
   TBranch        *b_Mu_PIDp;   //!
   TBranch        *b_Mu_PT;   //!
   TBranch        *b_nCandidate;   //!
   TBranch        *b_totCandidates;   //!
   TBranch        *b_EventInSequence;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_PVX;   //!
   TBranch        *b_PVY;   //!
   TBranch        *b_PVZ;   //!
   TBranch        *b_PVXERR;   //!
   TBranch        *b_PVYERR;   //!
   TBranch        *b_PVZERR;   //!
   TBranch        *b_PVCHI2;   //!
   TBranch        *b_PVNDOF;   //!
   TBranch        *b_PVNTRACKS;   //!

   DecayTree(TTree *tree=0);
   virtual ~DecayTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef DecayTree_cxx
DecayTree::DecayTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/lhcb/user/l/lgrillo/AsldRunITuples/SLB_ntuplesRunII_v1/Data2016_Strip28r1_MagUp.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/eos/lhcb/user/l/lgrillo/AsldRunITuples/SLB_ntuplesRunII_v1/Data2016_Strip28r1_MagUp.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/eos/lhcb/user/l/lgrillo/AsldRunITuples/SLB_ntuplesRunII_v1/Data2016_Strip28r1_MagUp.root:/b2DpMuX");
      dir->GetObject("DecayTree",tree);

   }
   Init(tree);
}

DecayTree::~DecayTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DecayTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DecayTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void DecayTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("B_D_FD", &B_D_FD, &b_B_D_FD);
   fChain->SetBranchAddress("B_ETA", &B_ETA, &b_B_ETA);
   fChain->SetBranchAddress("B_ID", &B_ID, &b_B_ID);
   fChain->SetBranchAddress("B_M", &B_M, &b_B_M);
   fChain->SetBranchAddress("B_P", &B_P, &b_B_P);
   fChain->SetBranchAddress("B_PHI", &B_PHI, &b_B_PHI);
   fChain->SetBranchAddress("B_PT", &B_PT, &b_B_PT);
   fChain->SetBranchAddress("B_VCHI2NDOF", &B_VCHI2NDOF, &b_B_VCHI2NDOF);
   fChain->SetBranchAddress("B_ENDVERTEX_X", &B_ENDVERTEX_X, &b_B_ENDVERTEX_X);
   fChain->SetBranchAddress("B_ENDVERTEX_Y", &B_ENDVERTEX_Y, &b_B_ENDVERTEX_Y);
   fChain->SetBranchAddress("B_ENDVERTEX_Z", &B_ENDVERTEX_Z, &b_B_ENDVERTEX_Z);
   fChain->SetBranchAddress("B_ENDVERTEX_XERR", &B_ENDVERTEX_XERR, &b_B_ENDVERTEX_XERR);
   fChain->SetBranchAddress("B_ENDVERTEX_YERR", &B_ENDVERTEX_YERR, &b_B_ENDVERTEX_YERR);
   fChain->SetBranchAddress("B_ENDVERTEX_ZERR", &B_ENDVERTEX_ZERR, &b_B_ENDVERTEX_ZERR);
   fChain->SetBranchAddress("B_ENDVERTEX_CHI2", &B_ENDVERTEX_CHI2, &b_B_ENDVERTEX_CHI2);
   fChain->SetBranchAddress("B_ENDVERTEX_NDOF", &B_ENDVERTEX_NDOF, &b_B_ENDVERTEX_NDOF);
   fChain->SetBranchAddress("B_ENDVERTEX_COV_", B_ENDVERTEX_COV_, &b_B_ENDVERTEX_COV_);
   fChain->SetBranchAddress("B_OWNPV_X", &B_OWNPV_X, &b_B_OWNPV_X);
   fChain->SetBranchAddress("B_OWNPV_Y", &B_OWNPV_Y, &b_B_OWNPV_Y);
   fChain->SetBranchAddress("B_OWNPV_Z", &B_OWNPV_Z, &b_B_OWNPV_Z);
   fChain->SetBranchAddress("B_OWNPV_XERR", &B_OWNPV_XERR, &b_B_OWNPV_XERR);
   fChain->SetBranchAddress("B_OWNPV_YERR", &B_OWNPV_YERR, &b_B_OWNPV_YERR);
   fChain->SetBranchAddress("B_OWNPV_ZERR", &B_OWNPV_ZERR, &b_B_OWNPV_ZERR);
   fChain->SetBranchAddress("B_OWNPV_CHI2", &B_OWNPV_CHI2, &b_B_OWNPV_CHI2);
   fChain->SetBranchAddress("B_OWNPV_NDOF", &B_OWNPV_NDOF, &b_B_OWNPV_NDOF);
   fChain->SetBranchAddress("B_OWNPV_COV_", B_OWNPV_COV_, &b_B_OWNPV_COV_);
   fChain->SetBranchAddress("B_IP_OWNPV", &B_IP_OWNPV, &b_B_IP_OWNPV);
   fChain->SetBranchAddress("B_IPCHI2_OWNPV", &B_IPCHI2_OWNPV, &b_B_IPCHI2_OWNPV);
   fChain->SetBranchAddress("B_FD_OWNPV", &B_FD_OWNPV, &b_B_FD_OWNPV);
   fChain->SetBranchAddress("B_FDCHI2_OWNPV", &B_FDCHI2_OWNPV, &b_B_FDCHI2_OWNPV);
   fChain->SetBranchAddress("B_DIRA_OWNPV", &B_DIRA_OWNPV, &b_B_DIRA_OWNPV);
   fChain->SetBranchAddress("D_ETA", &D_ETA, &b_D_ETA);
   fChain->SetBranchAddress("D_ID", &D_ID, &b_D_ID);
   fChain->SetBranchAddress("D_IP", &D_IP, &b_D_IP);
   fChain->SetBranchAddress("D_IPCHI2", &D_IPCHI2, &b_D_IPCHI2);
   fChain->SetBranchAddress("D_M", &D_M, &b_D_M);
   fChain->SetBranchAddress("D_PHI", &D_PHI, &b_D_PHI);
   fChain->SetBranchAddress("D_PT", &D_PT, &b_D_PT);
   fChain->SetBranchAddress("D_VCHI2NDOF", &D_VCHI2NDOF, &b_D_VCHI2NDOF);
   fChain->SetBranchAddress("D_ENDVERTEX_X", &D_ENDVERTEX_X, &b_D_ENDVERTEX_X);
   fChain->SetBranchAddress("D_ENDVERTEX_Y", &D_ENDVERTEX_Y, &b_D_ENDVERTEX_Y);
   fChain->SetBranchAddress("D_ENDVERTEX_Z", &D_ENDVERTEX_Z, &b_D_ENDVERTEX_Z);
   fChain->SetBranchAddress("D_ENDVERTEX_XERR", &D_ENDVERTEX_XERR, &b_D_ENDVERTEX_XERR);
   fChain->SetBranchAddress("D_ENDVERTEX_YERR", &D_ENDVERTEX_YERR, &b_D_ENDVERTEX_YERR);
   fChain->SetBranchAddress("D_ENDVERTEX_ZERR", &D_ENDVERTEX_ZERR, &b_D_ENDVERTEX_ZERR);
   fChain->SetBranchAddress("D_ENDVERTEX_CHI2", &D_ENDVERTEX_CHI2, &b_D_ENDVERTEX_CHI2);
   fChain->SetBranchAddress("D_ENDVERTEX_NDOF", &D_ENDVERTEX_NDOF, &b_D_ENDVERTEX_NDOF);
   fChain->SetBranchAddress("D_ENDVERTEX_COV_", D_ENDVERTEX_COV_, &b_D_ENDVERTEX_COV_);
   fChain->SetBranchAddress("D_OWNPV_X", &D_OWNPV_X, &b_D_OWNPV_X);
   fChain->SetBranchAddress("D_OWNPV_Y", &D_OWNPV_Y, &b_D_OWNPV_Y);
   fChain->SetBranchAddress("D_OWNPV_Z", &D_OWNPV_Z, &b_D_OWNPV_Z);
   fChain->SetBranchAddress("D_OWNPV_XERR", &D_OWNPV_XERR, &b_D_OWNPV_XERR);
   fChain->SetBranchAddress("D_OWNPV_YERR", &D_OWNPV_YERR, &b_D_OWNPV_YERR);
   fChain->SetBranchAddress("D_OWNPV_ZERR", &D_OWNPV_ZERR, &b_D_OWNPV_ZERR);
   fChain->SetBranchAddress("D_OWNPV_CHI2", &D_OWNPV_CHI2, &b_D_OWNPV_CHI2);
   fChain->SetBranchAddress("D_OWNPV_NDOF", &D_OWNPV_NDOF, &b_D_OWNPV_NDOF);
   fChain->SetBranchAddress("D_OWNPV_COV_", D_OWNPV_COV_, &b_D_OWNPV_COV_);
   fChain->SetBranchAddress("D_IP_OWNPV", &D_IP_OWNPV, &b_D_IP_OWNPV);
   fChain->SetBranchAddress("D_IPCHI2_OWNPV", &D_IPCHI2_OWNPV, &b_D_IPCHI2_OWNPV);
   fChain->SetBranchAddress("D_FD_OWNPV", &D_FD_OWNPV, &b_D_FD_OWNPV);
   fChain->SetBranchAddress("D_FDCHI2_OWNPV", &D_FDCHI2_OWNPV, &b_D_FDCHI2_OWNPV);
   fChain->SetBranchAddress("D_DIRA_OWNPV", &D_DIRA_OWNPV, &b_D_DIRA_OWNPV);
   fChain->SetBranchAddress("D_ORIVX_X", &D_ORIVX_X, &b_D_ORIVX_X);
   fChain->SetBranchAddress("D_ORIVX_Y", &D_ORIVX_Y, &b_D_ORIVX_Y);
   fChain->SetBranchAddress("D_ORIVX_Z", &D_ORIVX_Z, &b_D_ORIVX_Z);
   fChain->SetBranchAddress("D_ORIVX_XERR", &D_ORIVX_XERR, &b_D_ORIVX_XERR);
   fChain->SetBranchAddress("D_ORIVX_YERR", &D_ORIVX_YERR, &b_D_ORIVX_YERR);
   fChain->SetBranchAddress("D_ORIVX_ZERR", &D_ORIVX_ZERR, &b_D_ORIVX_ZERR);
   fChain->SetBranchAddress("D_ORIVX_CHI2", &D_ORIVX_CHI2, &b_D_ORIVX_CHI2);
   fChain->SetBranchAddress("D_ORIVX_NDOF", &D_ORIVX_NDOF, &b_D_ORIVX_NDOF);
   fChain->SetBranchAddress("D_ORIVX_COV_", D_ORIVX_COV_, &b_D_ORIVX_COV_);
   fChain->SetBranchAddress("D_FD_ORIVX", &D_FD_ORIVX, &b_D_FD_ORIVX);
   fChain->SetBranchAddress("D_FDCHI2_ORIVX", &D_FDCHI2_ORIVX, &b_D_FDCHI2_ORIVX);
   fChain->SetBranchAddress("D_DIRA_ORIVX", &D_DIRA_ORIVX, &b_D_DIRA_ORIVX);
   fChain->SetBranchAddress("K_ETA", &K_ETA, &b_K_ETA);
   fChain->SetBranchAddress("K_GHOSTPROB", &K_GHOSTPROB, &b_K_GHOSTPROB);
   fChain->SetBranchAddress("K_ID", &K_ID, &b_K_ID);
   fChain->SetBranchAddress("K_IP", &K_IP, &b_K_IP);
   fChain->SetBranchAddress("K_IPCHI2", &K_IPCHI2, &b_K_IPCHI2);
   fChain->SetBranchAddress("K_ISMUON", &K_ISMUON, &b_K_ISMUON);
   fChain->SetBranchAddress("K_PHI", &K_PHI, &b_K_PHI);
   fChain->SetBranchAddress("K_PIDK", &K_PIDK, &b_K_PIDK);
   fChain->SetBranchAddress("K_PIDmu", &K_PIDmu, &b_K_PIDmu);
   fChain->SetBranchAddress("K_PIDp", &K_PIDp, &b_K_PIDp);
   fChain->SetBranchAddress("K_PT", &K_PT, &b_K_PT);
   fChain->SetBranchAddress("Pi1_ETA", &Pi1_ETA, &b_Pi1_ETA);
   fChain->SetBranchAddress("Pi1_GHOSTPROB", &Pi1_GHOSTPROB, &b_Pi1_GHOSTPROB);
   fChain->SetBranchAddress("Pi1_ID", &Pi1_ID, &b_Pi1_ID);
   fChain->SetBranchAddress("Pi1_IP", &Pi1_IP, &b_Pi1_IP);
   fChain->SetBranchAddress("Pi1_IPCHI2", &Pi1_IPCHI2, &b_Pi1_IPCHI2);
   fChain->SetBranchAddress("Pi1_ISMUON", &Pi1_ISMUON, &b_Pi1_ISMUON);
   fChain->SetBranchAddress("Pi1_PHI", &Pi1_PHI, &b_Pi1_PHI);
   fChain->SetBranchAddress("Pi1_PIDK", &Pi1_PIDK, &b_Pi1_PIDK);
   fChain->SetBranchAddress("Pi1_PIDmu", &Pi1_PIDmu, &b_Pi1_PIDmu);
   fChain->SetBranchAddress("Pi1_PIDp", &Pi1_PIDp, &b_Pi1_PIDp);
   fChain->SetBranchAddress("Pi1_PT", &Pi1_PT, &b_Pi1_PT);
   fChain->SetBranchAddress("Pi2_ETA", &Pi2_ETA, &b_Pi2_ETA);
   fChain->SetBranchAddress("Pi2_GHOSTPROB", &Pi2_GHOSTPROB, &b_Pi2_GHOSTPROB);
   fChain->SetBranchAddress("Pi2_ID", &Pi2_ID, &b_Pi2_ID);
   fChain->SetBranchAddress("Pi2_IP", &Pi2_IP, &b_Pi2_IP);
   fChain->SetBranchAddress("Pi2_IPCHI2", &Pi2_IPCHI2, &b_Pi2_IPCHI2);
   fChain->SetBranchAddress("Pi2_ISMUON", &Pi2_ISMUON, &b_Pi2_ISMUON);
   fChain->SetBranchAddress("Pi2_PHI", &Pi2_PHI, &b_Pi2_PHI);
   fChain->SetBranchAddress("Pi2_PIDK", &Pi2_PIDK, &b_Pi2_PIDK);
   fChain->SetBranchAddress("Pi2_PIDmu", &Pi2_PIDmu, &b_Pi2_PIDmu);
   fChain->SetBranchAddress("Pi2_PIDp", &Pi2_PIDp, &b_Pi2_PIDp);
   fChain->SetBranchAddress("Pi2_PT", &Pi2_PT, &b_Pi2_PT);
   fChain->SetBranchAddress("Mu_ETA", &Mu_ETA, &b_Mu_ETA);
   fChain->SetBranchAddress("Mu_GHOSTPROB", &Mu_GHOSTPROB, &b_Mu_GHOSTPROB);
   fChain->SetBranchAddress("Mu_ID", &Mu_ID, &b_Mu_ID);
   fChain->SetBranchAddress("Mu_IP", &Mu_IP, &b_Mu_IP);
   fChain->SetBranchAddress("Mu_IPCHI2", &Mu_IPCHI2, &b_Mu_IPCHI2);
   fChain->SetBranchAddress("Mu_ISMUON", &Mu_ISMUON, &b_Mu_ISMUON);
   fChain->SetBranchAddress("Mu_PHI", &Mu_PHI, &b_Mu_PHI);
   fChain->SetBranchAddress("Mu_PIDK", &Mu_PIDK, &b_Mu_PIDK);
   fChain->SetBranchAddress("Mu_PIDmu", &Mu_PIDmu, &b_Mu_PIDmu);
   fChain->SetBranchAddress("Mu_PIDp", &Mu_PIDp, &b_Mu_PIDp);
   fChain->SetBranchAddress("Mu_PT", &Mu_PT, &b_Mu_PT);
   fChain->SetBranchAddress("nCandidate", &nCandidate, &b_nCandidate);
   fChain->SetBranchAddress("totCandidates", &totCandidates, &b_totCandidates);
   fChain->SetBranchAddress("EventInSequence", &EventInSequence, &b_EventInSequence);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("PVX", PVX, &b_PVX);
   fChain->SetBranchAddress("PVY", PVY, &b_PVY);
   fChain->SetBranchAddress("PVZ", PVZ, &b_PVZ);
   fChain->SetBranchAddress("PVXERR", PVXERR, &b_PVXERR);
   fChain->SetBranchAddress("PVYERR", PVYERR, &b_PVYERR);
   fChain->SetBranchAddress("PVZERR", PVZERR, &b_PVZERR);
   fChain->SetBranchAddress("PVCHI2", PVCHI2, &b_PVCHI2);
   fChain->SetBranchAddress("PVNDOF", PVNDOF, &b_PVNDOF);
   fChain->SetBranchAddress("PVNTRACKS", PVNTRACKS, &b_PVNTRACKS);
   Notify();
}

Bool_t DecayTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DecayTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DecayTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef DecayTree_cxx
