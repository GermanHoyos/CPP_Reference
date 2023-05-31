#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


//MAIN FUNCTION
int main()
{
    ifstream inData;
    string lineScan;

    int lineCounter = 0;
    int x = 0;
    char answer;

    char answerKey[19];
    char studentId[7];
    char studentAnswers[19];

        ifstream readFl("Ch8_Ex6Data.txt");
        while(getline(readFl, lineScan)){
            lineCounter++;
                if (lineCounter > 1){

                    string transferID = lineScan.substr(0, 7);
                    cout << "[Student Id]>> " << transferID ;

                    string transferAns = lineScan.substr(9, 29);
                    cout << " [Student Answers]>> " << transferAns << endl;

                }
        }  lineCounter = 0;


  return 0;
}
//END MAIN

