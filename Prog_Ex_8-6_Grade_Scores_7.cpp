#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

double score(string transferAns, string transferKey);

//MAIN FUNCTION
int main()
{
    string lineScan;
    string transferKey;
    char grade = 'A';
    double cScore;
    double percent;

    int lineCounter = 0;
    ifstream readFl("Ch8_Ex6Data.txt");

        while(getline(readFl, lineScan)){ //1st line(do this)... 2nd line(do this)... etc etc
                if (lineCounter < 1){
                    transferKey = lineScan.substr(0, 20);
                } lineCounter++;
                if (lineCounter > 1){
                    string transferID = lineScan.substr(0, 8);
                    cout << transferID << " ";
                    string transferAns = lineScan.substr(9, 29);
                    cScore = score(transferAns, transferKey);
                    //calculate grade via score
                    percent = (cScore / 40) * 100;
                    if (percent >= 90){
                        grade = 'A';
                    } else if(percent >= 80 && percent <= 89.99){
                        grade = 'B';
                    } else if(percent >= 70 && percent <= 70.99){
                        grade = 'C';
                    } else if(percent >= 60 && percent <= 69.99){
                        grade = 'D';
                    } else {
                        grade = 'F';
                    }
                    cout << cScore << " " << grade << endl;
                }
        }  lineCounter = 0;
  return 0;
}

double score(string transferAns, string transferKey){
    int score = 0;
    int x = 0;

    cout << transferAns
         << " ";

    for (char c : transferAns){
        if (c == transferKey[x]){
            score = score + 2;
        }
        if (c != transferKey[x] && c != ' '){
            score = score - 1;
        }
        x++; // verified correct tabulations
    }

    return score;
}


/* OUTPUT
    [Student ID] [Student Answers] [Student Score] [Student Grade]
*/

/*
TTFTFTTTFTFTFFTTFTTF
ABC54102 T FTFTFTTTFTTFTTF TF
DEF56278 TTFTFTTTFTFTFFTTFTTF
ABC42366 TTFTFTTTFTFTFFTTF
ABC42586 TTTTFTTT TFTFFFTF
*/

// Use a string array [Transfer ID] [Transfer Answers]