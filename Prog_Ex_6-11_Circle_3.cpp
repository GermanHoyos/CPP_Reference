#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

double distance(int x1, int y1, int x2, int y2){
    double r;
    double distance;
        r = sqrt(pow((x2 - x1),2)+pow((y2 - y1),2));
        distance = r * 2;
            return distance;
}

double radius(int x1, int y1, int x2, int y2){
    double r;
        r = sqrt(pow((x2 - x1),2)+pow((y2 - y1),2));
            return r;
}

double circumference(double cRadius){
    double circumference;
        circumference = 2 * 3.1416 * cRadius; //2(PI)r
            return circumference;
}

double area(double cRadius){
    double area;
        area = 3.1416 * pow(cRadius, 2); //(PI)r^2
            return area;
}

int main() {
    int x1, y1; //first point
    int x2, y2; //second point

    double cRadius;
    double cDiam;
    double cCircumf;
    double cArea;

    double tst = 2.00;

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
        //cout << fixed << showpoint;
        cout << setprecision (2) << fixed;
        cout << "Radius = " << cRadius << endl;

//find diameter (same as distance)
    cDiam = distance(x1, y1, x2, y2);
        cout << "Distance = " << cDiam << endl;

//find circumf
    cCircumf = circumference(cRadius);
        cout << "Circumference = " << cCircumf << endl;

//find area
    cArea = area(cRadius);
        cout << "Area = " << cArea << endl;

 return 0;
}
