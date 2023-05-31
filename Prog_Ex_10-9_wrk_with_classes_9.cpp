#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "clockType.h"
using namespace std;

void clockType::set_3_vals(int a, int b, int c){ // <-- kind of like an object method (could have be described inside object)
  hr = a;
  min = b;
  sec = c;
}

int main() {

  clockType firstC;

  firstC.set_3_vals (24,60,20);

  cout << "Time is: " << firstC.showHr() << ":" << firstC.showMin() << ":" << firstC.showSec() << endl;
}
