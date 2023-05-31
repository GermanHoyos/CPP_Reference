#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

void buildMulti(
  string multiArr[20][3], string lastName, string firstName, string score,
  int plus1, int lastN, int firstN, int scoreIndex
);

void sortMulti(
  string multiArr[20][3], int intA, int intB, string index0A, string index1A,
  string index2A, string index0B, string index1B, string index2B
);

void printMulti(
  string multiArr[20][3]
);

int main() {
  ifstream inData;
  ofstream outData;
  inData.open("Ch9_Ex2Data.txt");
  outData.open("Ch9_Ex2Out.txt");
  string multiArr[20][3];
  string lastName, firstName, score,
         index0A,   index1A,    index2A,
         index0B,   index1B,    index2B;
  int plus1 = 0;
  int lastN = 0;
  int firstN = 1;
  int scoreIndex =  2;
  int intA, intB;

  buildMulti(
    multiArr, lastName, firstName,
    score, plus1, lastN, firstN,
    scoreIndex
  );

  sortMulti(
    multiArr, intA, intB, index0A, index1A,
    index2A, index0B, index1B, index2B
  );

  printMulti(multiArr);

  inData.close();
  outData.close();

  return 0;
}

//per cengage
//"A function to read the students data into the array"
void buildMulti(
  string multiArr[20][3], string lastName, string firstName, string score,
  int plus1, int lastN, int firstN, int scoreIndex
){
  ifstream inData;
  inData.open("Ch9_Ex2Data.txt");
  while(inData >> lastName >> firstName >> score) {
      multiArr[plus1][lastN] = lastName;
      multiArr[plus1][firstN] = firstName;
      multiArr[plus1][scoreIndex] = score;
      plus1++;
  }
}

//per cengage
//"A function to assign a relevent grade to each student"

//per cengage
//"A function to find the highest test score"
void sortMulti(
  string multiArr[20][3], int intA, int intB, string index0A, string index1A,
  string index2A, string index0B, string index1B, string index2B
){
  for(int a = 0; a < 20; a++){
    for(int b = a; b < 20; b++){
      istringstream(multiArr[a][2]) >> intA;
      istringstream(multiArr[b][2]) >> intB;
      if(intB > intA){
        index0A = multiArr[a][0]; index1A = multiArr[a][1]; index2A = multiArr[a][2];
        index0B = multiArr[b][0]; index1B = multiArr[b][1]; index2B = multiArr[b][2];
        multiArr[a][0] = index0B; multiArr[a][1] = index1B; multiArr[a][2] = index2B;
        multiArr[b][0] = index0A; multiArr[b][1] = index1A; multiArr[b][2] = index2A;
      }
    }
  }
}

//per cengage
//"A function to print the names of the students having the highest test scores"
void printMulti(string multiArr[20][3]){
  for(int i = 0; i < 20; i++){
    //ofstream outData;
    //outData.open("Ch9_Ex2Out.txt");
    cout << multiArr[i][1] << " " << multiArr[i][0] << " " << multiArr[i][2] << endl;
    //outData "left justify"
    //outData << multiArr[i][0] << ", " << multiArr[i][1] << " " << multiArr[i][2] << endl;
  }
}
