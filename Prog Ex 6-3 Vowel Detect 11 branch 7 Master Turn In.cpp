#include <iostream>
#include <string>
using namespace std;

bool isVowel(char range);

int main() {
  string usrInpt;
  int vwlCnt = 0;
  bool x;

  getline (cin, usrInpt);

//iterate over all the elements in range
//for (delcaration : range){statement};
  for (char range : usrInpt){
    x = isVowel(range);
    if (x == true){
        vwlCnt++;
    }
  }

 cout << vwlCnt << " vowels in this sentence." << endl;

 return 0;
}

 bool isVowel(char range){
    if ( range == 'a' || range == 'A' ||
         range == 'e' || range == 'E' ||
         range == 'i' || range == 'I' ||
         range == 'o' || range == 'O' ||
         range == 'u' || range == 'U' ) {
        return true;
    } else {
        return false;
    };
}
