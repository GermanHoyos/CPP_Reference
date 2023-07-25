#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void passTest(int arrMul[3][5]);

main()
{

  int arrMul[3][5] = {
    {12,21,454,45,0},
    {9,89,67,78,889},
    {9219,0,1,2,90}
  };

  passTest(arrMul);

  system("pause>0");
  return 0;
}

void passTest(int arrMul[3][5]){
  cout << arrMul[2][4];
}
