#include <stdio.h>
#include <string.h>

char *my_strtok(char *str, const char *delimiters) {
    static char *lastToken = NULL; 

    if (str == NULL && lastToken != NULL) {
        str = lastToken;
    } else if (str == NULL) {
        return NULL; 
    }

    while (*str != '\0' && strchr(delimiters, *str) != NULL) {
        ++str;
    }

    if (*str == '\0') {
        lastToken = NULL;
        return NULL;
    }

    char *token = str;
    while (*str != '\0' && strchr(delimiters, *str) == NULL) {
        ++str;
    }

    if (*str == '\0') {
        lastToken = NULL;
    } else {
        *str = '\0';
        lastToken = str + 1;
    }

    return token;
}

int main() {
    char str[] = "This,is,a,sample,string,which,I,am,as,a,coder,giving,to,my,code,to,test,does,it,work,or,not,!";
    const char delimiters[] = ",";

    // Tokenize the string using my_strtok
    char *token = my_strtok(str, delimiters);
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = my_strtok(NULL, delimiters);
    }

    return 0;
}
