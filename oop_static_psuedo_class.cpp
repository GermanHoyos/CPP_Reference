class MyClass {
public:
    static int staticVariable; // Static member variable
    int regularVariable; // Regular member variable

    static void staticFunction() { // Static member function
        // Access staticVariable
        staticVariable = 10;

        // Cannot access regularVariable
        // regularVariable = 20; // Error: regularVariable is not a static member
    }

    void regularFunction() {
        // Access staticVariable
        staticVariable = 30;

        // Access regularVariable
        regularVariable = 40;
    }
};

int MyClass::staticVariable = 0; // Definition of the static member variable

int main() {
    MyClass::staticVariable = 5; // Accessing static member variable without an instance

    MyClass obj1;
    obj1.regularFunction(); // Accessing member functions and variables using an object

    MyClass::staticFunction(); // Accessing static member function without an instance

    return 0;
}

