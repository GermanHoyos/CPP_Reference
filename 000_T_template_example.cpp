#include <iostream>

// Template class definition
template <class T>
class MyTemplateClass {
public:
    T data;

    // Function to set the value of the 'data' member
    void setData(T newValue) {
        // Assign the provided value to the 'data' member
        data = newValue;
    }
};

int main() {
    // Instantiate the template class with int
    MyTemplateClass<int> objInt;
    
    // Set the value for the 'data' member using setData
    objInt.setData(5);

    // Instantiate the template class with double
    MyTemplateClass<double> objDouble;
    
    // Set the value for the 'data' member using setData
    objDouble.setData(2.5);

    // Display the values
    std::cout << "Integer Value: " << objInt.data << std::endl;
    std::cout << "Double Value: " << objDouble.data << std::endl;

    return 0;
}
