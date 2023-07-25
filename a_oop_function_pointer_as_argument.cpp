#include <iostream>
#include <vector>
#include <algorithm>

// Function that takes a function pointer as an argument "HIGHER ORDER"
/*
The term "higher-order" refers to functions that can accept other
functions as arguments or return functions as results. In C++, this
is achieved through the use of function pointers or function objects
(functors) that encapsulate the behavior of a function.
*/
void applyFunction(const std::vector<int>& numbers, void (*func)(int)) {
    for (int number : numbers) { // for (variable declaration : range expression)
        func(number); //whichever func was passed via pointer, apply to number
    }
}

// Function that prints a number
void printNumber(int number) {
    std::cout << number << " ";
}

// Function that doubles a number
void doubleNumber(int& number) {
    number *= 2;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Applying the printNumber function to each element in the vector
    applyFunction(numbers, printNumber);
    std::cout << std::endl;

    // Applying the doubleNumber function to each element in the vector
    applyFunction(numbers, doubleNumber);

    // Printing the modified vector
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
