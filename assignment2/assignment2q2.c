#include <stdio.h>

int main(){
    char n = 'a';

    printf("Printing ASCII values of alphabets: \n");
    while (n<='z')
    {
        printf("ASCII value of '%c' is '%3d'\t", n, n);
        printf("ASCII value of '%c' is '%d'\n", n-32, n-32);
        n++;
    }
    
    return 0;
}
