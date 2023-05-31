#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


//MAIN FUNCTION
int main()
{
    ifstream inData;
    string line1, line2, line3,
           line4, line5, line6,
           line7, line8;

    int lineCounter1 = 0;
    int lineCounter2 = 0;
    int lineCounter3 = 0;
    int lineCounter4 = 0;
    int lineCounter5 = 0;
    char answer;

    char answerKey[19];
    char studentId[7];
    char studentAnswers[19];


//read all data with no white space

        inData.open("Ch8_Ex6Data.txt");
        while(inData >> answer){
            cout << answer;
        }
        cout << endl;
        cout << endl;
//count number of total lines

        ifstream read1("Ch8_Ex6Data.txt");
        while(getline(read1, line1)){
            lineCounter1++;
        }
            cout << endl;
            cout << "Number Of Lines:" << lineCounter1++ << endl;

//cout << only 1st line

        ifstream read2("Ch8_Ex6Data.txt");
        while(getline(read2, line2)){
            lineCounter2++;
            if (lineCounter2 < 2){
                cout << " 1st Line = " << line2;
            }
        }

        cout << endl;
        cout << endl;
//cout << 3rd line

        ifstream read3("Ch8_Ex6Data.txt");
        while(getline(read3, line3)){
            lineCounter3++;
            if (lineCounter3  == 3){
                cout << " 3rd Line = " << line3;
            }
       }

       cout << endl;
       cout << endl;
//cout << each line separately

        ifstream read4("Ch8_Ex6Data.txt");
        while(getline(read4, line4)){
            lineCounter4++;
            cout << "Line Number: " << lineCounter4 <<" = " << line4 << endl;
        }
        cout << endl;
        cout << endl;
//put answers into answerKey[];
        ifstream read5("Ch8_Ex6Data.txt");
        while(getline(read5, line5)){
            lineCounter5++;
            int indexer = 0;
            if (lineCounter5 < 2){
                for (char c  : line5){
                    answerKey[indexer] = c;
                    indexer++;
                }
            }
        }
        for (int x = 0; x < 20; x++){
            cout <<" AnswerKey = " << "[" << answerKey[x]<< "]" << endl;
        }lineCounter5 = 0;
        cout << endl;
        cout << endl;
//get student id
        ifstream read6("Ch8_Ex6Data.txt");
        while(getline(read6, line6)){
            lineCounter5++;
            if(lineCounter5 > 1){
                cout << line6.substr(0, 7) << endl;
            }
        } lineCounter5 = 0;
        cout << endl;
        cout << endl;
//get student answers
        ifstream read7("Ch8_Ex6Data.txt");
        while(getline(read7, line7)){
            lineCounter5++;
            if(lineCounter5 > 1){
                cout << line7.substr(0, 7)
                     << " "
                     << line7.substr(9, 29)
                     << endl;
            }
        } lineCounter5 = 0;
        cout << endl;
        cout << endl;





//push id into temp array and cout
        ifstream read8("Ch8_Ex6Data.txt");
        int x = 0;
        while(getline(read8, line8)){
            lineCounter5++;
                if (lineCounter5 > 1){
                    string transferID = line8.substr(0, 7);
                    cout << "[Student Id]>> " << transferID ;

                    string transferAns = line8.substr(9, 29);
                    cout << " [Student Answers]>> " << transferAns << endl;


                }
        }  lineCounter5 = 0;
        cout << endl;
        cout << endl;

























































//CLOSE
 /*       ifstream read8("Ch8_Ex6Data.txt");
        int x = 0;
        while(getline(read8, line8)){
            lineCounter5++;


            if(lineCounter5 > 1){
                if (x < 7){
                for (char c : line8){

                    studentId[x] = c;
                    x++;

                } x = 0;
                } cout <<"Student Id: " << studentId << endl;
            }
        }  lineCounter5 = 0;
        cout << endl;
        cout << endl;
*/






//cout [STUDENT ID] [STUDENT ANSWERS] [GRADE]


    inData.close();

  return 0;
}
