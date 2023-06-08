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
    cout << "(PassByRef) X was changed to: " << x << endl;
    cout << "(PassByRef) Y was changed to: " << y << endl;

    int a = passByVal(z);
    cout << "(PassByVal) Z stays the same: " << z << endl;
    cout << "(PassByVal) A was changed to: " << a << endl;

 return 0;
}


