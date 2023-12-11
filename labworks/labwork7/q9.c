#include <stdio.h>

void rev(char *str);

int main() {
    char inputString[100];
    printf("Enter a string: ");
    scanf("%s", inputString);
    rev(inputString);
    printf("Reversed string: %s\n", inputString);
    return 0;
}

// Define a function that reverses the string "str" in place
void rev(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}
