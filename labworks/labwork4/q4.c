/*
Question: Write a C program to check whether a number is even or odd.
*/

#include <stdio.h>

int main() {
    int num;

    // Input a number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check and print whether the number is even or odd
    if (num % 2 == 0)
        printf("Even\n");
    else
        printf("Odd\n");

    return 0;
}
