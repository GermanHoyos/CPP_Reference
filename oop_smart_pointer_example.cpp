#include <iostream>
#include <memory>

class MyClass {
public:
    void doSomething() {
        std::cout << "Doing something..." << std::endl;
    }
};

int main() {
    // Create a unique_ptr and dynamically allocate an object
    std::unique_ptr<MyClass> ptr(new MyClass); // see notes below program
    //

    // Use the object through the smart pointer
    ptr->doSomething();

    // No need to manually delete the object, it will be automatically deleted when the unique_ptr goes out of scope

    return 0;
}

//QUESTION:
/*
in the main function on the line where the unique_ptr is used,
this not only creates a pointer to the class my class but also
instantiates an object using said class?
*/

//ANSWER:
/*

Yes, that's correct. In the main function,
the line std::unique_ptr<MyClass> ptr(new MyClass);
creates a std::unique_ptr named ptr and dynamically
allocates an object of type MyClass using the new keyword.

The new MyClass expression allocates memory to hold
an object of type MyClass and constructs the object
using the default constructor. The std::unique_ptr
takes ownership of this dynamically allocated object.

So, in one line, we have both created a pointer (ptr)
to the class MyClass and instantiated an object of MyClass.
The std::unique_ptr manages the ownership and lifetime
of this object.

With the std::unique_ptr, you don't need to manually delete
the object using delete. The memory will be automatically
released and the object will be destroyed when the std::unique_ptr
goes out of scope, ensuring proper cleanup and preventing memory leaks.
*/
