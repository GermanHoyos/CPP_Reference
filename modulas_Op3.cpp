#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    int a, b;
    int c; //test var


    cout << "Enter two integers: " << endl;
    cin >> a >> b;
    cout <<"your numbers are " << a <<" and " << b;

    if (a > b){
        cout << ": first # > second #" << endl;

            for(int x = a; x >= b; x--){
                c = x * 3;
                cout << x <<" * 3 = int: " << c << endl;
            }

            cout << endl;

            for(int x = a; x >= b; x--){
                c = x * 5;
                cout << x <<" * 5 = int: " << c << endl;
            }

    } else {
        cout << ": first # < second #" << endl;

            for(int x = a; x <= b; x++){
                c = x * 3;
                cout << x <<" * 3 = int: " << c << endl;
            }

            cout << endl;

            for(int x = a; x <= b; x++){
                c = x * 5;
                cout << x <<" * 5 = int: " << c << endl;
            }

    }

    return 0;
}
//multiples of 3 are: (3)*(3)=(multiple) or (3)*(x)=((multiple) if % = 0)
//multiples of 5 are: (5)*(5)=(multiple) or (5)*(x)=((multiple) if % = 0)

//modulus example: x=5 y=2 z=x%y z=1(remainder)
//x=11 % 3; x =2
//note: modulus may not be necessary for this program

//int(a) loop -> int(b) ("inclusive" meaning include a and b)
//if (a) > (b) {decrement}
//if (a) < (b) {increment}

//Write a program that prompts the user to enter two integers.
//The program outputs how many numbers are multiples of 3 and
//how many numbers are multiples of 5 between the two integers
//(inclusive).

//Correct output when first number is smaller: if (a) > (b) {decrement}
//Correct output when second number is smaller: if (a) < (b) {increment}
