/*
Question: Write a C program to check whether a character is an uppercase or lowercase alphabet.
*/

#include <stdio.h>

int main() {
    char ch;

    // Input a character
    printf("Enter a character: ");
    scanf(" %c", &ch);

    // Check and print whether the character is uppercase or lowercase
    if (ch >= 'A' && ch <= 'Z')
        printf("Uppercase Alphabet\n");
    else if (ch >= 'a' && ch <= 'z')
        printf("Lowercase Alphabet\n");
    else
        printf("Not an alphabet\n");

    return 0;
}
