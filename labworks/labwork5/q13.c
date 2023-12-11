#include<stdio.h>

int main()
{
	char c;
	printf("Enter a character:-\n");
	scanf("%c",&c);
	int a=(int)c;
	
	printf("The ASCII value of the character is %d\n",a);
	if (((65<=a)&&(a<=90))||((97<=a)&&(a<=122)))
	{
		if ((65<=a)&&(a<=97))
		{	
			printf("The entered character is uppercase alphabet./n");
			
		}
		else if ((97<=a)&&(a<=122))
		{
			printf("The entered character is lowercase alphabet./n");
		}
	}
	else if ((48<=a)&&(a<=57))
	{
		printf("The entered character is a digit.\n");
	}
	else
	{
		printf("the entered charactir is a special charcter.\n");	
	}
	
	return 0;
}
	
