#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

//CLASS BLUPRINT----------------------------------------------------------------
//"clockType" bluprint needs to be in a "header file" ex: clockType.h
class clockType{
public:
 void setTime(int, int, int); //change or mod values
 void getTime(int&, int&, int&) const; //retrieve values
 void printTime() const;  //retrieve values
 void incrementSeconds(); //change or mod values
 void incrementMinutes(); //change or mod values
 void incrementHours();   //change or mod values
 bool equalTime(const clockType&) const; //check / compare
private: // only accessable through class object reference
 int hr;
 int min;
 int sec;
};

//CLASS METHODS/FUNCTIONS-------------------------------------------------------
//this method should be inline
void clockType::setTime(int a, int b, int c){ // <-- kind of like an object method in .js
  hr = a;
  min = b;
  sec = c;
}

//pass these variables by "referece" -> "int& a" affects the external var from
//within the function (research.js equivalnt)
//http://www.cplusplus.com/doc/tutorial/functions/
//"const" unsures the ref parameters are not modified by this particular function
void clockType::getTime(int& a, int& b, int& c) const{ //this should be "inline"
  a = hr;  //can be set with "cin >>"
  b = min; //can be set with "cin >>"
  c = sec; //can be set with "cin >>"
}

void clockType::printTime() const{
  cout << hr << ":" << min << ":" << sec;
  cout << endl;
}

//change hr somehow, maybee hr++ if less than 24?
void clockType::incrementHours(){
  hr++;
  if (hr > 23) {
    hr = 0; //24 hour counter cycle
  }
}

//change min somehow, maybee min++ if less than 60?
void clockType::incrementMinutes(){
  min++;
  if (min > 59){
    min = 0; //60 min counter cycle
  }
}

//change sec somehow, maybee sec++ if les than 60?
void clockType::incrementSeconds(){
  sec++;
  if (sec > 59){
    sec = 0; //60 sec counter cycle
  }
}

//this function will compare two clocks and return t/f if they are "equal"
//this function does not change any values / hence "const"
//compare clock1.equalTime call using the param clockParam to clockParam
//clockParam is simply another instanstiation of the clockTypeCLass like .js
//object instanstiations
bool clockType::equalTime(const clockType& clockParam) const {
  if (hr == clockParam.hr && min == clockParam.min && sec == clockParam.sec){
    return true;
  } else {
    return false;
  }
}

//MAIN--------------------------------------------------------------------------
int main() {

  bool tOrF; //true or false
  int a, b, c; //for getTime function method

  clockType clock1;
    clock1.setTime (24,60,20);
    clock1.printTime(); //maybee use "this" like in .js to print "clock1" before time?

  clockType clock2;
    clock2.setTime (13,22,12);
    clock2.printTime(); //maybee use "this" like in .js to print "clock2" before time?

  tOrF = clock1.equalTime(clock2);
    if (tOrF == 0){
      cout << "clocks match: false" << endl;
    } else {
      cout << "clocks match: true" << endl;
    }

  clock2.setTime (24,60,20);
    cout << "new 'clock2' time is:" << endl;
    clock2.printTime();


  tOrF = clock1.equalTime(clock2);
    if (tOrF == 0){
      cout << "clocks match: false" << endl;
    } else {
      cout << "clocks match: true" << endl;
    }

  cout << "Please enter 'clock2' hr: ";
    cin >> a;
  cout << "Please enter 'clock2' min: ";
    cin >> b;
  cout << "Please enter 'clock2' sec: ";
    cin >> c;
    clock2.setTime(a, b, c);
  cout << "Clock 2 time is: ";
    clock2.printTime();

//test incrementation of time here:
  clock2.setTime(12, 13, 14);
    clock2.incrementHours();
    clock2.incrementMinutes();
    clock2.incrementSeconds();
//clock 2 should print 13,14,15
  clock2.printTime();

}
