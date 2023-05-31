#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

//function pointer: stores the address of a function

//CASE 1
int getNumber(){ // no param function
  return 5;
}

//CASE 2
int add(int a, int b){
  return a + b;
}

//CASE 3
bool ascendingCompare(int a, int b){
    return a < b;
}
bool descendingCompare(int a, int b){
    return a > b;
}
void sortAscedning(vector<int>& numbersVector)
{
  for (int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
  {
    int bestIndex = startIndex;

      for(int currentIndex = startIndex +1; currentIndex < numbersVector.size(); currentIndex++)
      {
          //We are doing comparison here
          if(ascendingCompare(numbersVector[currentIndex], numbersVector[bestIndex]))
            bestIndex = currentIndex;
      }
      swap(numbersVector[startIndex], numbersVector[bestIndex]);
  }
}
void sortDescending(vector<int>& numbersVector)
{
  for (int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
  {
    int bestIndex = startIndex;

      for(int currentIndex = startIndex +1; currentIndex < numbersVector.size(); currentIndex++)
      {
          //We are doing comparison here
          if(descendingCompare(numbersVector[currentIndex], numbersVector[bestIndex]))
            bestIndex = currentIndex;
      }
      swap(numbersVector[startIndex], numbersVector[bestIndex]);
  }
}
void customSort(vector<int>& numbersVector,bool(*compareFuncPtr)(int, int))
{
  for (int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
  {
    int bestIndex = startIndex;

      for(int currentIndex = startIndex +1; currentIndex < numbersVector.size(); currentIndex++)
      {
          //pointer (*compareFuncPtr) can call iether ascending or descending compares
          if(compareFuncPtr(numbersVector[currentIndex], numbersVector[bestIndex]))
            bestIndex = currentIndex;
      }
      swap(numbersVector[startIndex], numbersVector[bestIndex]);
  }
}
void printNumbers(vector<int>& numbersVector){
  for (int i = 0; i < numbersVector.size(); i++)
    cout << numbersVector[i] << ' ';
}



 int main()
{

//normal call to get return value
//cout << getNumber();

//CASE 1
cout << "case 1: " << endl;
//function pointer to point to address of a function
int(*funcPtr)() = getNumber;

cout <<"ptr 1: " << funcPtr() << endl; //returns the value of the func return

//CASE 2
cout << "case 2: " << endl;
//function pointer to point to address of a function with params
int(*antrPtr)(int, int) = add;
cout <<"ptr 2: " << antrPtr(2, 7) << endl;

//CASE 3
cout << "case 3: " << endl;
vector<int>myNumbers = {2,5,1,3,6,4};
sortAscedning(myNumbers);
printNumbers(myNumbers);
cout << endl;
sortDescending(myNumbers);
printNumbers(myNumbers);
cout << endl;

//CASE 3 A
cout << "case 3 a: " << endl;
bool(*funcPtrTwo)(int, int) = ascendingCompare;
customSort(myNumbers, funcPtrTwo);
printNumbers(myNumbers);





  system("pause>nul");
  return 0;
}
