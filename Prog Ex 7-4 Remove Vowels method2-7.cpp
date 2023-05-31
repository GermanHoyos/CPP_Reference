#include <iostream>
#include <string>

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
            if (scan == target1){ cout << "'a' found at index # " << i <<  endl;}
            if (scan == target2){ cout << "'A' found at index # " << i <<  endl;}
            if (scan == target3){ cout << "'e' found at index # " << i <<  endl;}
            if (scan == target4){ cout << "'E' found at index # " << i <<  endl;}
            if (scan == target5){ cout << "'i' found at index # " << i <<  endl;}
            if (scan == target6){ cout << "'I' found at index # " << i <<  endl;}
            if (scan == target7){ cout << "'o' found at index # " << i <<  endl;}
            if (scan == target8){ cout << "'O' found at index # " << i <<  endl;}
            if (scan == target9){ cout << "'u' found at index # " << i <<  endl;}
            if (scan == target10){ cout << "'U' found at index # " << i << endl;}
     } return usrInp;
}

//Per cengage: "...  a function to remove all the vowels"
string removeV(string transfer){
    for (int i = 0; i < transfer.length(); i++){
        scan = transfer[i];
            if (scan == target1){  transfer.erase(i,1);} //erase index location [i], exactly "1" char
            if (scan == target2){  transfer.erase(i,1);}
            if (scan == target3){  transfer.erase(i,1);}
            if (scan == target4){  transfer.erase(i,1);}
            if (scan == target5){  transfer.erase(i,1);}
            if (scan == target6){  transfer.erase(i,1);}
            if (scan == target7){  transfer.erase(i,1);}
            if (scan == target8){  transfer.erase(i,1);}
            if (scan == target9){  transfer.erase(i,1);}
            if (scan == target10){ transfer.erase(i,1);}
     } newStr = transfer.substr(0, transfer.length()); // assign to newStr the erased/fully scanned previous string called "transfer"
       return newStr;
}

int main() {
    cout << "String: ";
    getline (cin, usrInp);
    transfer = determine(usrInp);
    newStr = removeV(transfer);
    cout << newStr;
}
//Using the two functions like above is highly inefficient, see below:
/*
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    string usrStr;
    getline (cin, usrStr);
    cout << endl;

for (char c : usrStr){
     if ( c != 'a' && c != 'A' &&
          c != 'e' && c != 'E' &&
          c != 'i' && c != 'I' &&
          c != 'o' && c != 'O' &&
          c != 'u' && c != 'U' ) {
          cout << "[" << c << "]";
     }
}
cout << '\n';

return 0;
}



*/
