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

//distance func below has redundant code per radius func
//however per the HW instructions it must take 4 params
//therefore the only logical use for 4 params is as follows
int distance (int x1, int y1, int x2, int y2){
    float r;
    float distance;
        r = sqrt(pow((x2 - x1),2)+pow((y2 - y1),2));
        distance = r * 2;
            return distance;
}

float circumference(float cRadius){
    float circumference;
        circumference = 2 * 3.1416 * cRadius; //2(PI)r
            return circumference;
}

float area(float cRadius){
    float area;
        area = 3.1416 * pow(cRadius, 2); //(PI)r^2
            return area;
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
        cout << fixed << showpoint;
        cout << setprecision(3);
        cout << "Radius = " << cRadius << endl;

//find diameter (same as distance)
    cDiam = distance(x1, y1, x2, y2);
        cout << fixed << showpoint;
        cout << setprecision(3);
        cout << "Distance = " << cDiam << endl;

//find circumf
    cCircumf = circumference(cRadius);
        cout << fixed << showpoint;
        cout << setprecision(3);
        cout << "Circumference = " << cCircumf << endl;

//find area
    cArea = area(cRadius);
        cout << fixed << showpoint;
        cout << setprecision(3);
        cout << "Area = " << cArea << endl;

 return 0;
}





