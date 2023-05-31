#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdio.h>      /* printf */
#include <assert.h>     /* assert */
using namespace std; // <--- must be included in all .cpp files

//"clockType" bluprint needs to be in a "header file" ex: clockType.h
class clockType{
public:
 void setTime(int, int, int);           //This modifies values
 void getTime(int&, int&, int&) const;  //This retrieve values
 void printTime() const;                //This retrieves values
 void incrementSeconds();               //This modifies values
 void incrementMinutes();               //This modifies values
 void incrementHours();                 //This modifies values
 //"Add functions - setHours, setMinutes, setSeconds"
 void setHours(int a);
 void setMinutes(int b);
 void setSeconds(int c);
 //This modifies values
 //"Add functions - setHours, setMinutes, setSeconds" (make inline)
 inline int getHours() const{
    return hr;
 };
 inline int getMinutes() const{
    return min;
 };
 inline int getSeconds() const{
    return sec;
 };
 //Function to compare two instantiations
 bool equalTime(const clockType&) const;
 private:
 //Only accessable through class object reference
   int hr;
   int min;
   int sec;
};

//The following function methods should be in an "implamentation" file
void clockType::setTime(int a, int b, int c){
  if (0 <= a && a < 24){
    hr = a;
  } else {
    hr = 0;
  }

  if (0 <= b && b < 60){
    min = b;
  } else {
    min = 0;
  }

  if (0 <= c && c < 60){
    sec = c;
  } else {
    sec = 0;
  }

}

//Pass these variables by "referece" -> "int& a" affects the external var from
//within the function (research.js equivalnt)
//Http://www.cplusplus.com/doc/tutorial/functions/
//"Const" unsures the ref parameters are not modified by this particular function
void clockType::getTime(int& a, int& b, int& c) const{
  a = hr;  //can be set with "cin >>"
  b = min; //can be set with "cin >>"
  c = sec; //can be set with "cin >>"
}

void clockType::printTime() const{
  cout << hr << ":" << min << ":" << sec;
  cout << endl;
}

//Change hr somehow, maybee hr++ if less than 24?
void clockType::incrementHours(){
  hr++;
  if (hr > 23) {
    hr = 0; //24 hour counter cycle
  }
}

//Change min somehow, maybee min++ if less than 60?
void clockType::incrementMinutes(){
  min++;
  if (min > 59){
    min = 0; //60 min counter cycle
  }
}

//Change sec somehow, maybee sec++ if les than 60?
void clockType::incrementSeconds(){
  sec++;
  if (sec > 59){
    sec = 0; //60 sec counter cycle
  }
}

//Set a single val
void clockType::setHours(int a){
  hr = a;
};

//Set a single val
void clockType::setMinutes(int b){
  min = b;
};

//Set a single val
void clockType::setSeconds(int c){
  sec = c;
};

//This function will compare two clocks and return t/f if they are "equal"
//This function does not change any values / hence "const"
//Compare clock1.equalTime call using the param clockParam to clockParam
//ClockParam is simply another instanstiation of the clockTypeCLass like .js object instantiations
bool clockType::equalTime(const clockType& clockParam) const {
  if (hr == clockParam.hr && min == clockParam.min && sec == clockParam.sec){
    return true;
  } else {
    return false;
  }
}

//MAIN--------------------------------------------------------------------------
int main() {

//Test for "get...()" functions
  clockType myClock;
    myClock.setTime(10, 5, 50);
    cout << "'get()' functions test -> ";
    cout << myClock.getHours() << ":" << myClock.getMinutes() << ":" << myClock.getSeconds() << endl << endl;

//Test for "set...()" functions
  cout << "'set()' functions test -> ";
    myClock.setHours(1);
    myClock.setMinutes(2);
    myClock.setSeconds(3);
    cout << myClock.getHours() << ":" << myClock.getMinutes() << ":" << myClock.getSeconds() << endl << endl;

//Test for printTime() func
  clockType clock1;
    clock1.setTime (24,60,20);
    cout << "'printTime()' func test -> ";
    clock1.printTime();
    cout << endl;

//Test for multiple object instanstiation
  clockType clock2;
    clock2.setTime (13,22,12);
    cout << "'instanstiation' of objects test -> ";
    clock2.printTime();
    cout << endl;

//Test for equalTime() func
  bool tOrF; //true or false
    tOrF = clock1.equalTime(clock2);
      if (tOrF == 0){
        cout << "'equalTime()' func test returns -> FALSE" << endl;
      } else {
        cout << "'equalTime()' func test returns -> TRUE" << endl;
      } cout << endl;

//Test of incrementation...() functions
  clock2.setTime(1, 1, 1);
    clock2.incrementHours();
    clock2.incrementMinutes();
    clock2.incrementSeconds();
    cout << "'increment()' from 1 1 1; functions test -> ";
    clock2.printTime();
    cout << endl << endl << endl;

    return 0;
}

//end all functionality tested
