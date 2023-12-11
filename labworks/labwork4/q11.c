/*
Question: Write a C program to input angles of a triangle and check whether the triangle is valid or not.
*/

#include <stdio.h>

int main() {
    float angle1, angle2, angle3;

    // Input angles of the triangle
    printf("Enter three angles of the triangle: ");
    scanf("%f %f %f", &angle1, &angle2, &angle3);

    // Check and print whether the triangle is valid or not
    if (angle1 + angle2 + angle3 == 180 && angle1 > 0 && angle2 > 0 && angle3 > 0)
        printf("Valid Triangle\n");
    else
        printf("Invalid Triangle\n");

    return 0;
}
