#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
Write a function that takes in a non-empty array of integers that are sorted
in ascending order and returns a new array of the same length with the squares
of the same length with the squares of the original integers also sorted in
ascending order.
*/

vector<int> sortedSquaredArray(vector<int> array) {
    vector<int> arraySquared(array.size()); // Initialize the vector with the correct size
    for (int i = 0; i < array.size(); i++) {
        arraySquared[i] = array[i] * array[i]; // Square the elements and store in arraySquared
    }
    // Use std::sort with iterators to sort the vector
    std::sort(arraySquared.begin(), arraySquared.end());
    return arraySquared;
}

 int main() {
    vector<int> input = {1, 2, 3, 5, 6, 8, 9};
     vector<int> arraySquared;

     arraySquared = sortedSquaredArray(input);

    for (int i : arraySquared) {    // Use int i to iterate over arraySquared elements
          cout << " " << i << endl; // Print the squared elements
    }

    return 0; // Return 0 to indicate successful execution
 }
