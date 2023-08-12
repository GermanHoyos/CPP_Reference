#include <stdio.h>

int main(void)
{
    int cnt = 0;
    float sum = 0.0, x;

    printf("The sum of your numbers will be computed \n\n");
    printf ("Input some numbers: ");
    while (scanf("%f", &x) == 1) { //take the user input and place it into the address location of 'x'
        cnt = cnt + 1;
        sum = sum + x;
    }
    printf("\n%s%5d\n%s%12f\n\n", "Count:", cnt, "  Sum:", sum);
        //  \n: Inserts a newline character, which moves the cursor to the next line.
        //  %s: Placeholder for a string argument.
        //  %5d: Placeholder for an integer argument, with a field width of 5 characters.
        //  %s: Placeholder for a string argument.
        //  %12f: Placeholder for a floating-point (decimal) argument, with a field width of 12 characters.
    return 0;
}

