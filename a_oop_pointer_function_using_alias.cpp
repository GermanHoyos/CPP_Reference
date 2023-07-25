#include <iostream>

// Function pointer type
typedef void (*FunctionPointer)(int);

// Function to print a number
void printNumber(int num) {
    std::cout << "Number: " << num << std::endl;
}

int main() {
    // Declare a function pointer variable
    FunctionPointer ptr;

    // Assign the address of the printNumber function to the function pointer
    ptr = printNumber;

    // Call the function through the function pointer
    ptr(42);

    return 0;
}

