//File I/O in 5 steps
#include <iostream>
#include <string>
#include <fstream> //Step 1)Include the header file fstream in the program.
#include <iomanip>
using namespace std;

/*

Ch3_Ex5Data.txt

Miller Andrew 65789.87 5
Green Sheila 75892.56 6
Sethi Amit 74900.50 6.1

*/

int main()
{

    string firstName, lastName;
    double curSal, payInc , newSal;

    //Step 2)Declare file stream variables
    ifstream inData;
    ofstream outData;

    //getLine needs a string as its second param. User inputs file name
    string inFlString;
    cout << "Please enter file name, including file extension: ";
    getline( cin, inFlString); //user puts in file with extension. "Ch3_Ex5Data.txt"

    //Step 3)Associate the file stream with I/O sources. Program writes to this file
    inData.open(inFlString);
    //Ch3_Ex5Output.txt to test, also use cout for rapid views
    outData.open("Ch3_Ex5Output.txt");

    //Step 4)Use the file stream variable with >>,<<, or other I/O functions. Code for data manipulation
    /* TESTING only
    while (inData >> lastName >> firstName >> curSal >> payInc) {
        //check in console to make sure data is retrieved
        cout << firstName << ", "<< lastName << ", "<< curSal <<", "<< payInc << endl;
    }
    */
    while (inData >> lastName >> firstName >> curSal >> payInc) {
        //"Ch3_Ex5Output" for tests
            newSal = (curSal * payInc / 100) + curSal;
                cout << firstName << " " << lastName << " " << newSal << endl;
                outData << firstName << " " << lastName << " " << newSal << endl;
     }



    //Step 5)Disassociate stream variables
    inData.close();
    outData.close();

  return 0;
}
