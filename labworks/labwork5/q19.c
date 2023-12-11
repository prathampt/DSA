#include<stdio.h>

int divby5(int n)
{
	int i;
	if(n%5==0)
	{
		i=1;
		printf("True.\n");
	}
	else
	{
		i=0;
		printf("false.\n");
	}
}

int divby6(int n)
{
	int i;
	if(n%6==0)
	{
		i=1;
		printf("True.\n");
	}
	else
	{
		i=0;
		printf("false.\n");
	}
}

int divby5and6(int n)
{
	int i;
	if ((divby5(n))&&(divby6(n)))
	{
		i=1;
		printf("True.\n");
	}
	else
	{
		i=0;
		printf("False.\n");
	}
}
int main()
{
	int num;
	printf("Enter the number:-\n");
	scanf("%d",&num);
	
	printf("Is %d divisible by 5?",num);
	divby5(num);
	
	printf("Is %d divisible by 6?",num);
	divby6(num); 
	
	printf("Is %d divisible by both 5 and 6?.",num);
	divby5and6(num);
	
	return 0;
}

	
	
	
	
