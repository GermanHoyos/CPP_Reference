#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  int seqIdx = -1;
  int arrIdx = -1;
  bool valid = false;

  // sequence = [1,6,-1,10] = i
  // array = [5,1,22,25,6,-1,8,10] = j

  //In the below for loops: the 1st loop iterates through the sequence
  //and then calls an inner loop to check every index of the array in
  //comparison to the sequence. If the 2nd for loop does not find any
  //true comparisons, then the for loop ends with the "valid" operator
  //being false, if it does find a true comparison it makes valid "true"
  //and breaks out of the inner loop
  
  for (int i = 0; i < sequence.size(); i++) { // [1,6,-1,10]
    for (int j = 0; j < array.size(); j++) { // [5,1,22,25,6,-1,8,10]
      if (sequence[i] == array[j] && j != arrIdx && j > arrIdx) {
        arrIdx = j;
        valid = true; // Fixed the missing semicolon here
        break; // break out of this for loop and go to the next number in sequence
      } else {
        valid = false;
      }
    }
    if (valid == false) {
      return false;
    }
  }
  return valid;
}
