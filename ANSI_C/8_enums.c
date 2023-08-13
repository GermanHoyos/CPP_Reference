#include <stdio.h>

int main(void)
{
    //simple example
    enum day {sun, mon, tue, wed, thu, fri, sat};
    enum day d1, d2;
    d1 = fri;
    printf("%d", d1);

    //multiple declare
    enum suit {clubs = 1, diamonds, hearts, spades} a, b, c; // diamonds = 2, hearts = 3, etc etc... 
    //enum suit a,b,c; //already declared above

    //change order of int indexing
    enum fruit {apple = 7, pear, orange = 3, lemon} frt; // pear = 8, lemon = 4

    //tag name not needed
    enum { January = 1, February, March, April, May, June, July, August, September, October, November, December } birthMonth;
    //Jan is 1 not 0
    birthMonth = August;
    printf("%d", birthMonth);

    return 0;
}

