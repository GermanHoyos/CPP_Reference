#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;



int main() {

  string stringSort[10] = {"1","4","76","71","92","24","46","67","9","12"};
  string tempA, tempB;
  int    intA,  intB;

  for(int a = 0; a < 10; a++){
    for(int b = a; b < 10; b++){
        istringstream(stringSort[a]) >> intA;
        istringstream(stringSort[b]) >> intB;
        if(intB > intA){ //compare operator can be used for int data type
          tempA = stringSort[a];
          tempB = stringSort[b];
          stringSort[a] = tempB;
          stringSort[b] = tempA;
        }
      }
    }

  for(int i = 0; i < 10; i++){
    cout << stringSort[i] << endl;
  }

  return 0;
}

























// for(int i = 0; i < 10; i++){
//   cout << stringSort[i] << endl;
// }
