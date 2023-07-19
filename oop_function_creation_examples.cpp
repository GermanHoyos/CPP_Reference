#include <iostream>

// Function Declaration and Definition
int add(int a, int b) {
    return a + b;
}

// Function Declaration and Definition with Default Arguments
int multiply(int a, int b = 1) {
    return a * b;
}

// Function Declaration and Definition in a Class (Member Function)
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
};

// Function Declaration and Definition in a Class (Static Member Function)
class MathUtils {
public:
    static int square(int num) {
        return num * num;
    }
};

// Function Declaration and Definition using Function Pointers
// int (*mathOperation)(int, int) = nullptr;
int (*operation)(int, int) = &add; //see "function_pointer_calls_multi_functions.cpp"


// Function Declaration and Definition using Lambda Expressions
// particularly useful in situations where you need to define a small, one-time function
// without the need to declare a named function separately.
auto lambdaMultiply = [](int a, int b) -> int {
    return a * b;
};

int main() {
    // Function Invocation
    int result1 = add(3, 5);
    int result2 = multiply(2, 4);

    Calculator calc;
    int result3 = calc.add(7, 3);

    int result4 = MathUtils::square(5);

    int result5 = operation(4, 6);

    int result6 = lambdaMultiply(2, 3);

    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;
    std::cout << "Result 3: " << result3 << std::endl;
    std::cout << "Result 4: " << result4 << std::endl;
    std::cout << "Result 5: " << result5 << std::endl;
    std::cout << "Result 6: " << result6 << std::endl;

    return 0;
}

