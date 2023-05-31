#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


int main() {

    int test1 = 0;
    char test2 = 'g';
    bool verifyChar = false;
    bool verifyInt = false;

    string a = typeid(test2).name();

    if (a == "c") {
        verifyChar = true;
    }
    
    cout << a << " "; 
    cout << verifyChar;

     

    
   
   
    
}



