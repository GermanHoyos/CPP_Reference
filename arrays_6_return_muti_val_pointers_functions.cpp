#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int getMin(int numbers[], int size){
  int min = numbers[0]; // assign it value of 1st element
  for (int i = 1; i < size; i++){
    if(numbers[i] < min) // if less than first elem
      min = numbers[i];
  }
  return min;
}

int getMax(int numbers[], int size){
  int max = numbers[0]; // assign it value of 1st element
  for (int i = 1; i < size; i++){
    if(numbers[i] > max) //if greater than first elem
      max = numbers[i];
  }
  return max;
}

void getMinAndMax(int numbers[], int size, int*min, int*max){
  for (int i = 1; i < size; i++){
    if(numbers[i] > *max) //if greater than first elem
       *max = numbers[i]; //tricky way of returning more than 1 return
    if(numbers[i] < *min) //if greater than first elem
       *min = numbers[i]; //tricky way of returning more than 1 return
  }
}

 int main()
{

  int numbers[5] = {5,4,-2,29,6};
  //cout <<"Min is "<< getMin(numbers, 5)<<endl;
  //cout <<"Max is "<< getMax(numbers, 5)<<endl;
  int min = numbers[0];
  int max = numbers[0];

  getMinAndMax(numbers, 5, &min, &max);
    cout <<"min is " << min << endl;
    cout <<"max is " << max << endl;



  system("pause>0");
  return 0;
}
