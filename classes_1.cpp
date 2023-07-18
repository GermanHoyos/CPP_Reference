#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

class Rectangle {
    int width, height; //private to rectangle class
    public:            // functions declared after this line are public / global
    void set_values (int,int);
    int area() {
      return width*height;
    }
};

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}

int main() {
  Rectangle rect; // instantiate object called rect with class Rectangle Blueprint
  rect.set_values (3,4);
  cout << "area: " << rect.area();
  return 0;
}
