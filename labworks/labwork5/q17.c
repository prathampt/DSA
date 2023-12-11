#include<stdio.h>
#include<math.h>

int main()
{
	int i=1;
	while(i==1)
	{
		int num;
		printf("Enter a number,enter -1 to exit:-\n");
		scanf("%d",&num);
		int temp=num;
		int num2=0;
		if(num!=-1)
		{
			while(temp!=0)
			{
				int a=temp%10;
				num2=num2+pow(a,3);
				temp=temp/10;
			}
		
			if(num2==num)
			{
				printf("It is a armstrong number.\n");
			}
			else
			{
				printf("It is not a armstrong number.\n");
			}
		}
		if(num==-1)
		{	
			printf("Exiting the program.");
			i=-1;
		}
	}
	return 0;
}

			
