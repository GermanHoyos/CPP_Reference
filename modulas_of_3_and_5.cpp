#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;


//Write a program that prompts the user to enter two integers.
//The program outputs how many numbers are multiples of 3 and
//how many numbers are multiples of 5 between the two integers
//(inclusive).

int main() {
    int a, b;       //user inputs
    int three = 0;  //count success attempts for 3's
    int five = 0;   //count success attempts for 5's

    cout << "Enter two integers: ";
    cin >> a >> b;

    if (a > b){
        for(int x = a; x >= b; x--){
            if(x % 3 == 0){
                three++;
            }
            if(x % 5 == 0){
                five++;
            }
        }
        cout << three << endl;
        cout << five << endl;
    } else {
        for(int x = a; x <= b; x++){
            if(x % 3 == 0){
                three++;
            }
            if(x % 5 == 0){
                five++;
            }
        }
        cout << three << endl;
        cout << five << endl;
    }
    return 0;
}
//multiples of 3 are: (3)*(3)=(multiple) or (3)*(x)=((multiple) if % = 0)
//multiples of 5 are: (5)*(5)=(multiple) or (5)*(x)=((multiple) if % = 0)

//modulus example: x=5 y=2 z=x%y z=1(remainder)
//x=11 % 3; x =2

//int(a) loop -> int(b) ("inclusive" meaning include a and b)
//if (a) > (b) {decrement}
//if (a) < (b) {increment}


//Correct output when first number is smaller: if (a) > (b) {decrement}
//Correct output when second number is smaller: if (a) < (b) {increment}
