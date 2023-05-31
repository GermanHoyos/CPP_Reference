#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

double totalCent(int feet, int inches)
{
    double feet_cent, inch_cent, total_cent;
    feet_cent = feet * 30.48;
    inch_cent = inches * 2.54;
    total_cent = feet_cent + inch_cent;

    return total_cent;
}

int main()
{

    int feet;
    int inches;
    double finalCent;

    cin >> feet;
    cin >> inches;

    if (feet > -1 || inches > -1)
    {
        finalCent = totalCent(feet, inches);
        cout << finalCent;
    }
    else
    {
        cout << "error";
    }

    return 0;
}
