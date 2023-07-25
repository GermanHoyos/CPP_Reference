#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    // Lambda function with capture by value
    auto lambda1 = [x, y]() {
        std::cout << "Captured values: x = " << x << ", y = " << y << std::endl;
    };

    // Lambda function with capture by reference
    auto lambda2 = [&x, &y]() {
        x += 5;
        y += 10;
        std::cout << "Updated values: x = " << x << ", y = " << y << std::endl;
    };

    lambda1(); // Output: Captured values: x = 10, y = 20
    lambda2(); // Output: Updated values: x = 15, y = 30

    std::cout << "Original values: x = " << x << ", y = " << y << std::endl;
    // Output: Original values: x = 15, y = 30 (changes made by lambda2 are reflected in the original variables)


    //ANOTHER USE CASE*******************************************************

    int multiplier = 2;

    // Lambda function that captures 'multiplier' and takes an argument 'x'
    auto lambda = [multiplier](int x) {
        return multiplier * x;
    };

    int result = lambda(5);  // Calls the lambda function with argument 5
/*
Here are a few reasons why capturing can be more useful than argument passing in certain scenarios:

Access to local variables: Lambda functions can capture local variables from the enclosing scope,
even if those variables are not passed as arguments. This allows you to work with variables that
are defined outside the lambda function but are still within its scope. It can be particularly
useful when you want to use variables from the enclosing function without explicitly passing them.

Convenience and readability: Capturing variables can make your code more concise and readable,
especially when dealing with complex or nested function calls. Instead of passing multiple arguments
to a lambda function, you can simply capture the required variables and use them directly within
the lambda body.

Flexibility and delayed execution: Captured variables can be used within the lambda function even
after the enclosing scope has finished executing. This allows lambda functions to store and retain
the state of captured variables for later use, even outside the original scope. It provides
flexibility in scenarios where you need to perform delayed execution or pass functions as parameters
 to other functions.

Avoiding global variables: Capturing allows you to access variables from the enclosing scope without
resorting to global variables. This promotes encapsulation and can help maintain the integrity of
your code by limiting the scope of variables to where they are actually needed.

Overall, capturing in lambda expressions provides a powerful mechanism for working with variables
from the enclosing scope, making your code more expressive and concise while preserving the necessary
context and state.
*/







    return 0;
}

