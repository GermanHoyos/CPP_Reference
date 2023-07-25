#include <iostream>

// Function to print a number
void printNumber(int num) {
    std::cout << "Number: " << num << std::endl;
}

int main() {
    // Declare a function pointer variable
    void (*ptr)(int);

    // Assign the address of the printNumber function to the function pointer
    ptr = printNumber;

    // Call the function through the function pointer
    ptr(42);

    return 0;
}

