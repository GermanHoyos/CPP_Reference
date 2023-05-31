#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

bool isVowel(char range){
    if ( range == 'a' || range == 'A' ||
         range == 'e' || range == 'E' ||
         range == 'i' || range == 'I' ||
         range == 'o' || range == 'O' ||
         range == 'u' || range == 'U' ) {
        cout << true;  //1
    } else {
        cout << false; //0
    }
}

int main() {
  string usrInpt;
  cin >> usrInpt;
  bool x;

  for (char range : usrInpt){
    x = isVowel(range);
  }

return 0;
}
