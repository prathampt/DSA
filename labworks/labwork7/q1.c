/*
Question: Write a function to count the number of occurrences of a character in a string.
*/

#include <stdio.h>

int countOccurrences(char str[], char target) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == target) {
            count++;
        }
    }

    return count;
}

int main() {
    char str[100], target;

    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Input target character
    printf("Enter the character to count: ");
    scanf(" %c", &target);

    // Count the number of occurrences
    int occurrences = countOccurrences(str, target);

    // Display the result
    printf("Number of occurrences of '%c' in the string: %d\n", target, occurrences);

    return 1;
}
