#include<stdio.h>

int main()
{
	int count=0;
	int sum=0;
	
	for (int i=1; i<200; i=i+1)
	{
		if(i%2==0)
		{
			count=count+1;
			sum=sum+i;
		}
	}
	
	printf("The total number of even numbers between 1 and 200 is %d\n",count);
	printf("The sum of all even numbers between 1 and 200 is %d\n",sum);
	
	return 0;
}
 
