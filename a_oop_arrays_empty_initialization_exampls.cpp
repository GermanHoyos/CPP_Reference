#include <iostream>

int main() {
    // 1. Default initialization
    int arr1[5]; // Elements are uninitialized, holding garbage values

    // 2. Initialize with zero using brace initialization
    int arr2[5] = {}; // All elements are set to zero

    // 3. Initialize with zero using value initialization
    int arr3[5]{}; // All elements are set to zero

    // 4. Initialize with zero using memset (requires <cstring> header)
    #include <cstring>
    int arr4[5];
    memset(arr4, 0, sizeof(arr4));

    // 5. Initialize with zero using std::fill (requires <algorithm> header)
    #include <algorithm>
    int arr5[5];
    std::fill(arr5, arr5 + 5, 0);

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

