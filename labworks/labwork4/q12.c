/*
Question: Write a C program to check whether the triangle is equilateral, isosceles, or scalene.
*/

#include <stdio.h>

int main() {
    float side1, side2, side3;

    // Input sides of the triangle
    printf("Enter three sides of the triangle: ");
    scanf("%f %f %f", &side1, &side2, &side3);

    // Check and print whether the triangle is equilateral, isosceles, or scalene
    if (side1 == side2 && side2 == side3)
        printf("Equilateral Triangle\n");
    else if (side1 == side2 || side2 == side3 || side1 == side3)
        printf("Isosceles Triangle\n");
    else
        printf("Scalene Triangle\n");

    return 0;
}
