#include <stdio.h>

#define LIMIT 100 //DEFINES ONLY OFFECT LINES THAT COME AFTER IT
#define MYPI 3.14159 //"MYPI" = SYMBOLIC CONSTANT

//%d = conversion character

int main(void)
{
    char first, middle, last;
    int age;

    printf("Input your three initials and your age: ");
    scanf("%c%c%c%d", &first, &middle, &last, &age);
    printf("\nGreetings %c.%c.%c.  %s %d.\n", //for addresses "%p"
        first, middle, last, //to display addresses "&"
        "Next year your age will be", age + 1);
    return 0;
}

// notice carefully
// "%c%c%c%d   &first & middle &last &age"