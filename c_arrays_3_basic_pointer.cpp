#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
// "f5" to run in atom editor

/*
  In C++, a pointer refers to a variable that holds the address of another
  variable. Like regular variables, pointers have a data type. For example,
  a pointer of type integer can hold the address of a variable of type integer.
  A pointer of character type can hold the address of a variable of character type
*/

int main()
{

// "&" address-of-operator
// "*" dereference operator
    int myVar = 25;  //assign val to variable
    int* foo = &myVar; //"create pointer" = "[type] * name"
    cout <<" My Var Address [&myVar] = "
         << &myVar <<endl  //returns: [0x61fdfc]
         <<" My Var Address [foo]= "
         << foo    <<endl  //returns: [0x61fdfc]
         <<" My Var Value   [myVar]= "
         << myVar  <<endl  //returns: [25]
         <<" My Var Value   [*foo]= "
         << *foo   <<endl;  //returns: [25] //dereferences the address variable
    int bar = myVar;  //get the 25 val from one and assign to another

    int fish = 5;
    cout <<"fish " << &fish << endl; //returns address of fish

    int *fishPointer;

    fishPointer = &fish;

    cout <<"fish " << fishPointer << endl; //returns address of fish


//initializing an array with predetermined sequence (single qoutes'')
//21 elements of type "char" including \0
  char key[] = {
    'T','T','T','T','F','T','F','F','T','T',
    'F','T','T','F','T','F','T','T','T','T', '\0'
  };



//initializing an array with string literals (double qoutes"")
//21 elements of type "char" including \0
  char userKey[] = "TTTFTTTTTFFTTTTTFFT";



//possibley pass pointers of array into function for comparisons?
  int num1[5] = {1,2,3,4,5};
    cout << num1 << endl;     //returns address - specificly "1"
    cout << &num1[0] << endl; //& = reference >> returns address - specificly "1"

    cout << num1[3] << endl;          //returns 4
    cout << *(num1 + 3) << endl << endl;      //* = DEreference >> returns 4



//array lesson user input
  // int num2[5];
  //
  // for (int i = 0; i <= 4; i++){
  //   cout << "Number: ";
  //   cin >> num2[i];
  // }
  //
  // for (int i = 0; i < 5; i++){
  //   cout << *(num2+i ) << " " ;
  // } cout << endl;
  //
  // cout << num2[2]; // cout 3rd input



//pointers
  int n = 5;
    cout << n << endl; //returns 5
    cout <<"Pointer 1 : "<< &n << endl; //returns physical address
  int* ptr = &n;
    cout <<"Pointer 2 : " << ptr << endl;  //returns physical address
    cout <<"Pointer 3 : " << *ptr << endl; //returns value

    *ptr = 10; //change value at this address
    cout <<"Pointer val changed 4 : " << *ptr << endl;
    cout <<"N has changed: " << n << endl; //now returns 10
    //char pointer only to char vals / int pointer only to int, etc etc....

    int v; // noobs forget this
    int* ptr2 = &v; // use the phyical address of v
    *ptr2 = 7; // assigned value at this address
    cout << "V = " << v << endl; //print value












  system("pause>0");
}
