#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream readFl("Ch8_Ex6Data.txt");
    string lineScan;

    int lineCounter = 0;
    int answer_key_size;
    int line_size;
    int row_size = 0;
    int column_size = 2;

    while (getline(readFl, lineScan)) //1st line(do ALL this)... 2nd line(do ALL this)... etc etc
    {

        if (lineCounter < 1)
        {
            answer_key_size = lineScan.length();
            string *answer_key = new string[answer_key_size];
            for (int i = 0; i < lineScan.length(); i++)
            {
                answer_key[i] = lineScan[i];
            }

            for (int i = 0; i < answer_key_size; i++)
            {
                //cout << "[" << answer_key[i] << "]";
            }
            //cout << endl;
        }
        lineCounter++;
        if (lineCounter > 1)
        {
            // row_size++;
            // string getID = lineScan.substr(0, 8);
            // string getAnswers = lineScan.substr(9, 29);
            // cout << getID << " " << getAnswers << endl;
            line_size = lineScan.length();
            string *student_rows = new string[line_size]; // create dynam Arr

            //put id's and answers
            for (int i = 0; i < line_size; i++)
            {
                student_rows[i] = lineScan[i];
            }

            //cout indexes of dynam array
            for (int i = 0; i < line_size; i++)
            {
                cout << "[" << student_rows[i] << "]";
            } cout << endl;
        }
        
    }

    return 0;
}

/* OUTPUT
[Student ID] [Student Answers] [Student Score] [Student Grade]

TTFTFTTTFTFTFFTTFTTF
ABC54102 T FTFTFTTTFTTFTTF TF
DEF56278 TTFTFTTTFTFTFFTTFTTF
ABC42366 TTFTFTTTFTFTFFTTF
ABC42586 TTTTFTTT TFTFFFTF
*/
