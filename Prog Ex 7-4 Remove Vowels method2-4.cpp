#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <queue>
using namespace std;

int main() {

    string usrInp = "find all my vowels at once!";
    string scan;
    string newStr;

    string target1 = "a", target2 ="A",
           target3 = "e", target4 ="E",
           target5 = "i", target6 ="I",
           target7 = "o", target8 ="O",
           target9 = "U", target10 ="U";

    cout << usrInp << endl << endl;

    for (int i = 0; i < usrInp.length(); i++){
        scan = usrInp[i];
            if (scan == target1){
                cout << "'a' found at: " << i << endl;
                    usrInp.erase(i,1);
            }           newStr = usrInp.substr(0,usrInp.length());
    }
    cout << endl;
    cout << usrInp << endl;
    cout << "New String = " << newStr;


}









//[0,1,2,3,etc...]
//manipulating strings
//https://www.cplusplus.com/reference/string/string/substr/
//dynamic memory
//https://www.cplusplus.com/doc/tutorial/dynamic/
