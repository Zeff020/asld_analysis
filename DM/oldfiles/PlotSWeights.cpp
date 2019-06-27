/*


In this file I try to plot the SWeights but it doesn't work yet.


 */


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

void PlotSWeights(){
   TFile *f = new TFile("../../data/Data2016_Strip28r1_MagUpsmall300withcutssweights.root");
   TTree *tr = (TTree*)f->Get("DecayTree");

   Double_t         D_M;
   Float_t	    nsig_sw;
   Float_t          nbkg_sw;



   tr -> SetBranchAddress("D_M",&D_M);
   tr -> SetBranchAddress("nsig_sw",&nsig_sw);
   tr -> SetBranchAddress("nbkg_sw",&nbkg_sw);


   RooRealVar *mD = new RooRealVar("D_M","mass D",1800, 1980,"MeV");
   RooRealVar *nsig_ = new RooRealVar("nsig_sw","mass D",-1, 2,"MeV");

   TCanvas* canvas = new TCanvas("Sweights","Sweights");
   RooPlot* frame = nsig_ -> frame();


   RooDataSet * data = new RooDataSet("fitData","fit input dataset",tr,RooArgList(*mD));
   RooDataSet * nsig = new RooDataSet("sig","fit input dataset",tr,RooArgList(*nsig_));
   RooDataSet * nbkg = new RooDataSet("nbkg","fit input dataset",tr,RooArgList(*mD));
   
   nsig -> plotOnXY(frame);

   frame -> Draw();
   
   

   
   

}
