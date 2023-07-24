using namespace std;
#include <vector>

bool isValidSubsequence(vector<int> array, vector<int> sequence) {

  int indexFoundAt = 0;
  bool found = false;

  for (int i = 0; i < sequence.length(); i++) {
    for (int x = 0; x < array.length(); x++) {
      if (sequence[i] == array[x] && sequance[i] > indexFoundAt){
        indexFoundAt = x;
        found = true;
      } else {
        found = false;
        return found;
      }
    }
  }


  return found;
}
