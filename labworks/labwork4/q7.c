/*
Question: Write a C program to input any alphabet and check whether it is a vowel or consonant.
*/

#include <stdio.h>

int main() {
    char ch;

    // Input a character
    printf("Enter a character: ");
    scanf(" %c", &ch);

    // Check and print whether the character is a vowel or consonant
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            printf("Vowel\n");
        else
            printf("Consonant\n");
    } else {
        printf("Not an alphabet\n");
    }

    return 0;
}
