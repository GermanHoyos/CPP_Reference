#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
// "f5" to run in atom editor

int main()
{
  int myArry[3] = {2,3,1};

  for(int i = 0; i < 3; i++) {
    cout << myArry[i];
  }

  cout << endl;

  for(int i = 2; i >= 0; i--) {
    cout << myArry[i];
  }

  system("pause>0");
}
