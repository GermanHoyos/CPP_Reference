#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

struct studentType
{
  string studentFname;
  string studentLname;
  int testScore;
  char grade;
} sU;

int main() {
  ifstream inData; inData.open("Ch9_Ex2Data.txt");
  ofstream outData; outData.open("Ch9_Ex2Out.txt");
  struct studentType stud[20]; int plus1 = 0;
  string lastName, firstName, score,
         tmpFnA,  tmpLnA,
         tmpFnB,  tmpLnB;
  int    tmpTstA, tmpTstB;
  char   tmpGrdA, tmpGrdB;

//build object
while(inData >> lastName >> firstName >> score) {
  stud[plus1].studentFname = firstName;
  stud[plus1].studentLname = lastName;
  stud[plus1].testScore = stoi(score);
  // istringstream(score) >> intTempA;
  // stud[plus1].testScore = intTempA; // convert score string to int for sU object
  stud[plus1].grade = 'F';
  plus1++;
}

//print object
for (int i = 0; i < 20; i++){
  cout << stud[i].studentFname << " " << stud[i].studentLname << " " << stud[i].testScore << " " << stud[i].grade << endl;
}

//sort object
for(int a = 0; a < 20; a++){
  for(int b = a; b < 20; b++){
    if (stud[b].testScore > stud[a].testScore){
       tmpFnA = stud[a].studentFname; tmpLnA = stud[a].studentLname; tmpTstA = stud[a].testScore; tmpGrdA = stud[a].grade;
       tmpFnB = stud[b].studentFname; tmpLnB = stud[b].studentLname; tmpTstB = stud[b].testScore; tmpGrdB = stud[b].grade;
       stud[a].studentFname = tmpFnB; stud[a].studentLname = tmpLnB; stud[a].testScore = tmpTstB; stud[a].grade = tmpGrdB;
       stud[b].studentFname = tmpFnA; stud[b].studentLname = tmpLnA; stud[b].testScore = tmpTstA; stud[b].grade = tmpGrdA;
    }
  }
} cout << endl;

//print object
for (int i = 0; i < 20; i++){
  cout << stud[i].studentFname << " " << stud[i].studentLname << " " << stud[i].testScore << " " << stud[i].grade << endl;
} cout << endl;

//grade object
for (int i = 0; i < 20; i++){
  if(stud[i].testScore >= 90){
    stud[i].grade = 'A';
  } else if (stud[i].testScore >= 80 && stud[i].testScore <= 89){
    stud[i].grade = 'B';
  } else if (stud[i].testScore >= 70 && stud[i].testScore <= 79){
    stud[i].grade = 'C';
  } else if(stud[i].testScore >= 60 && stud[i].testScore <= 69){
    stud[i].grade = 'D';
  } else {
    stud[i].grade = 'F';
  }
}

//print object
for (int i = 0; i < 20; i++){
  cout << stud[i].studentFname << ", " << stud[i].studentLname << " " << stud[i].testScore << " " << stud[i].grade << endl;
}

  inData.close();
  outData.close();

  return 0;
}
