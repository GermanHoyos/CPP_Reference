#include <iostream>
#include <string>

struct Vector3
{
    float x, y, z;

    Vector3() //default constructor
        : x(10), y(11), z(12) {}
};

int main()
{
    int value = 5; //allocated from stack
    int array[5];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    Vector3 myVector;
    //when the scope comes to an end, the above is free'd memory

    int* hvalue = new int; //"new" allocates on the heap // new = malloc
    *hvalue = 5; //allocated from heap
    int* harray = new int[5];
    harray[0] = 1;
    harray[1] = 2;
    harray[2] = 3;
    harray[3] = 4;
    harray[4] = 5;
    Vector3* hvector = new Vector3();

    //we have to manually delete and free our memory
    delete hvalue;
    delete[] harray;
    delete hvector;


    std::cin.get();

}
