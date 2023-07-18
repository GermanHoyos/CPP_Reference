#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5};  // Declare and initialize an array of integers
    int* ptr = arr;               // Declare a pointer and assign the address of the array

    std::cout << "Elements of the array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << *ptr << " ";   // Access and print the value using the pointer
        ptr++;                     // Move the pointer to the next element
    }

    std::cout << std::endl;

    return 0;
}

