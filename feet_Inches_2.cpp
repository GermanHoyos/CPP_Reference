#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    int feet, inches;
    double feet_cent, inch_cent, total_cent; //feet * 30.48, inches * 2.54

    cout << "Enter length in Feet: " << endl;
    cin >> feet;
    cout << "Enter length in inches: " << endl;
    cin >> inches;

    try
    {
        if (feet < 0 || inches < 0)
        {
            throw 0;
        }
    }
    catch (int x)
    {
        cout << "A non positive number is entered" << endl;
    }

    feet_cent = feet * 30.48;
    inch_cent = inches * 2.54;
    total_cent = feet_cent + inch_cent;

    cout << "Total centimeteres: " << total_cent;

    return 0;
}
