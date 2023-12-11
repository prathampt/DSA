#include<stdio.h>

int main()
{
	int cost;
	char item[10];
	printf("Enter the item you want to order:-\n");
	fgets(item,10,stdin);
	
	printf("Enter its original price:-\n");
	scanf("%d ",&cost);
	
	int shipcharges;
	int nightcharges;
	int isnight;
	if((0<=cost)&&(cost<=100))
	{
		shipcharges=20;
	}
	else
	{
		shipcharges=30;
	}
	
	printf("Enter 1 if it is night else enter 0:-\n");
	scanf("%d",&isnight);
	
	if (isnight==1)
	{
		nightcharges=50;
	}
	else
	{
		nightcharges=0;
	}
	
	int totcost=cost+shipcharges+nightcharges;
	printf("Dear customer ,the net charge is %d", totcost);
	
	return 0;
}
	
	
	
	
