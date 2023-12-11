/*
Question: Generate ten random numbers in the range [1, 100] using the rand() function.
Initialize an array of integers with values ranging from 50 to 100 (both inclusive) and display the contents.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int array[10];
    
    // Seed the random number generator
    srand(time(NULL));

    printf("Initializing array with values ranging from 50 to 100 (inclusive):\n");

    // Initialize array with random values in the range [50, 100]
    for (int i = 0; i < 10; ++i) {
        array[i] = rand() % 51 + 50;  // Generates a random number in the range [50, 100]
        printf("%d\n", array[i]);
    }

    return 0;
}
