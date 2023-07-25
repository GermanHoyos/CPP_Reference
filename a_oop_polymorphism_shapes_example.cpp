#include <iostream>

using namespace std;

// Base class
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape." << endl;
    }
};

// Derived class 1
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a rectangle." << endl;
    }
};

// Derived class 2
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

int main() {

    //"base class pointer" shape*
    Shape* shape1 = new Rectangle();
    Shape* shape2 = new Circle();
    //if we did not use pointers and instantiated
        //Rectangle shape1;
        //Circle shape2;
    //then draw() would produce: "Drawing a shape." for both objects.


    shape1->draw(); // Output: "Drawing a rectangle."
    shape2->draw(); // Output: "Drawing a circle."

    delete shape1;
    delete shape2;

    return 0;
}

/*

In this example, the Shape class is the base class,
while the Rectangle and Circle classes are derived
classes. The Shape class has a virtual draw() method
that can be overridden by the derived classes.

In the main() function, we create two pointers of type
Shape* that can point to objects of Rectangle and Circle
classes. We assign a Rectangle object to shape1 and a
Circle object to shape2. When we call the draw()
method using these pointers, the appropriate draw()
method of the corresponding derived class is invoked,
based on the type of object they are pointing to.

This demonstrates polymorphism, as we can treat objects
of different derived classes (Rectangle and Circle) as
objects of the base class (Shape). This allows for code
reusability and flexibility, as we can write generic code
that operates on the base class and still have it work
correctly with derived class objects.

*/
