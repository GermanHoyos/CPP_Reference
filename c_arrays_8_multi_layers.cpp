#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

 int main() // see excell doc (array_8_multi_layers)
{
  int rows, cols;
  cout << "rows, cols:"<< endl;
  cin >> rows >> cols;

  //int pointer to pointer = table
  // = create new int array of pointers with [rows]
  int** table = new int*[rows];

  //for each element create a seperate dynamic array
  for (int i = 0; i < rows; i++){
    table[i] = new int[cols];
    //"table[1] = row 1 // table[2] = row[2]"
    //"table[1][1] = row 1 column 1 // table[1][2] = row 1 column 2"
  }

  //table row 1 column 2 will have 88 as value
  table[1][2] = 88;

  //deAllocate memory
  for (int i = 0; i < rows; i++){
    delete[] table[i];
  }

  delete[] table;
  table = NULL;


  system("pause>0");
  return 0;
}
