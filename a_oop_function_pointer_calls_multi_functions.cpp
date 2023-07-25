#include <iostream>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int main() {
    int (*mathOperation)(int, int) = nullptr;
    int a, b;
    char operatorSymbol;

    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;
    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> operatorSymbol;

    switch (operatorSymbol) {
        case '+':
            mathOperation = add;
            break;
        case '-':
            mathOperation = subtract;
            break;
        case '*':
            mathOperation = multiply;
            break;
        case '/':
            mathOperation = divide;
            break;
        default:
            std::cout << "Invalid operator!" << std::endl;
            return 0;
    }

    int result = mathOperation(a, b);
    std::cout << "Result: " << result << std::endl;

    return 0;
}

