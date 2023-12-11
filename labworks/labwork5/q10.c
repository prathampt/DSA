#include<stdio.h>
#include<math.h>

int main()
{
	float num;
	printf("Enter the floating point number:-\n");
	scanf("%f",&num);
	int no=(int)num;
	
	int count=0;
	while (num>10)
	{
		num=num/10;
		count=count+1;
	
	}
	
	float num2=no/pow(10,count);
	printf("The exponential expansion is %fe+%d\n",num2,count);
	
	return 0;
}

