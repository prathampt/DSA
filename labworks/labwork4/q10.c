/*
Question: Write a C program to input month number and print the number of days in that month.
*/

#include <stdio.h>

int main() {
    int month;

    // Input month number
    printf("Enter month number (1-12): ");
    scanf("%d", &month);

    // Check and print the number of days in the entered month
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("Number of days: 31\n");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("Number of days: 30\n");
            break;
        case 2:
            printf("Number of days: 28 or 29 (leap year)\n");
            break;
        default:
            printf("Invalid month number\n");
    }

    return 0;
}
