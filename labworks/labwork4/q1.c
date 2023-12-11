/*
Question: Write a C program to find maximum between two numbers.
*/

#include <stdio.h>

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Determine and print the maximum
    int max = (num1 > num2) ? num1 : num2;
    printf("Maximum: %d\n", max);

    return 0;
}
