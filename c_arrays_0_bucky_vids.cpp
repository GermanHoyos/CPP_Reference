 #include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void printArray(int theArray[], int sizeOfArray );

int main()
{
//Array Video 1
    int studentID[3] = {2,5,9};
        cout << studentID[2] << endl;

//Array Video 2
    int arrEx[6];
        cout << "Element --- Value" << endl;
        for (int x=0; x<=7; x++){
            arrEx[x] = 100; //insert value 100 into each arrays index/element
            cout << x << " --- " << arrEx[x] << endl;
        }

//Array Video 3
    int fish[4] = {2,2,2,2};
    int sum = 0;
    for(int x = 0; x < 3; x++){
        sum += fish[x];
        cout << sum << endl;
    }

//Array Video 4
    int vid4[3] = {20,54,675};
    int vid42[7] = {45,45,78,12,90,67,34};

        printArray(vid4, 3);
        printArray(vid42, 7);
        cout << endl;

//Array Video 5 / 6
     int multi[2][3] = {{2,3,4},
                        {8,9,10}};   //[2]Rows [3]Columns
                                     // 2,3,4
                                     // 8,9,10
     cout << multi[1][1]; //9

    for (int row=0; row<2; row++){
        for(int column = 0; column<3; column++){
            cout << multi[row][column] << " ";
        } cout << endl;
    }

  return 0;
}


//Array Video 4
void printArray(int theArray[], int sizeOfArray ){
    for(int x = 0; x<sizeOfArray; x++){
        cout << theArray[x] << endl;
    }
}
