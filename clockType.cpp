#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "clockType.h"

void clockType::set_3_vals(int a, int b, int c){ // <-- kind of like an object method (could have be described inside object)
  hr = a;
  min = b;
  sec = c;
}
