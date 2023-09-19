#include <stdio.h>
#include <stdlib.h>

int length(char * string);
void copy(char * str1, char * str2);
int compare(char * str1, char * str2);
void concat(char * str1, char * str2);
void reverse(char * string);
char * getSubstring(char * string, int i, int j);
int isSubstring(char * str1, char * str2);

int main(){
    char str1[100], str2[100];
    int choice;

    printf("Menu:\n");
    printf("1. Calculate Length\n");
    printf("2. Copy String\n");
    printf("3. Compare Strings\n");
    printf("4. Concatenate Strings\n");
    printf("5. Reverse String\n");
    printf("6. Extract Substring\n");
    printf("7. Check is Substring\n");
    printf("8. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                scanf("%s", str1);
                printf("Length of the string: %d\n", length(str1));
                break;

            case 2:
                printf("Enter the source string: ");
                scanf("%s", str1);
                copy(str1, str2);
                printf("Copied string: %s\n", str2);
                break;

            case 3:
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                if (compare(str1, str2) == 1)
                    printf("Strings are equal.\n");
                else
                    printf("Strings are not equal.\n");
                break;

            case 4:
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                concat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 5:
                printf("Enter a string: ");
                scanf("%s", str1);
                reverse(str1);
                printf("Reversed string: %s\n", str1);
                break;

            case 6:
                printf("Enter a string: ");
                scanf("%s", str1);
                int start, end;
                printf("Enter the starting index: ");
                scanf("%d", &start);
                printf("Enter the end index of substring: ");
                scanf("%d", &end);
                char * result = getSubstring(str1, start, end);
                printf("Substring: %s\n", result);
                break;

            case 7:
                printf("Enter a string: ");
                scanf("%s", str1);
                printf("Enter other string: ");
                scanf("%s", str2);
                int b = isSubstring(str1, str2);
                if (b)
                    printf("Second string is substring of first string.\n");
                else
                    printf("Second string is not substring of first string.\n");
                break;

            case 8:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

}

int length(char * string){
    int i = 0;

    while (*(string+i)!='\0')
    {
        i++;
    }

    return i;

}

void copy(char * str1, char * str2){
    int len = length(str1);

    for (int i = 0; i < len; i++)
    {   
        *(str2 + i) = *(str1 + i);
    }

    return;
    
}

int compare(char * str1, char * str2){
    int c = 1, len = length(str1);

    for (int i = 0; i < len; i++)
    {
        if (*(str1 + i) != *(str2 + i))
        {
            c = 0;
            break;
        }
        
    }

    return c;
    
}

void concat(char * str1, char * str2){
    int len1 = length(str1), len2 = length(str2);

    for (int i = 0; i < len2; i++)
    {
        *(str1+len1+i) = *(str2+i);
    }
    
    return;
}

void reverse(char * string){
    int len = length(string);

    for (int i = 0; i < len/2; i++)
    {
        char temp = *(string + i);
        *(string + i) = *(string + len - 1 - i);
        *(string + len - 1- i) = temp;
    }
    
    return;
}

int isSubstring(char * str1, char * str2){
    int len1 = length(str1), len2 = length(str2);
    int b = 0;

    int i = 0, j = 0;
    while (i<len1 && j<len2)
    {
        if (*(str2 + j) != *(str1 + i))
        {
            i++;
            j = 0;
        }
        else if (*(str2 + j) == *(str1 + i))
        {
            i++;
            j++;
        }
        
        if (j == len2)
        {
            b = 1;
        }
        else{
            b = 0;
        }
        
        
    }
    
    return b;
}

char * getSubstring(char * string, int i, int j){
    char * sub = malloc((j - i)*sizeof(char));

    for (int k = i; k < j; k++)
    {
        *(sub + (k - i)) = *(string + k);
    }

    return sub;
    
}
