#include<stdio.h>

int main()
{
	float n1,n2,n3,sum;
	printf("Enter the 3 floating numbers:-\n");
	scanf("%f %f %f",&n1,&n2,&n3);
	
	sum=n1+n2+n3;
	
	printf("The sum of the three numbers is %.2f\n",sum);
	
	return 0;
}

