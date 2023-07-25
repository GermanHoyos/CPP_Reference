//condesending
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
        void set_first_name(string first_name){ this->first_name = first_name; }
    // getters
        string get_student_ID() { return this->student_ID; }
        string get_first_name() { return this->first_name; }
        string print() {
            cout << this->get_student_ID();
        }
    // constructor
        Student(string student_ID, string first_name){
            this-> student_ID = student_ID;
            this-> first_name = first_name;
        }
}; //**********************************************************
//*************************************************************


//*************************************************************
class Roster { //**********************************************
    public:
        int delimCount = 0;
        string str_student_data;
        Student* classRosterArray[5];

    // "studentData[]" parser / then call add()
        void parse(int i, string arrRow){
            string sendID, sendFName;
            for (char c : arrRow){
                //cout << c;// print all chars
                if (c == ','){ delimCount++; }
                if (delimCount == 0){
                    sendID = arrRow.substr(0,2);
                }
                if (delimCount == 1){
                    sendFName = arrRow.substr(4,4);
                }

            } cout << endl; // break by index
            delimCount = 0;
            add( i , sendID, sendFName);
        };
    // "classRosterArray[]" builder / new "Student" object builder
        void add(int i, string student_ID, string first_name) {

            cout << "index is: "<< i << "  address is: " ;
            classRosterArray[i] = new Student (student_ID, first_name);
            cout << classRosterArray[i];
            cout << " student_ID is: " << student_ID << " first_name is: " << first_name;
        };

    // remove student from "classRosterArray[]" or "Student"
        void remove() {

        };
    // print current state of roster
        void printAll(){
            for (int i = 0; i < 5; i++){
               //how can I dereference "classRosterArray[i]" to see instance of student object?
               cout <<  "address is: " << classRosterArray[i] << " student is: "<< classRosterArray[i]->print() << endl;
            }
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
    }

//instantiate roster
    Roster roster;

//parse array
    for (int i = 0; i < 5; i++){
        roster.parse(i, studentData[i]);
    }   cout << endl << endl;

//print array
    roster.printAll();
    cout << endl;

    //cout << roster.classRosterArray[2]->student_ID;
    //cout << endl;




return 0;
}



