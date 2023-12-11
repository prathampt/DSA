#include<stdio.h>

int main()
{
	int n;
	printf("Enter the upper bound of the numbers:-\n");
	scanf("%d",&n);
	
	int sum=0;
	for (int i=1; i<=n; i=i+1)
	{
		sum= sum+i;
	}
	
	float ave=sum/n;
	printf("The sum of all the numbers from 1 to %d is %d\n",n,sum);
	printf("The average is %f\n",ave);
	return 0;
}
 
	
