#include <iostream>
#include "AidaTT.hh"
#include "ConstantSolenoidBField.hh"


using namespace std;
//using namespace aidaTT;

int main()
{

  aidaTT::AidaTT *a = new aidaTT::AidaTT();
  
  aidaTT::ConstantSolenoidBField b(3.4);
  
  vector<double> anywhere;
  anywhere.resize(3);
  anywhere.push_back(0.);
  anywhere.push_back(0.);
  anywhere.push_back(0.);
  
}