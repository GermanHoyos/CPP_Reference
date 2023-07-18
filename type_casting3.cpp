#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int num;

    cout << "Enter an integer between 0 and 35:" << endl;
    cin >> num;

    if (num <= 9) {
        cout << num << endl;
    } else {
        //Example cin = '11'.... (97  + (11  - 10)) } = 98 which is "b"
        cout << static_cast<char>('A' + (num - 10)) << endl; // cast into a CHAR
        //      operator<dataType> (expression)
    }

  return 0;
}
//http://www.cplusplus.com/forum/beginner/78338/

//EXAMPLES
/*

static_cast<double> (25) => 25.0
static_cast<double> (8+3) = (11) => 11.0
static_cast<double> (15) / 2 = 15.0 / 2 => 7.5
static_cast<double> (15 / 2) = (7) => 7.0
static_cast<int> ('A') => 65
static_cast<int> ('8') => 56 // cast the charactor 8 into its dec value according to the ascii chart
static_cast<char> (65) => 'A'
static_cast<char> (56) => '8'

static_cast<int> (7.8 + static_cast<double>(15) / 2)
    = static_cast<int> (7.8 + 15.0 / 2)
    = static_cast<int> (7.8 + 7.5)
    = static_cast<int> (15.3)
    = 15

*/

