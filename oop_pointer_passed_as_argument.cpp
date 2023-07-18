#include <iostream>
#include <memory>

class MyClass {
public:
    void doSomething() {
        std::cout << "Doing something!\n";
    }
};

void processObject(std::unique_ptr<MyClass> obj) {
    // Use the object
    obj->doSomething();
    // No need to delete obj, it will be automatically destroyed when the function ends
}

int main() {
    std::unique_ptr<MyClass> ptr(new MyClass);

    // Pass the ownership of ptr to the function
    processObject(std::move(ptr)); //MOVE keyword, see below

    // ptr is now nullptr because ownership has been transferred to the function

    return 0;
}


//MOVE =
/*
    In C++, std::move is a utility function defined in the <utility> header that enables
the transfer of ownership from one object to another. It is used with smart pointers,
like std::unique_ptr, to explicitly indicate that ownership is being transferred rather than copied.

In the example provided, std::move is used to transfer ownership of the ptr object to the
obj parameter of the processObject function. By using std::move(ptr) as the argument, ptr is treated
as an rvalue reference, allowing the contents (in this case, the raw pointer managed by
std::unique_ptr) to be moved into the obj parameter.

This transfer of ownership is important because std::unique_ptr enforces the unique ownership
of a dynamically allocated object. By transferring ownership, we ensure that only one
std::unique_ptr manages the object at a time. After the transfer, the original ptr becomes
a null pointer, indicating that it no longer owns any object.

Using std::move in this context allows for efficient resource management and avoids unnecessary
copying of the std::unique_ptr. It explicitly communicates the intent to transfer ownership and
makes the code more readable and concise.
*/
