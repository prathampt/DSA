#include <stdio.h>
#include <math.h>

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("List of prime numbers till n is: %d ", 2);
    for (int i = 3; i < n+1; i++)
    {
        int bool = 0;
        for (int j = 2; j < (int) sqrt(i) + 1; j++)
        {
            if (i % j == 0)
            {
                bool = 1;
                break;                
            }
        }

        if (bool == 0)
        {
            printf("%d ", i);
        }
        
        
    }

    printf("\n");
    return 0;
    
}