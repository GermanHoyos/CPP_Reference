#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

int radius (int x1, int y1, int x2, int y2){
    float r;
    r = sqrt(pow((x2 - x1),2)+pow((y2 - y1),2));
return r;
}

int main() {
    int x1, y1; //first point
    int x2, y2; //second point

    int cRadius;
    int cDiam;
    int cCircumf;
    int cArea;

//prompt for center and point
    cout << "Center X: ";
    cin >> x1;
    cout << "Center Y: ";
    cin >> y1;

    cout << "Point X: ";
    cin >> x2;
    cout << "Point Y: ";
    cin >> y2;

//find radius
    cRadius = radius(x1, y1, x2, y2);
    cout << "sqrt(("<<x2<<" - "<<x1<<")^2 + ("<<y2<<" - "<<y1<<")^2)" <<  endl;
    cout << fixed << showpoint;
    cout << setprecision(3);
    cout << cRadius;

/*
//find diameter (same as distance)
    cDiam = diameter();
    cout << cDiam;

//find circumf
    cDist = circumference();
    cout << cDist;

//find area
    cDist = area();
    cout << cDist;
*/
 return 0;
}





