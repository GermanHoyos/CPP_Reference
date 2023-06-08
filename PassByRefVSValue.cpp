#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

void passByRef(int& a, int& b){
    a = 100;
    b = 200;
}

int passByVal(int a){
    a = 300;
    return a;
}

int main()
{

    int x = 5;
    int y = 10;
    int z = 15;

    passByRef(x,y);
    cout << "(PassByRef) X was changed to: " << x << endl; //100
    cout << "(PassByRef) Y was changed to: " << y << endl; //200

    int a = passByVal(z);
    cout << "(PassByVal) Z stays the same: " << z << endl; //15
    cout << "(PassByVal) A was changed to: " << a << endl; //300

 return 0;
}


