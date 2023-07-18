//File I/O in 5 steps
#include <iostream>
#include <string>
#include <fstream> //Step 1)Include the header file fstream in the program.
#include <iomanip>
using namespace std;

int main()
{
    int num;

    cout << "Enter an integer between 0 and 35:" << endl;
    cin >> num;

    if (num <= 9) {
        cout << num << " = ";
        cout << char(num) << endl;
    } else {
        cout << char(num) << endl;
        //cout << static_cast<char>('A' + (num - 10)) << endl;
        //cout << static_cast<char>('a' + (num - 10)) << endl;

    }

  return 0;
}


//ASCCII table, convert every possible character to a number
//2^7 represents all possible combinations, or 128 characters

//test - this seems convert straight to
//cout << static_cast<char>(num) << endl;

//final
//cout << static_cast<char>('A' + (num - 10)) << endl;

