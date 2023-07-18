
#include <iostream>

using namespace std;

class Car {
public:
    virtual void start() = 0; // Abstract method
    virtual void stop() = 0; // Abstract method
    virtual void drive() = 0; // Abstract method
};

class SportsCar : public Car {
public:
    void start() override {
        std::cout << "The sports car starts with a powerful engine sound.\n";
    }

    void stop() override {
        std::cout << "The sports car comes to a smooth stop.\n";
    }

    void drive() override {
        std::cout << "The sports car zooms down the road at high speed.\n";
    }
};

class SedanCar : public Car {
public:
    void start() override {
        std::cout << "The sedan car starts quietly.\n";
    }

    void stop() override {
        std::cout << "The sedan car stops gently.\n";
    }

    void drive() override {
        std::cout << "The sedan car cruises comfortably on the road.\n";
    }
};

int main() {
    Car* car1 = new SportsCar();
    Car* car2 = new SedanCar();

    car1->start();
    car1->drive();
    car1->stop();

    car2->start();
    car2->drive();
    car2->stop();

    delete car1;
    delete car2;

    return 0;
}


/*

In the example above, we have an abstract base class
Car that defines three abstract methods: start(),
stop(), and drive(). These methods don't have any
implementation in the base class but are meant to
be overridden by derived classes.

We then have two derived classes: SportsCar and
SedanCar. These classes inherit from the Car class
and provide their own specific implementations for
the abstract methods.

In the main() function, we create two pointers of
type Car* and instantiate them with objects of the
derived classes. Since the base class has abstract
methods, it cannot be instantiated directly.

The start(), drive(), and stop() methods are called
on the objects using the base class pointer. However,
the actual behavior executed is determined by the
derived class's implementation of these methods.

Abstraction allows us to create a generalized interface
(Car class) that hides the internal complexities and
provides a way to interact with different types of cars
(SportsCar and SedanCar). We can use the common methods
(start(), stop(), drive()) without worrying about the
specific implementation details of each car type.

This concept of abstraction helps us simplify complex
systems by focusing on essential features and behaviors
while hiding unnecessary details, making it easier to
understand and work with objects in our programs.

*/
