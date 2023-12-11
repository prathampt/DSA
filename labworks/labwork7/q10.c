#include <stdio.h>
#include <string.h>

char* cutonchar(char* str, char ch) {
    char* result = str;
    char* pos = strchr(str, ch);

    if (pos != NULL) {
        *pos = '\0';
    }

    return result;
}

int main() {
    char inputString[100];
    char separator;
    printf("Enter a string: ");
    scanf("%s", inputString);

    printf("Enter a character to cut on: ");
    scanf(" %c", &separator);

    char* result = cutonchar(inputString, separator);
    printf("Result: %s\n", result);

    return 0;
}
