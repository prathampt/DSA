#include <stdio.h>

int main(){
    char a;
    char A;

    printf("Enter any character: ");
    scanf("%c", &a);

    if (a>='a' && a <='z')
    {
        A = a - 32;
    }
    else{
        A = a + 32;
    }

    printf("After changing the case: %c\n", A);

    return 0;
    
}