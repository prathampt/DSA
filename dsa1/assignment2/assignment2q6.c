#include <stdio.h>


int factorial(int n);
int combination(int n, int r);
int main(){
    int n;


    printf("Star Pattern:\n");
    printf("Enter n (preferred 5): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-1-i; j++)
        {
            printf("%s ", " ");
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            printf("%s ", "*");
        }
        printf("\n");
        
    }
    printf("\n");


    printf("Floyd's Triangle:\n");
    printf("Enter n (preferred 4): ");
    scanf("%d", &n);

    int count = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            printf("%d ", count);
            count++;
        }
        printf("\n");
        
    }
    printf("\n");


    printf("Binary Pattern:\n");
    printf("Enter n (preferred 5): ");
    scanf("%d", &n);

    int b = 0;
    for (int i = 0; i < n; i++)
    {
        b = 0;
        for (int j = 0; j < i+1; j++)
        {
            printf("%d ", b);
            if (b == 0)
            {
                b = 1;
            }
            else{
                b = 0;
            }
            
            
        }
        for (int k = 0; k < 3 * (n - i - 1); k++)
        {
            printf(" ");
        }
        b = 0;
        for (int j = 0; j < i+1; j++)
        {
            printf("%d ", b);
            if (b == 0)
            {
                b = 1;
            }
            else{
                b = 0;
            }
        }
            
        
        printf("\n");
        
    }
    printf("\n");


    printf("Pascal's Triangle:\n");
    printf("Enter n (preferred 6): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            printf(" ");
        }
        
        for (int j = 0; j < i+1; j++)
        {
            printf("%2d", combination(i, j));
            printf(" ");
        }

        printf("\n");
        
    }
    

    


    return 0;
}

int factorial(int n){
    if (n==0 || n==1)
    {
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
    
}

int combination(int n, int r){
    return factorial(n)/(factorial(r)*factorial(n-r)) ;
}