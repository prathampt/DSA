#include <stdio.h>
#include <ctype.h>

int deriveInteger(const char *str) {
    int result = 0;

    while (*str != '\0') {
        if (isdigit(*str)) {
            result = result * 10 + (*str - '0');
        } else {
            return 0;
        }

        str++;
    }

    return result;
}

int main() {
    char inputString[100];

    printf("Enter a string: ");
    scanf("%s", inputString);

    int result = deriveInteger(inputString);
    
    if (result != 0) {
        printf("Derived integer: %d\n", result);
    } else {
        printf("The string does not represent a valid integer.\n");
    }

    return 0;
}
