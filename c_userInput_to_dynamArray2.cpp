#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
  string usrInput;
  int size;

  cout << "Size: ";
  cin >> size; cout << endl;
  cout << "Input: ";
  cin >> usrInput; cout << endl;

  char * myArray = new char [size];

  for(int i = 0; i < size; i++){
    myArray[i] = usrInput[i];
  }

  for(int i = 0; i < size; i++){
    cout << static_cast<char>(toupper(myArray[i]));
  }

  return 0;
}
