#include <stdio.h>

#define LIMIT 100 //DEFINES ONLY OFFECT LINES THAT COME AFTER IT
#define MYPI 3.14159 //"MYPI" = SYMBOLIC CONSTANT

//%d = conversion character

int main(void)
{
    int inches, feet, fathoms = 7;
    //fathoms = 7;
    feet = 6 * fathoms;
    inches = 12 * feet;
    printf("Wreck of the Hesperus:\n");
    printf("Its depth at sea in different units:\n");
    printf("    %d fathoms\n", fathoms);
    printf("    %d feet\n", feet);
    printf("    %d inches\n", inches);

    printf("Get set: %s %d %f %c%c\n","one",2,3.33,'G','O');
    printf("%s%s\n", "This statement will print ", " just one very long line of text on the screen.");

    return 0;
}