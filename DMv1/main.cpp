#include "header.h"
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;
int main(int argc, char** argv){
  /* First input is filename, second is directory name, third is size by which it is decreased. Do 1 for no decrease in size.


   */
  
  std::string filenameCuts_s = DecreaseTreeSizeAndCuts(argv[1], argv[2], argv[3]); // First input is filename, second is directory name, thiid is size by which it is decreased. Do 0 for no decrease in size.
  
  const char* filenameCuts = filenameCuts_s.c_str();
  
  std::string filenameDMhist_s = DmHist(filenameCuts);

  const char* filenameDMhist = filenameDMhist_s.c_str();
  
  cout << "Filename before function" << filenameDMhist << endl;
  cout << "Type of filename before function" << typeid(filenameDMhist).name()<<endl;
  std::string filenameDFit = Fit(filenameDMhist);
  
  return 0;

}
