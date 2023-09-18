#include <stdio.h>
#include <math.h>

int main(){
    int n;

    printf("Enter a decimal integer: ");
    scanf("%d", &n);

    // Converting decimal to binary.
    long int bin = 0;
    int i = 0;
    while (n)
    {
        bin = bin + (n % 2) * pow(10, i);
        n = n / 2;
        i++;
    }

    printf("Binary form of above number is: %ld\n", bin);

    // Calculating the no. of ones in the binary number
    int one = 0;
    while (bin)
    {
        if (bin % 10 == 1){
            one++;
        }
        bin = bin / 10;
    }

    printf("The number of ones is: %d\n", one);

    return 0;
    
    
}