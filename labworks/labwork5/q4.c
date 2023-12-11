#include<stdio.h>

int main()
{
	float a,b;
	int sum;
	printf("Enter the two numbers to be added:-\n");
	scanf("%f %f",&a,&b);
	sum=a+b;
	
	printf("%f+%f=%d\n",a,b,sum);
	
	return 0;
}

