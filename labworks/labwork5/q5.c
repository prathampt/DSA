#include<stdio.h>
#include<math.h>

int main()
{
	int time;
	float principle,rate;
	printf("Enter the time in years:-\n");
	scanf("%d",&time);
	printf("Enter the principle amount:-\n");
	scanf("%f",&principle);
	printf("enter the rate :-\n");
	scanf("%f",&rate);
	
	float SI,CI;
	SI=principle*rate*time;
	CI=principle*(pow(1+rate,time)-1);
	printf("Simple interest:-%f\n",SI);
	printf("Compound interest:-%f\n",CI);
	
	return 0;
}

