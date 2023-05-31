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
