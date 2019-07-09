#include <iostream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atof */
#include <math.h>       /* sin */
using namespace std;

int main(int argc, char **argv){
  /* First argument is hadronization fraction, Second argument is generator level efficiencies, Third argument is cut efficiencies */
  double HadronFrac = atof( argv[1] );
  double GenEff = atof( argv[2] );
  double CutEff = atof( argv[2] );


  double Nbkg = HadronFrac * GenEff * CutEff;

};
