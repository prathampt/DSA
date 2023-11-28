#include "logic.c"

int main(){
    char * string = "(10 + 96) * (34 - 8) ^ 4 % 5";

    int len = 0, i = 0;
    char c;
    while ((c = string[len]) != '\0'){
        len++;
    }    

    char * answer = infixToPostfix(string, len);

    while ((c = answer[i]) != '\0')
    {
        printf("%c", c);
        i++;
    }
    
    printf("\n");

    return 0;
}