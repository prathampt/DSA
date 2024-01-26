#include <stdio.h>

int main(){
    int v = 0,c = 0,d = 0,b = 0;
    char str[100], chr;

    printf("Enter any string:\n");
    scanf("%[^\n]s", str);

    int i = 0;
    while ((chr = *(str+i)) != '\0')
    {
        if (chr == ' ')
        {
            b++;
        }
        else if (chr <= '9' && chr >= '0')
        {
            d++;
        }
        else if ((chr <= 'z' && chr >= 'a') || (chr <= 'Z' && chr >= 'A'))
        {
            switch (chr)
            {
            case 'a':
            case 'e':            
            case 'i':  
            case 'o':  
            case 'u': 
            case 'A':
            case 'E':            
            case 'I':  
            case 'O':  
            case 'U': 
                v++;
                break;
            default:
                c++;
            }
        }
        i++;
        
    }
    
    printf("The number of Vowels are: %d\n", v);
    printf("The number of Consonants are: %d\n", c);
    printf("The number of Digits are: %d\n", d);
    printf("The number of Blank Spaces are: %d\n", b);

    return 0;
}