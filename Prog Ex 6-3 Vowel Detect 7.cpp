#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;


int main() {

    string strVar;
    int cntVowls = 0;

    getline (cin, strVar);

    for (char range : strVar){
            if ( range == 'a' || range == 'A' ||
                 range == 'e' || range == 'E' ||
                 range == 'i' || range == 'I' ||
                 range == 'o' || range == 'O' ||
                 range == 'u' || range == 'U' ) {
                 cntVowls++;
            }
    }

    cout << cntVowls;

return 0;
}
