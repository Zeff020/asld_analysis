#include "header.h"
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;
int main(int argc, char** argv){
  /* 

     
     First input is filename, second is directory name, third is size by which it is decreased. Do 1 for no decrease in size.


   */
  
  std::string filenameCuts_s = DecreaseTreeSizeAndCuts(argv[1], argv[2], argv[3]); // First input is filename, second is directory name, thiid is size by which it is decreased. Do 0 for no decrease in size.
  
  const char* filenameCuts = filenameCuts_s.c_str();
  
  std::string filenameDMhist_s = DmHist(filenameCuts); // Generate histogram for D mass to make it easier to handle

  const char* filenameDMhist = filenameDMhist_s.c_str();
  
  std::string filenamesweights_s = Fit(filenameDMhist,filenameCuts);

  std::string filenameCutsBCorr_s = Bcm(filenameCuts); // Generate B corrected mass and add it to TTree

  const char* filenameCutsBCorr = filenameCutsBCorr_s.c_str();

  std::string filenameCutsBcorrDbkg = ExtractDBkg(filenameCutsBCorr);

  
  
  return 0;

}
