#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


 int main()
{
  int size;
  cout << "Size: ";
  cin >> size; //<- int myArray[5];

  //Address of first element is stored in myArray pointer
  int * myArray = new int [size];

  for(int i = 0; i < size; i++){
    cout << "Array[" << i << "] ";
    cin >> myArray[i];
  }

  for(int i = 0; i < size; i++){
    cout << myArray[i]<<" ";
  }


  system("pause>0");
  return 0;
}
