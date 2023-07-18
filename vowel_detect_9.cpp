#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int isVowel(string param){
    int r = 0;
        for (char range : param){
            if ( range == 'a' || range == 'A' ||
                 range == 'e' || range == 'E' ||
                 range == 'i' || range == 'I' ||
                 range == 'o' || range == 'O' ||
                 range == 'u' || range == 'U' ) {
                 r++;
                }
        }
    return r;
}

int main() {

    int vCount;
    string usrInp;

    getline (cin, usrInp);

    vCount = isVowel (usrInp);

    cout << vCount;

return 0;
}

