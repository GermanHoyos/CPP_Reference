#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


bool sortBool(int a, int b){
  return b > a;
}

int main() {

  bool larger = false;

  int sortMe[20] = {21,20,20,5,6,8,9,21,45,12,1,34,1,1,67,90,99,6,5,2};

  larger = sortBool(sortMe[0], sortMe[1]);

  for(int a = 0; a < 20; a++){
    for(int b = a; b < 20; b++){
      cout << "Compare: " << sortMe[a] << " to " << sortMe[b] << endl;
    }
  }

  if (larger == 1){
    cout << "true";
  } else {
    cout << "false";
  }






  return 0;
}
