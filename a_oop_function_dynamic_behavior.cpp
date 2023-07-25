#include <iostream>

// Function pointer type
typedef void (*Operation)(int, int);

// Add function
void add(int a, int b) {
    std::cout << "Addition: " << a + b << std::endl;
}

// Subtract function
void subtract(int a, int b) {
    std::cout << "Subtraction: " << a - b << std::endl;
}

// Multiply function
void multiply(int a, int b) {
    std::cout << "Multiplication: " << a * b << std::endl;
}

// Calculator function
void calculate(int a, int b, Operation op) {
    op(a, b);  // Perform the operation
}

int main() {
    int num1 = 10;
    int num2 = 5;

    // Calculate using different operations
    calculate(num1, num2, add);
    calculate(num1, num2, subtract);
    calculate(num1, num2, multiply);

    return 0;
}

