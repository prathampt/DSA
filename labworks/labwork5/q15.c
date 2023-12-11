#include<stdio.h>

int main()
{
	int m,n,i;
	printf("enter the lower bound and the upper bound respectively:-\n");
	scanf("%d %d",&m,&n);
	
	i=m;
	
	printf("All the odd numbers between %d and %d are:-\n",m,n);
	while(i<=n)
	{
		if (i%2==1)
		{
			printf("%d ,",i);
		}
		i=i+1;
	}
	
	return 0;
}

	
