#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <queue>
using namespace std;

    string usrInp;
    string scan;
    string newStr;
    string transfer;

    string target1 = "a", target2 ="A",
           target3 = "e", target4 ="E",
           target5 = "i", target6 ="I",
           target7 = "o", target8 ="O",
           target9 = "U", target10 ="U";

//Per cengage: "... a function to determine whether a character is a vowel."
string determine(string usrInp){
    for (int i = 0; i < usrInp.length(); i++){
        scan = usrInp[i];
            if (scan == target1){ cout << "'a' found at index # " << i << endl; usrInp.erase(i,1);}
            if (scan == target2){ cout << "'A' found at index # " << i << endl; usrInp.erase(i,1);}
            if (scan == target3){ cout << "'e' found at index # " << i << endl; usrInp.erase(i,1);}
            if (scan == target4){ cout << "'E' found at index # " << i << endl; usrInp.erase(i,1);}
            if (scan == target5){ cout << "'i' found at index # " << i << endl; usrInp.erase(i,1);}
            if (scan == target6){ cout << "'I' found at index # " << i << endl; usrInp.erase(i,1);}
            if (scan == target7){ cout << "'o' found at index # " << i << endl; usrInp.erase(i,1);}
            if (scan == target8){ cout << "'O' found at index # " << i << endl; usrInp.erase(i,1);}
            if (scan == target9){ cout << "'u' found at index # " << i << endl; usrInp.erase(i,1);}
            if (scan == target10){ cout << "'U' found at index # " << i << endl; usrInp.erase(i,1);}
     } return usrInp;
}

//Per cengage: "...  a function to remove all the vowels"
string removeV(string transfer){
    newStr = transfer;
    cout << newStr;
}

int main() {
    cout << "String: ";
    getline (cin, usrInp);
    transfer = determine(usrInp);
    removeV(transfer);
}

