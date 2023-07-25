#include <iostream>
#include <string>
using namespace std;

int main() {

//string array to be modified:
    string strArray[1] = {"stringOne"};

//console out the address and value in each index
    cout << &strArray[0] << ": " << strArray[0] << endl;

//make pointer "myAddress" store address of strArray[0]
    string * myAddress = &strArray[0];

//console out 'myAddress' which will be the address of strArray[0]
    cout << "myAddress: " << myAddress << endl;

//create whats called a "pointer array"
    string *arr[1];

//initialize the 0th index to NULL
    arr[0] = NULL;

//assign the address stored in 'myAddress' to the 0th index of "string *arr[1]"
    arr[0] = myAddress;

//console out the 0th index which should be the address of strArray[0] and dereference it
    cout << arr[0] << ": " << *arr[0] << endl;

//make changes to 'arr' which thereby changes 'strArray'
    *arr[0] = "changedOne";

//console out strArray which should have a different value now
    cout << &strArray[0] << ": " << strArray[0] << endl;


 return 0;
}


