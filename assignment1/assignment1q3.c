#include <stdio.h>

int main(){
	char ch;

	printf("Enter any alphabet: ");
	scanf("%c", &ch);

	//Using if-else statements...
	/*
	if (ch == 'a' || ch == 'A') {
		printf("Vowel\n");
	}
	else if (ch == 'e' || ch == 'E') {
		printf("Vowel\n");
	}
	else if (ch == 'i' || ch == 'I') {
		printf("Vowel\n");
	}
	else if (ch == 'o' || ch == 'O') {
		printf("Vowel\n");
	}
	else if (ch == 'u' || ch == 'U') {
		printf("Vowel\n");
	}
	else {
		printf("Consonant\n");
	}
	*/
	
	// Using switch statement...
	
	/*
	switch(ch)
	{
		case 'a': 
		    printf("Vowel\n");
		    break;
		case 'e': 
		    printf("Vowel\n");
		    break;
		case 'i': 
		    printf("Vowel\n");
		    break;
		case 'o': 
		    printf("Vowel\n");
		    break;
		case 'u': 
		    printf("Vowel\n");
		    break;
		case 'A': 
		    printf("Vowel\n");
		    break;
		case 'E': 
		    printf("Vowel\n");
		    break;
		case 'I': 
		    printf("Vowel\n");
		    break;
		case 'O': 
		    printf("Vowel\n");
		    break;
		case 'U': 
		    printf("Vowel\n");
		    break;
		default: 
		    printf("Consonant\n");
	}
	*/
	// We can also write code like this...

	switch(ch)
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
		    printf("Vowel\n");
		    break;

		default: printf("Consonant\n");
	}

	return 0;
}
