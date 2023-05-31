#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
  ifstream inData;
  ofstream outData;
  inData.open("Ch9_Ex2Data.txt");
  outData.open("Ch9_Ex2Out.txt");
  string multiArr[20][4];
  string lastName, firstName, score,
         index0A,   index1A,    index2A,
         index0B,   index1B,    index2B;
  int plus1 = 0;
  int lastN = 0;
  int firstN = 1;
  int scoreIndex =  2;
  int intA, intB, intTempA, intTempB;

  struct studentType{
    string studentFname;
    string studentLname;
    int testScore;
    char grade;
  } sU;

  while(inData >> sU.studentLname >> sU.studentFname >> score){
    multiArr[plus1][0] = sU.studentLname;
    multiArr[plus1][1] = sU.studentFname;
    multiArr[plus1][2] = score;
    multiArr[plus1][3] = 'X';
    istringstream(score) >> intTempA; // convert score string to int for sU object
    sU.testScore = intTempA;
    sU.grade = 'F';
    plus1++;
  }

  for(int i = 0; i < 20; i++){
    cout << multiArr[i][1] << " " << multiArr[i][0] << " " << multiArr[i][2] << " " << multiArr[i][3] << endl;
  }



  inData.close();
  outData.close();

  return 0;
}
