/*
Question: Write a C program to check whether a year is a leap year or not.
*/

#include <stdio.h>

int main() {
    int year;

    // Input a year
    printf("Enter a year: ");
    scanf("%d", &year);

    // Check and print whether the year is a leap year or not
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        printf("Leap year\n");
    else
        printf("Not a leap year\n");

    return 0;
}
