//File I/O in 5 steps
#include <iostream>
#include <string>
#include <fstream> //Step 1)Include the header file fstream in the program.
#include <iomanip>
using namespace std;

int main()
{

    string firstName, lastName;
    double curSal, payInc, newSal;
    int score;

    //Step 2)Declare file stream variables
    ifstream inData;
    ofstream outData;

    //getLine needs a string as its second param. User inputs file name
    string inFlString;
    cout << "Please enter file name, including file extension: ";
    getline( cin, inFlString); //user puts in file with extension "Ch8_Ex4Data.txt"

    //Step 3)Associate the file stream with I/O sources. Program writes to this file
    inData.open(inFlString);
    //outData.open("Ch3_Ex5Output.dat");

    while(inData >> score) {

        cout << score << endl;
    }


    /*
    //Step 4)Use the file stream variable with >>,<<, or other I/O functions. Code for data manipulation
    while (inData >> lastName >> firstName >> curSal >> payInc) {
        newSal = (curSal * payInc / 100) + curSal; // pay increase was a %percentage
            //"fixed notation != e+10" "showpoint" decimall will always display "setpercicion" amount of dec
            cout << fixed << showpoint << setprecision(2);
            cout << firstName << " " << lastName << " " << newSal << endl;
                outData << fixed << showpoint << setprecision(2);
                outData << firstName << " " << lastName << " " << newSal << endl;
     }*/

    //Step 5)Disassociate stream variables
    inData.close();
    //outData.close();

  return 0;
}
