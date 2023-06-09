// classes and uniform initialization
#include <iostream>
using namespace std;

// "::" scope operator

class Circle {
    double radius;
  public:
    Circle(double r) { radius = r; }
    double circum() {return 2*radius*3.14159265;}
};

int main () {
  Circle foo (10.0);   // functional form
  Circle bar = 20.0;   // assignment init.
  Circle baz {30.0};   // uniform init.
  Circle qux = {40.0}; // POD-like

  cout << "foo's circumference: " << foo.circum() << '\n';
  return 0;
}


// Rectangle rectb;   // default constructor called
// Rectangle rectc(); // function declaration (default constructor NOT called)
// Rectangle rectd{}; // default constructor called
