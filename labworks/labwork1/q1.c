/* Q1: Write a C function to find the area of a circle and call the function in main to print the area of the circle. */

#include <stdio.h>
#define PI 3.14159265359

double calculateArea(double radius)
{
    return PI * radius * radius;
}

int main()
{
    double radius;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    double area = calculateArea(radius);
    printf("Area of the circle: %lf\n", area);
    return 0;
}
