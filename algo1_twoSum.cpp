/*
Write a function that takes in a non-empty array of distinct
intergers and an integer representing a target sum. If any two
numbers in the input array sum up to the target sum, the function
should return them in an array, in any order. If no two numbers
sum up to the target sum, the function should return an empty array

the sum must be attained with two seperate indexes

*/

#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  //Write your code here.
  //for (length of the array, i++)
    //for (length of the array x++)
      //if indexOf i != indexOf x
        //if i + x = sum
          //tempi = i / tempx = x
  vector<int> returnArray;

  for (int i = 0; i < array.size(); i++){
    for (int x = 0; x < array.size(); x++){
      if (i != x){
        int sumOfCheck = array[i] + array[x];
        if(sumOfCheck == targetSum){
          returnArray.push_back(array[i]);
          returnArray.push_back(array[x]);
          return returnArray;
        }
      }
    }
  }

  return returnArray;
}
