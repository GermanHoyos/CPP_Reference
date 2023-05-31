#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    int a, b;

    cout << "Enter two integers: ";
    cin >> a >> b;
    cout <<"your numbers are " << a <<" and " << b;

    if (a > b){
        cout << ": first # > second #" << endl;
        for(int x = a; x >= b; x--){
            cout <<"loop " << x << endl;
        }
    } else {
        cout << ": first # < second #" << endl;
        for(int x = a; x <= b; x++){
            cout <<"loop " << x << endl;
        }
    }

    return 0;
}
//multiples of 3 are: (3)*(3)=(multiple) or (3)*(x)=((multiple) if % = 0)
//multiples of 5 are: (5)*(5)=(multiple) or (5)*(x)=((multiple) if % = 0)
//modulus example: x=5 y=2 z=x%y z=1(remainder)

//int(a) loop -> int(b) ("inclusive" meaning include a and b)
//if (a) > (b) {decrement}
//if (a) < (b) {increment}

//Write a program that prompts the user to enter two integers.
//The program outputs how many numbers are multiples of 3 and
//how many numbers are multiples of 5 between the two integers
//(inclusive).

//Correct output when first number is smaller: if (a) > (b) {decrement}
//Correct output when second number is smaller: if (a) < (b) {increment}
