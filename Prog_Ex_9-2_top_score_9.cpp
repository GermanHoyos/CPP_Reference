#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;
// "Ch9_Ex2Data.txt"

int main() {

  ifstream inData;
  ofstream outData;
  inData.open("Ch9_Ex2Data.txt");
  string multiArr[20][3];
  string lastName, firstName, score,
         index0A,   index1A,    index2A,
         index0B,   index1B,    index2B;
  int plus1 = 0;
  int lastN = 0;
  int firstN = 1;
  int scoreIndex =  2;
  int intA, intB;

//put scores into multi
  while(inData >> lastName >> firstName >> score) {
      multiArr[plus1][lastN] = lastName;
      multiArr[plus1][firstN] = firstName;
      multiArr[plus1][scoreIndex] = score;
      plus1++;
  }

//check multi for unsorted scores
  for(int i = 0; i < 20; i++){
    cout << multiArr[i][1] << " " << multiArr[i][0] << " " << multiArr[i][2] << endl;
  }

  cout << endl;
  cout << endl;

//sort multi in descending order
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

//check multi for sorted scores
  for(int i = 0; i < 20; i++){
    cout << multiArr[i][1] << " " << multiArr[i][0] << " " << multiArr[i][2] << endl;
  }

  return 0;
}


// Duckey Donald 85
// Goof Goofy 89
// Brave Balto 93
// Snow Smitn 93
// Alice Wonderful 89
// Samina Akthar 85
// Simba Green 95
// Donald Egger 90
// Brown Deer 86
// Johny Jackson 95
// Greg Gupta 75
// Samuel Happy 80
// Danny Arora 80
// Sleepy June 70
// Amy Cheng 83
// Shelly Malik 95
// Chelsea Tomek 95
// Angela Clodfelter 95
// Allison Nields 95
// Lance Norman 88





//
//
// Instructions
// Write a program that reads students’ names followed by their test scores.
// The program should output each student’s name followed by the test scores and
// the relevant grade. It should also find and print the highest test score and
// the name of the students having the highest test score.
//
// Student data should be stored in a struct variable of type studentType, which
// has four components: studentFName and studentLName of type string, testScore of
// type int (testScore is between 0 and 100), and grade of type char. Suppose that
// the class has 20 students. Use an array of 20 components of type studentType.
// Your program must contain at least the following functions:
//
// A function to read the students’ data into the array.
// A function to assign the relevant grade to each student.
// A function to find the highest test score.
// A function to print the names of the students having the highest test score.
// Your program must output each student’s name in this form: last name followed
// by a comma, followed by a space, followed by the first name; the name must be
// left justified. Moreover, other than declaring the variables and opening the
// input and output files, the function main should only be a collection of function
// calls.
//
// Your program should accept no input and save the output to Ch9_Ex2Out.txt.














// for(int i = 0; i < 10; i++){
//   cout << stringSort[i] << endl;
// }
