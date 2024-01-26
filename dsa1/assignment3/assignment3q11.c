#include <stdio.h>
#include <stdlib.h>

int main(){
    char str[100], chr;
    char * alphabets = malloc(27*sizeof(char));

    printf("Enter any string:\n");
    scanf("%[^\n]s", str);

    int i = 0;
    while ((chr = *(str+i)) != '\0')
    {
        if ((chr <= 'Z' && chr >= 'A'))
        {
            chr += 32;
        }
        
        *(alphabets + (int) (chr - 'a')) += 1; 
        i++;     
    }

    for (int i = 0; i < 26; i++)
    {
        if (*(alphabets + i) == 0)
        {
            continue;
        }
        
        printf("The frequency of %c is %d\n", (i + 'a'), *(alphabets + i));
    }

    return 0;
    
}