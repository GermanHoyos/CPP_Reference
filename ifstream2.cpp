//File I/O in 5 steps
#include <iostream>
#include <string>
#include <fstream> //Step 1)Include the header file fstream in the program.
#include <iomanip>
using namespace std;

int main()
{

    string firstName;
    string lastName;
    double num;

    //Step 2)Declare file stream variables
    ifstream inData;
    ofstream outData;

    //getLine needs a string as its second param. User inputs file name
    string inFlString;
    cout << "Please enter file name, including file extension: ";
    getline( cin, inFlString); //user puts in file with extension. Istream1

    //Step 3)Associate the file stream with I/O sources. Program writes to this file
    inData.open(inFlString);
    outData.open("IstreamOut1.txt");

    //Step 4)Use the file stream variable with >>,<<, or other I/O functions. Code for data manipulation
    inData >> firstName >> lastName;
    cout   << firstName << ", " << lastName;

    inData >> num;
    cout   << " " << num;

    //Step 5)Disassociate stream variables
    inData.close();
    outData.close();

  return 0;
}
