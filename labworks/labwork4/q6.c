/*
Question: Write a C program to check whether a character is an alphabet or not.
*/

#include <stdio.h>

int main() {
    char ch;

    // Input a character
    printf("Enter a character: ");
    scanf(" %c", &ch);

    // Check and print whether the character is an alphabet or not
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        printf("Alphabet\n");
    else
        printf("Not an alphabet\n");

    return 0;
}
