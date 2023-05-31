#include <iostream>
#include <string>
using namespace std;

bool isVowel(char range){
    if ( range == 'a' || range == 'A' ||
         range == 'e' || range == 'E' ||
         range == 'i' || range == 'I' ||
         range == 'o' || range == 'O' ||
         range == 'u' || range == 'U' ) {
        return true;
    } else {
        return false;
    }
}

int main() {
  string usrInpt;
  int vwlCnt;
  bool x;

  getline (cin, usrInpt);

  for (char range : usrInpt){
    x = isVowel(range);
    if (x == true){
        vwlCnt++;
    }
  }

  cout << vwlCnt << " vowels in this sentence" << endl;

return 0;
}
