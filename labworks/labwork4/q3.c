/*
Question: Write a C program to check whether a number is divisible by 5 and 11 or not.
*/

#include <stdio.h>

int main() {
    int num;

    // Input a number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check and print whether the number is divisible by 5 and 11
    if (num % 5 == 0 && num % 11 == 0)
        printf("Divisible by 5 and 11\n");
    else if (num % 5 == 0)
        printf("Only divisible by 5\n");
    else if (num % 11 == 0)
        printf("Only divisible by 11\n");
    else
        printf("Not divisible by 5 and 11\n");

    return 0;
}
