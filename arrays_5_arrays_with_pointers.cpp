#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void passTest(int a[3][5]);

 main()
{
 /*
  int luckyNumbers[5] = {2,3,5,7,9};
  cout << luckyNumbers << endl;     // returns first element Address
  cout << &luckyNumbers[0] << endl; // returns first element Address
  cout << luckyNumbers[2] << endl;  // returns 5
  cout << *(luckyNumbers + 2) << endl;  // returns 5

  int luckyNumber2[5];

  for(int i = 0; i <= 4; i++){ //input numbers into array
    cout << "Number: ";
    cin >> luckyNumber2[i];
  }

  for(int i = 0; i <= 4; i++){ // display inputed numbers
    cout << *(luckyNumber2+i)<< " ";
  }
*/


  int arrMul[3][5] = {
    {12,21,454,45,0},
    {9,89,67,78,889},
    {9219,0,1,2,90}
  };



  int array[10][10];

  passTest(arrMul);


  system("pause>0");
  return 0;
}


void passTest(int a[3][5]){
  cout << a[2][4];
}
