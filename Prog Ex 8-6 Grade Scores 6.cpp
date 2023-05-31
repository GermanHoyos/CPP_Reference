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
    int cScore;
    int lineCounter = 0;
    ifstream readFl("Ch8_Ex6Data.txt");

        while(getline(readFl, lineScan)){
                if (lineCounter < 1){
                    transferKey = lineScan.substr(0, 20);
                    cout << "[AnswerKey]>>                              " << transferKey << endl;
                } lineCounter++;
                if (lineCounter > 1){
                    string transferID = lineScan.substr(0, 7);
                    cout << "[Student Id]>> " << transferID ;

                    string transferAns = lineScan.substr(9, 29);
                    cScore = score(transferAns, transferKey);
                    cout << "[Score]>> " << cScore << endl;
                }
        }  lineCounter = 0;
  return 0;
}

double score(string transferAns, string transferKey){
    int score = 0;
    int x = 0;

    cout << " [Student Answers]>> "
         << transferAns
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




























































/*
    //put answers into answerKey[];
        ifstream read5("Ch8_Ex6Data.txt");
        while(getline(read5, lineScan)){
            lineCounter++;
            int indexer = 0;
            if (lineCounter < 2){
                for (char c  : lineScan){
                    answerKey[indexer] = c;
                    indexer++;
                }
            }
        }
        for (int x = 0; x < 20; x++){
            cout <<" AnswerKey = " << "[" << answerKey[x]<< "]" << endl;
        }lineCounter = 0;
        cout << endl;
        cout << endl;

*/
