/* Read two numbers, without prompting the user to enter the numbers.
   Multiply the numbers.
   Print only the sum, difference, product, quotient, remainder without any extra message. */

#include <stdio.h>

int main() {
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("%d\n", num1 + num2);
    printf("%d\n", num1 - num2);
    printf("%d\n", num1 * num2);
    printf("%d\n", num1 / num2);
    printf("%d\n", num1 % num2);
    return 0;
}
