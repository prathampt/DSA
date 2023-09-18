#include <stdio.h>

int main(){
    int n;
    int sum = 0;

    printf("Enter n: ");
    scanf("%d", &n);
    while (n<=0)
    {
        printf("Enter a non-zero positive n: ");
        scanf("%d", &n);
    }
    
    // Using while loop
    printf("Using while loop:\n");
    int i = 0;
    while (i<n)
    {
        sum += (i+1); // as natural numbers start with 1, thus we should use (i+1)
        i++;
    }

    printf("The sum of natural numbers till n is: %d\n", sum);

    // Using for loop
    sum = 0; i = 0;
    printf("Using for loop:\n");

    for (int i = 0; i<n; i++){
        sum += (i+1);
    }

    printf("The sum of natural numbers till n is: %d\n", sum);
    
    return 0;
}