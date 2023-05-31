#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
  string usrInpt;
  cin >> usrInpt;

  for (char range : usrInpt){
    if ( range == 'a' || range == 'A' ||
         range == 'e' || range == 'E' ||
         range == 'i' || range == 'I' ||
         range == 'o' || range == 'O' ||
         range == 'u' || range == 'U' ) {
        cout << true;
    } else {
        cout << false;
    }
  }

return 0;
}
