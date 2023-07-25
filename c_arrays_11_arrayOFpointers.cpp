#include <iostream>
#include <string>
using namespace std;

int main() {
string strArray[3] = {"stringOne", "stringTwo", "stringThree"};

for (int i = 0; i < 3; i++){
        cout << &strArray[i] << ": " << strArray[i] << endl;
};      cout << endl;

string * pStr = strArray;

pStr[0] = "changedOne";
pStr[1] = "changedTwo";
pStr[2] = "changedTre";

for (int i = 0; i < 3; i++){
        cout << &strArray[i] << ": " << strArray[i] << endl;
};      cout << endl;

string ptrArray[3] = {pStr[0],pStr[1],pStr[2]};

for (int i = 0; i < 3; i++) {
    cout << "ptrArray[" << i << "]: " << ptrArray[i] << endl;
}   cout << endl;

string * p = &strArray[0];
cout << p << endl;

string arryA[1] = {*p};
cout << arryA[1];
 return 0;
}


