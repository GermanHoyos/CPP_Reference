#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;




int main() {

    string strVar;

    getline (cin, strVar);

    for (char range : strVar){
            cout << range;
    }

return 0;
}

