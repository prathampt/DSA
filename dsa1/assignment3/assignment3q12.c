#include <stdio.h>

int main(){
    char str[100], chr;

    printf("This program changes the case:\n\a");

    printf("Enter any string:\n");
    scanf("%[^\n]s", str);

    int i = 0;
    while ((chr = *(str+i)) != '\0')
    {
        if ((chr <= 'Z' && chr >= 'A'))
        {
            *(str+i) += 32;
        }
        else if ((chr <= 'z' && chr >= 'a'))
        {
            *(str+i) -= 32;
        }
        i++;
           
    }

    printf("The string after changing the case is:\n%s\n", str);

    return 0;
    
}