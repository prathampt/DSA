#include<stdio.h>

int main()
{
	int m,n;
	printf("Enter the lower and upper bound repsectively:-\n");
	scanf("%d %d",&m,&n);
	
	int i=m;
	printf("All the prime numbers between %d and %d are:-\n",m,n);
	while(i<=n)
	{
		int count=0;
		for (int j=1; j<=i;j=j+1)
		{
			if(i%j==0)
			{
				count=count+1;
			}
		}
		if (count==2)
		{
			printf("%d ,",i);
		}
		
		i=i+1;
	}
	
	return 0;
}

