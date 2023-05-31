#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <queue>
using namespace std;

string usrStr;
string newStr;
int enumV = 0;
int usrStrLngth;

//Enumerate where V's are
string determineV(string usrStr){
    for (char c : usrStr){
    usrStrLngth = usrStr.length();
     if ( c == 'a' || c == 'A' ||
          c == 'e' || c == 'E' ||
          c == 'i' || c == 'I' ||
          c == 'o' || c == 'O' ||
          c == 'u' || c == 'U' ) {
          cout << "[" << c << "]";
        }
    }
}

//Remove Enumerated V's with 'erase'
string removeV(string usrStr, int enumV){

}

int main() {
    getline (cin, usrStr);
    cout << endl;

    newStr = determineV(usrStr);
    //cout << newStr;

return 0;
}
