#include <stdio.h>
#define PI 3.1415

int main(void)
{
    double  radius;
    printf(
        "\n%s\n\n%S",
        "This program computes the aread of a circle.",
        "Input the radius: ");
    scanf("%lf", &radius);
    printf("\n%s\n%s%.2f%s%.2f%s%.2f\n%s%.5f\n\n",
        "Area = PI * radius * radius",
        "   = ", PI, " * ", radius, " * ", radius,
        "   = ", PI * radius * radius);
        return 0;
}