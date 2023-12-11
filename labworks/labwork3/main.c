/*
    Question: Write a program to Determine the ranges of char, short, int, and long variables, 
    both signed and unsigned by printing appropriate values from standard headers by direct computation. 
    Also, additionally determine the ranges of various floating-point types.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    // Char types
    printf("Char:\n");
    printf("Signed char: Range [%d, %d]\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char: Range [0, %u]\n", UCHAR_MAX);

    // Short types
    printf("\nShort:\n");
    printf("Signed short: Range [%d, %d]\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short: Range [0, %u]\n", USHRT_MAX);

    // Int types
    printf("\nInt:\n");
    printf("Signed int: Range [%d, %d]\n", INT_MIN, INT_MAX);
    printf("Unsigned int: Range [0, %u]\n", UINT_MAX);

    // Long types
    printf("\nLong:\n");
    printf("Signed long: Range [%ld, %ld]\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long: Range [0, %lu]\n", ULONG_MAX);

    // Floating-point types
    printf("\nFloat:\n");
    printf("Float: Range [%E, %E]\n", FLT_MIN, FLT_MAX);

    printf("\nDouble:\n");
    printf("Double: Range [%E, %E]\n", DBL_MIN, DBL_MAX);

    printf("\nLong Double:\n");
    printf("Long Double: Range [%LE, %LE]\n", LDBL_MIN, LDBL_MAX);

    return 0;
}
