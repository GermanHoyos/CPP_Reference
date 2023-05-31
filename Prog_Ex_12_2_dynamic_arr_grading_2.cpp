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
    char grade = 'A';

    double percent;

    cout << "# of questions?" << endl;
    cin >> answer_key_size;
    string *answer_key = new string[answer_key_size];

    while (getline(readFl, lineScan)) //1st line(do ALL this)... 2nd line(do ALL this)... etc etc
    {

        if (lineCounter < 1)
        {
            cout << "Key ";
            for (int i = 0; i < lineScan.length(); i++)
            {
                answer_key[i] = lineScan[i];
            }

            for (int i = 0; i < answer_key_size; i++)
            {
                cout << answer_key[i];
            }
            cout << endl;
        }
        lineCounter++;
        if (lineCounter > 1)
        {
            line_size = lineScan.length();
            string *student_rows = new string[line_size]; // create dynam Arr

            //put id's and answers
            for (int i = 0; i < line_size; i++)
            {
                student_rows[i] = lineScan[i];
            }

            double score = 0;

            for (int i = 0; i < line_size; i++)
            {
                if (i > 8)
                {
                    if (student_rows[i] == (answer_key[i - 9]))
                    {
                        score = score + 2;
                    }

                    if (student_rows[i] != answer_key[i - 9] && student_rows[i] != " ")
                    {
                        score = score - 1;
                    }
                }
            }

            percent = (score / 40) * 100;
            if (percent >= 90)
            {
                grade = 'A';
            }
            else if (percent >= 80 && percent <= 89.99)
            {
                grade = 'B';
            }
            else if (percent >= 70 && percent <= 70.99)
            {
                grade = 'C';
            }
            else if (percent >= 60 && percent <= 69.99)
            {
                grade = 'D';
            }
            else
            {
                grade = 'F';
            }

            //cout indexes of dynam array
            for (int i = 0; i < line_size; i++)
            {
                cout << student_rows[i];
            }

            cout << " " << score << " " << grade << " " << endl;
        }
    }

    return 0;
}
