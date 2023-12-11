/*
Question: Write a function to convert a decimal number to a binary number and return the binary
representation in a string.
*/

#include <stdio.h>
#include <stdlib.h>

char* decimalToBinary(int decimal) {
    int bits = 0;
    int temp = decimal;

    while (temp > 0) {
        bits++;
        temp /= 2;
    }

    char* binary = (char*)malloc((bits + 1) * sizeof(char));

    for (int i = bits - 1; i >= 0; i--) {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
    }

    binary[bits] = '\0';

    return binary;
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    char* binary = decimalToBinary(decimal);
    printf("Binary representation: %s\n", binary);

    free(binary);

    return 0;
}
