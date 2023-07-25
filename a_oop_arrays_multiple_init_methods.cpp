#include <iostream>
#include <array>

int main() {
    // 1. Initialize with values explicitly
    int arr1[] = {1, 2, 3, 4, 5};

    // 2. Initialize with all elements set to zero
    int arr2[5] = {0};

    // 3. Initialize with some elements explicitly, others set to zero
    int arr3[5] = {1, 2};

    // 4. Initialize using loop
    int arr4[5];
    for (int i = 0; i < 5; i++) {
        arr4[i] = i + 1;
    }

    // 5. Initialize using std::array (from <array> header)
    std::array<int, 5> arr5 = {1, 2, 3, 4, 5};

    // Print the arrays
    for (int i = 0; i < 5; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << arr4[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << arr5[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

