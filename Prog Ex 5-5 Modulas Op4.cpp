#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {

    int a, b, c;

    cout << "Enter two integers: " << endl;
    cin >> a >> b;

    if (a > b){
            for(int x = a; x >= b; x--){
                c = x * 3;
                    cout << c << endl;
            } //cout << endl;
            for(int x = a; x >= b; x--){
                c = x * 5;
                    cout << c << endl;
            }
    } else {
            for(int x = a; x <= b; x++){
                c = x * 3;
                    cout << c << endl;
            } //cout << endl;
            for(int x = a; x <= b; x++){
                c = x * 5;
                    cout << c << endl;
            }
    }
    return 0;
}

