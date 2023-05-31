//include statement(s)
#include <iostream> //<-- header file
#include <cmath>
#include <string>  //https://www.w3schools.com/cpp/cpp_strings_input.asp
#include <iomanip> // setprecision(n) n is the number of decimal places
                   // also for set with manipulator "setw"

//using namespace statement
using namespace std;

int main()
{

//variable declaration
  int num, num1, num2, num3, average;
  int test1, test2;
  char ch1, ch2, varChar;


  num1 = 125;
  num2 = 28;
  num3 = -25;

//  executable statements
//  average = (num1 + num2 + num3)/3;
  cout << num1 <<"\n";
//  cout << num2 <<"\n";
//  cout << num3 <<"\n";
//  cout << average <<"\n";
//  cin >> test1 >> test2;
//  cout << test1 << "\n" << test2 << "\n";
//  cout <<  pow(2,3);
//  cin >> ch1 >> ch2 >> num; //

//GET
    //https://www.cplusplus.com/reference/istream/istream/get/
    cin.get(ch1);
    cin.get(ch2);
    cin >> num; //https://www.youtube.com/watch?v=yMwA4u7eXEY
    cout << ch1 << "\n" << ch2 << "\n" << num;
//PUTBACKS
    //https://www.youtube.com/watch?v=yMwA4u7eXEY
    //https://www.cplusplus.com/reference/istream/istream/putback/
//PEEKS
    //https://www.youtube.com/watch?v=yMwA4u7eXEY
    //https://www.cplusplus.com/reference/istream/istream/peek/
//CLEAR
    //https://www.cplusplus.com/reference/ios/ios/clear/
//setw(n) SET WITH MANIPULATOR
    //https://www.youtube.com/watch?v=k7QATXoF1Rw
    //setw(26)
//setfill(ch)
    //self explanatory, fill blanks cout with a charector
//LEFT and RIGHT manipulators
    //self explanatory, justify left or right
//getline
    // get the string including white spaces
//getline(cin, myString)
    //cin get the input and the var = "myString" is assigned to that input

return 0;
}
