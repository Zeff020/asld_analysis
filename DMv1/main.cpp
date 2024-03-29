#include "header.h"
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;
int main(int argc, char** argv){
  /* 

     
     First input is filename, second is directory name, third is size by which it is decreased. Do 1 for no decrease in size. The fourth argument determines what operations you want to do on the dataset, for only the cuts and correcting the B mass use "b" and for everything use "a". Use option b for monte carlo samples.


   */
  char* samesign = argv[2];
  std::string filenameCuts_s;
  const char* filenameCuts;
  std::string filenameDMhist_s;
  const char* filenameDMhist;
  std::string filenamesweights_s;
  std::string filenameCutsBCorr_s;
  const char* filenameCutsBCorr;
  std::string filenameCutsBCorrDbkg;
  
  int choice = static_cast <int> (*argv[4]);
  switch (choice){
  
 case 97:
  filenameCuts_s = DecreaseTreeSizeAndCuts(argv[1], argv[2], argv[3]); // First input is filename, second is directory name, third is size by which it is decreased. Do 0 for no decrease in size.
  
  filenameCuts = filenameCuts_s.c_str();
  
  filenameDMhist_s = DmHist(filenameCuts); // Generate histogram for D mass to make it easier to handle

  filenameDMhist = filenameDMhist_s.c_str();
  
  filenamesweights_s = Fit(filenameDMhist,filenameCuts);

  filenameCutsBCorr_s = Bcm(filenameCuts, argv[2]); // Generate B corrected mass and add it to TTree

  filenameCutsBCorr = filenameCutsBCorr_s.c_str();

  filenameCutsBCorrDbkg = ExtractDBkg(filenameCutsBCorr);

  cout << "Produced final files with names: " << endl << filenameCutsBCorrDbkg << " for the file with the sideband D mass data in terms of B mass" << endl << filenameCutsBCorr << " for the file with B corrected mass" << endl << filenameDMhist << " for the file with the D mass histogram" << endl << filenamesweights_s << "For the file with the sweights" << endl;

  remove(filenameCuts);
  break;
 case 98:

  filenameCuts_s = DecreaseTreeSizeAndCuts(argv[1], argv[2], argv[3]); // First input is filename, second is directory name, thiid is size by which it is decreased. Do 0 for no decrease in size.
  
  filenameCuts = filenameCuts_s.c_str();

  
  filenameCutsBCorr_s = Bcm(filenameCuts, argv[2]); // Generate B corrected mass and add it to TTree

  filenameCutsBCorr = filenameCutsBCorr_s.c_str();
  
  cout << "Produced final file with name: " << filenameCutsBCorr << endl;
  remove(filenameCuts);
  break;
 default :

   cout << "Program is done running";
  }
  return 0;

}
