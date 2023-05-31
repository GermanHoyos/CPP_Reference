#include <iostream>
#include <string>
using namespace std;

int main() {

//string array to be modified:
    string strArray[5] = {"A1,stringOne","A2,stringTwo","A3,stringThree","A4,string four","A5,stringFive"};

//console out the address and value in each index
    for (int i = 0; i < 5; i++) {
        cout << &strArray[i] << ": " << strArray[i] << endl;
    }   cout << endl;

//make pointer "myAddress" store address of strArray[0]
    string * myAddress = &strArray[0];

//console out 'myAddress' which will be the address of strArray[0]
    cout << "myAddress: " << myAddress << endl;

//create whats called a "pointer array"
    string *arr[5];

//initialize the 0th index to NULL
    for (int i = 0; i < 5; i++) {
        arr[i] = NULL;
    };

//assign the address stored in 'myAddress' to the 0th index of "string *arr[1]" //arr[0] = myAddress;
    for (int i = 0; i < 5; i++) {
        arr[i] = myAddress;
        myAddress++;
    }   cout << endl;

//console out the 0th index which should be the address of strArray[0] and dereference it
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << ": " << *arr[i] << endl;
    };

//make changes to 'arr' which thereby changes 'strArray' //*arr[0] = "changedOne";
    for (int i = 0; i < 5; i++) {
        *arr[i] = "changed in Arr";
    }   cout << endl;

//console out strArray which should have a different value now
    for (int i = 0; i < 5; i++) {
        cout << &strArray[i] << ": " << strArray[i] << endl;
    };

return 0;
}
