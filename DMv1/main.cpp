#include "header.h"
#include <iostream>
#include <string>

using namespace std;
int main(int argc, char** argv){
  
  std::string filenameFit = DecreaseTreeSizeAndCuts(argv[1], argv[2], argv[3]); // First input is filename, second is directory name
  cout << filenameFit;
  return 0;
}
