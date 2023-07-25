//https://youtu.be/qrJjFN4Igfw
#include <iostream>
using namespace std;

template<typename T> //"T" is a generic data type

//OR CAN DO THIS:

template<class Type> //class is basically a usr defined data type

void Swap(T& a, T& b) //generic function
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 5, b = 7;
    cout << a << " - " << b << endl;
    Swap(a, b);
    cout << a << " - " << b << endl;

    //OR CAN DO THIS:

    cout << a << " - " << b << endl;
    Swap<int>(a, b);
    cout << a << " - " << b << endl;

    char c = 'c', d = 'd';
    cout << c << " - " << d << endl;
    Swap<char>(c, d);
    cout << c << " - " << d << endl;
}
