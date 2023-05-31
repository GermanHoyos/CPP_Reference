#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//"Ch9_Ex2Data.txt"
//"Ch9_Ex2Out.txt"

//MAIN FUNCTION
int main()
{

// Wonderful, Alice\s+89\s+B
// WonderFul, Alice 89 B
// [studentname 1] [,] [studentname 2] [testScore] [grade %] {highest to lowest}
string lastName, firstName;
int score;

ifstream inData;
ofstream outData;

inData.open("Ch9_Ex2Data.txt");

while(inData >> lastName >> firstName >> score) {
  

  cout << lastName << " " << firstName << " " << score << endl;
}




  return 0;
}

/*

Write a program that reads students’ names followed by their test scores.
The program should output each student’s name followed by the test scores
and the relevant grade. It should also find and print the highest test
score and the name of the students having the highest test score.

Student data should be stored in a struct variable of type studentType,
which has four components: studentFName and studentLName of type
string, testScore of type int (testScore is between 0 and 100), and grade
of type char. Suppose that the class has 20 students. Use an array of 20
components of type studentType. Your program must contain at least the
following functions:

A function to read the students’ data into the array.
A function to assign the relevant grade to each student.
A function to find the highest test score.
A function to print the names of the students having the highest test score.
Your program must output each student’s name in this form: last name followed
by a comma, followed by a space, followed by the first name; the name must
be left justified. Moreover, other than declaring the variables and opening
the input and output files, the function main should only be a collection of
function calls.

Your program should accept no input and save the output to Ch9_Ex2Out.txt.

*/
/*

Duckey Donald 85
Goof Goofy 89
Brave Balto 93
Snow Smitn 93
Alice Wonderful 89
Samina Akthar 85
Simba Green 95
Donald Egger 90
Brown Deer 86
Johny Jackson 95
Greg Gupta 75
Samuel Happy 80
Danny Arora 80
Sleepy June 70
Amy Cheng 83
Shelly Malik 95
Chelsea Tomek 95
Angela Clodfelter 95
Allison Nields 95
Lance Norman 88

*/
