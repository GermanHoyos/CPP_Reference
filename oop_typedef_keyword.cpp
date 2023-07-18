//https://youtu.be/NPZcP_8nhrg
#include <iostream>
using namespace std;

//https://cplusplus.com/reference/cstdint/
//above site is a reference to the pre built library with typedefs

typedef unsigned int uns_t; // typedef = reserved keyword that gives an existing datatype a "nickname"
//also known as ALIAS

struct myPoint {
    double x, y;
};

typedef struct myPoint myPoint;

//OR CAN DO THIS THANKS TO TYPEDEF

typedef struct myPoint2 {
    double x, y;
} myPoint2;

int main()
{
    uns_t age = 90;
    cout<<"Age: " << age << endl;

    myPoint p1; //thanks to typedef the "struc" is not needed / ALIAS
    p1.x = 10;
    p1.y = 11;
    cout<< "Point 1: " << p1.x << " " << p1.y << endl;


    myPoint2 p2;
    p2.x = 12;
    p2.y = 13;
    cout << "Point 2: " << p2.x << " " << p2.y << endl;

}
