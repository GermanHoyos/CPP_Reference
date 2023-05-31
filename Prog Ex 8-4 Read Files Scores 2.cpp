//File I/O in 5 steps
    #include <iostream>
    #include <string>
    #include <fstream> //Step 1)Include the header file fstream in the program.
    #include <iomanip>
    using namespace std;

int main()
{
    int score;
    int range1 = 0, range2 = 0, range3 = 0,
        range4 = 0, range5 = 0, range6 = 0,
        range7 = 0, range8 = 0;

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
        if (score <= 25){
            range1++;
        } else if (score >= 25 && score <= 49) {
            range2++;
        } else if (score >= 50 && score <= 74) {
            range3++;
        } else if (score >= 75 && score <= 99) {
            range4++;
        } else if (score >= 100 && score <= 124) {
            range5++;
        } else if (score >= 125 && score <= 149) {
            range6++;
        } else if (score >= 150 && score <= 174) {
            range7++;
        } else if (score >= 175 && score <= 200) {
            range8++;
        } else {
            //null
        }
     }

     cout << "0-24: "    << range1++ << " students " << endl;
     cout << "25-49: "   << range2++ << " students " << endl;
     cout << "50-74: "   << range3++ << " students " << endl;
     cout << "75-99: "   << range4++ << " students " << endl;
     cout << "100-124: " << range5++ << " students " << endl;
     cout << "125-149: " << range6++ << " students " << endl;
     cout << "150-174: " << range7++ << " students " << endl;
     cout << "175-200: " << range8++ << " students " << endl;

     //Step 5)Disassociate stream variables
     inData.close();

  return 0;
}












    //outData.close();

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
