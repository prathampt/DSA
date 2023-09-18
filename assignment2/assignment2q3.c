#include <stdio.h>

int main(){
    long int n;
    int sum = 0;
    printf("Enter any integer: ");
    scanf("%ld", &n);

    int i = 0;
    while (n)
    {
        if (i%2 != 0){
            n = n / 10;
            i++;
            continue;
        }

        sum += n % 10;
        printf("%ld + ", n%10);
        n = n / 10;
        i++;
    }
    
    printf("\b\b= %d\n", sum);

    return 0;
}