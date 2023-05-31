
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main() {

//*************************************************************
class Student { //*********************************************
    public:
        string student_ID, first_name;

    // setters
        void set_student_ID(string student_ID){ this->student_ID = student_ID; }
        void set_first_name(string first_name){ this->first_name = first_name;}
    // getters
        string get_student_ID() { this->student_ID = student_ID; };
        string get_first_name() { this->first_name = first_name; };
    // constructor
        Student(string student_ID, string first_name){
            this-> student_ID = student_ID;
            this-> first_name = first_name;
        };

}; //**********************************************************
//*************************************************************


//*************************************************************
class Roster { //**********************************************
    public:
        string str_student_data;
         Student* classRosterArray[5];

    // "studentData[]" parser / then call add()
        void parse(string arrRow){
            for (char c : arrRow){
                cout << "[" << c << "]";
            }
        };
    // "classRosterArray[]" builder / new "Student" object builder
        void add(string student_ID, string first_name) {

        };
    // remove student from "classRosterArray[]" or "Student"
        void remove() {

        };
    // print current state of roster
        void printAll(){

        }
    // constructor
        Roster(){};
 }; //*********************************************************
//*************************************************************

//array
    const string studentData[] = {
        "A1, John",
        "A2, Suzan",
        "A3, Jack",
        "A4, Erin",
        "A5, German"
    };
//console out array
    for (int i = 0; i < 5; i++){
        cout << &studentData[i] << ": " << studentData[i] << endl;
    }   cout << endl;

//instantiate roster
    Roster roster;

//parse array
    for (int i = 0; i < 5; i++){
        roster.parse(studentData[i]);
    }









return 0;
}



