/*
Question: Write a program to reverse the digits of an integer and store the result as another
integer.
*/

#include <stdio.h>

int reverseDigits(int num) {
    int reversedNum = 0;

    while (num != 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return reversedNum;
}

int main() {
    int originalNum;
    printf("Enter an integer: ");
    scanf("%d", &originalNum);

    int reversedNum = reverseDigits(originalNum);
    printf("Reversed integer: %d\n", reversedNum);

    return 0;
}
