#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void printNumber(int*numberPtr){
  cout << *numberPtr << endl;
}

void printLetter(char*printLetter){
  cout << *printLetter << endl;
}

void print(void* ptr, char type){ // type is just for keeping track
  switch(type){
    case 'i': cout<< *((int*)ptr) << endl; break; //prints value of int pointer
    case 'c': cout<< *((char*)ptr)<< endl; break;//prints value of char pointer
  }
}

int main()
{
  int number = 5;
  char letter ='a';
  // printNumber(&number);
  // printLetter(&letter);
  print(&number, 'i');
  print(&letter, 'c');

  system("pause>0");
  return 0;
}
