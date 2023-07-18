//File I/O in 5 steps
//test.txt
//Andrew Miller 87.50 89 65.75 37 98.50 (chapter 3 example)
//10 (my test file)
#include <iostream>
#include <string>
#include <fstream> //Step 1)Include the header file fstream in the program.
#include <iomanip>
using namespace std;

int main()
{

    int pay;
    string rate;

    //Step 2)Declare file stream variables
    ifstream inData;
    ofstream outData;

    //getLine needs a string as its second param. User inputs file name
    string inFlString;
    cout << "Please enter file name, including file extension: ";
    getline( cin, inFlString); //user puts in file with extension.

    //Step 3)Associate the file stream with I/O sources. Program writes to this file
    inData.open(inFlString);
    outData.open("out.txt");

    //Step 4)Use the file stream variable with >>,<<, or other I/O functions. Code for data manipulation
    inData >> pay >> rate;

    //"couts" used for rapid console debugging
    cout    << "Pay is: " << pay << "\n" << "Rate is: " << rate <<  "\n";
    outData << "Pay is: " << pay << "\n" << "Rate is: " << rate <<  "\n";

    //Step 5)Disassociate stream variables
    inData.close();
    outData.close();

  return 0;
}
