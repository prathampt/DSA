/*
Question: Write a C program to check whether a number is negative, positive, or zero.
*/

#include <stdio.h>

int main() {
    int num;

    // Input a number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check and print whether the number is negative, positive, or zero
    if (num > 0)
        printf("Positive\n");
    else if (num < 0)
        printf("Negative\n");
    else
        printf("Zero\n");

    return 0;
}
