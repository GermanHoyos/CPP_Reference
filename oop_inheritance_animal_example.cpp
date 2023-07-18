#include <iostream>

using namespace std;

// Parent class
class Animal {
public:
    void eat() {
        cout << "The animal is eating." << endl;
    }
};

// Child class, inherits from Animal
class Dog : public Animal {
public:
    void bark() {
        cout << "The dog is barking." << endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();  // The dog can eat because it inherited the eat() method from the Animal class
    myDog.bark(); // The dog has its own method bark()

    return 0;
}

