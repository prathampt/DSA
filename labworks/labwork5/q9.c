/*
Question: Take 20 integer inputs from the user and print the following:
- Number of positive numbers
- Number of negative numbers
- Number of odd numbers
- Number of even numbers
- Number of zeros
*/

#include <stdio.h>

int main() {
    int num, positiveCount = 0, negativeCount = 0, oddCount = 0, evenCount = 0, zeroCount = 0;

    printf("Enter 20 integers:\n");

    for (int i = 0; i < 20; ++i) {
        scanf("%d", &num);

        // Check conditions and update counts
        if (num > 0) {
            positiveCount++;
            if (num % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        } else if (num < 0) {
            negativeCount++;
            if (num % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        } else {
            zeroCount++;
        }
    }

    // Print the results
    printf("Number of positive numbers: %d\n", positiveCount);
    printf("Number of negative numbers: %d\n", negativeCount);
    printf("Number of odd numbers: %d\n", oddCount);
    printf("Number of even numbers: %d\n", evenCount);
    printf("Number of zeros: %d\n", zeroCount);

    return 0;
}
