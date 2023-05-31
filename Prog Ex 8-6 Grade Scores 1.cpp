#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;



int main()
{
    ifstream inData;
    string line;
    string lineTwo;

    int lineNum = 0;
    int lineNums = 0;
    char answer;


    inData.open("Ch8_Ex6Data.txt");

//read all data with no white space
        while(inData >> answer){
            cout << answer;
        }
        cout << endl;

//count number of lines
        ifstream file("Ch8_Ex6Data.txt");
        while(getline(file, line)){
            lineNum++;
            if (lineNum  == 3){
                cout << " 3rd Line: " << line;
            }
       }
       cout << endl;

       cout << "Number Of Lines:" << lineNum++ << endl;

//cout only first line
            ifstream fileTwo("Ch8_Ex6Data.txt");
            while(getline(fileTwo, lineTwo)){
                lineNums++;
                if (lineNums < 2){
                    cout << " first Line: " << lineTwo;
                }
            }



    inData.close();

  return 0;
}


