#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
  string usrInput;

  cout << "Input: ";
  cin >> usrInput;

  int size = usrInput.length();

  char * myArray = new char [size];

  for(int i = 0; i < size; i++){
    myArray[i] = usrInput[i];
  }

  for(int i = 0; i < size; i++){
    cout << static_cast<char>(toupper(myArray[i]));
  }

  return 0;
}

/*
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
  int size;
  string usrInput;

  cout << "Input: ";
  cin >> usrInput;

  size = usrInput.length();

  char * myArray = new char [size];

  for(int i = 0; i < size; i++){
    myArray[i] = usrInput[i];
  }

  for(int i = 0; i < size; i++){
       cout << static_cast<char>(toupper(myArray[i]));
  }

  return 0;
}
*/
