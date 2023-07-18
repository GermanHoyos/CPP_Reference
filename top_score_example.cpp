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

void buildObject(
  struct studentType stud[20],
  string lastName,
  string firstName,
  string score,
  int plus1,
  studentType &studentFname,
  studentType &studentLname,
  studentType &testScore,
  studentType &grade
);

void sortObject(
  struct studentType stud[20],
  string tmpFnA,
  string tmpFnB,
  string tmpLnA,
  string tmpLnB,
  int tmpTstA,
  int tmpTstB,
  char tmpGrdA,
  char tmpGrdB
);

void gradeObject(
  struct studentType stud[20]
);

void printObject(
  struct studentType stud[20]
);

int main() {
  ifstream inData; inData.open("Ch9_Ex2Data.txt");
  ofstream outData; outData.open("Ch9_Ex2Out.txt");
  struct studentType stud[20]; int plus1 = 0;
  string lastName, firstName, score,
         tmpFnA,  tmpLnA,
         tmpFnB,  tmpLnB;
  int    tmpTstA, tmpTstB;
  char   tmpGrdA, tmpGrdB;
  studentType fName, lName, tScore, gD;

buildObject(
  stud,  lastName, firstName, score, plus1,
  fName, lName,    tScore,    gD
);

sortObject(
  stud,  tmpFnA,  tmpFnB,  tmpLnA,
  tmpLnB,  tmpTstA,  tmpTstB,  tmpGrdA,
  tmpGrdB
);

gradeObject(
  stud
);

//print object
printObject(
  stud
);

inData.close();
outData.close();

return 0;
}

//"A function to read the students’ data into the array."
void buildObject(
  struct studentType stud[20],
  string lastName,
  string firstName,
  string score,
  int plus1,
  studentType &studentFname,
  studentType &studentLname,
  studentType &testScore,
  studentType &grade
)
{
  ifstream inData; inData.open("Ch9_Ex2Data.txt");
  while(inData >> lastName >> firstName >> score) {
    stud[plus1].studentFname = firstName;
    stud[plus1].studentLname = lastName;
    stud[plus1].testScore = stoi(score);
    stud[plus1].grade = 'F';
    plus1++;
  }
}

//"A function to print the names of the students having the highest test score."
void sortObject(
  struct studentType stud[20],
  string tmpFnA,
  string tmpFnB,
  string tmpLnA,
  string tmpLnB,
  int tmpTstA,
  int tmpTstB,
  char tmpGrdA,
  char tmpGrdB
){
  for(int a = 0; a < 20; a++){
    for(int b = a; b < 20; b++){
      if (stud[b].testScore > stud[a].testScore){
         tmpFnA = stud[a].studentFname; tmpLnA = stud[a].studentLname; tmpTstA = stud[a].testScore; tmpGrdA = stud[a].grade;
         tmpFnB = stud[b].studentFname; tmpLnB = stud[b].studentLname; tmpTstB = stud[b].testScore; tmpGrdB = stud[b].grade;
         stud[a].studentFname = tmpFnB; stud[a].studentLname = tmpLnB; stud[a].testScore = tmpTstB; stud[a].grade = tmpGrdB;
         stud[b].studentFname = tmpFnA; stud[b].studentLname = tmpLnA; stud[b].testScore = tmpTstA; stud[b].grade = tmpGrdA;
      }
    }
  }
}

//"A function to assign the relevant grade to each student."
void gradeObject(struct studentType stud[20]){
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
}

//"A function to print the names of the students having the highest test score."
void printObject(struct studentType stud[20]){
  ofstream outData; outData.open("Ch9_Ex2Out.txt");
  for (int i = 0; i < 20; i++){
    cout << stud[i].studentFname << ", " << stud[i].studentLname << " " << stud[i].testScore << " " << stud[i].grade << endl;
    outData << stud[i].studentFname << ", " << stud[i].studentLname << " " << stud[i].testScore << " " << stud[i].grade << endl;
  }
}
