#include<stdio.h>

int main()
{
	int i=1;
	while(i==1)
	{
		char c;
		printf("Enter a character.Enter * to exit:-\n");
		scanf("%c",&c);
		int a=(int)c;
		printf("The ASCII value of the character is %d\n",a);
		if ((65<=a)&&(a<=90))
		{
			int b=a+32;
			printf("Corrosponding alphabet in lowercase is %c\n",(char)b);
		}
		else if ((97<=a)&&(a<=122))
		{
			int b=a-32;
			printf("Corrosponding alphabet in uppercase is %c\n",(char)b);
		}
		
		else if (c=='*')
		{
			printf("exiting the program.\n");
			i=-1;
		}
		else
		{
			i=1;
		}
	}
	return 0;
}

		
