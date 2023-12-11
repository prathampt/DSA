/* Q3: Write a C function to find the factorial of numbers from 1 to 5. */

#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int i;
    for (i = 1; i <= 5; ++i) {
        printf("Factorial of %d: %d\n", i, factorial(i));
    }
    return 0;
}
