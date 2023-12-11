#include<stdio.h>

int main()
{
	char c1[10],c2[10],c3[10];
	float r1,r2,r3;
	float cost1,cost2,cost3;
	int amount1,amount2,amount3;
	float totcost;
	
	printf("Enter the 3 commodities you want to buy:-\n");
	fgets(c1,10,stdin);
	fgets(c2,10,stdin);
	fgets(c3,10,stdin);
	
	printf("Enter the rates of following commodites in same order as they are ordered respectively:-\n");
	scanf("%f %f %f",&r1,&r2,&r3);
	
	printf("Entetr the amounts of each commodities in same order as they are ordered repectively:-\n");
	scanf("%d %d %d",&amount1,&amount2,&amount3);
	
	cost1=r1*amount1;
	cost2=r2*amount2;
	cost3=r3*amount3;
	
	totcost=cost1+cost2+cost3;
	
	printf("*****************BILL******************\n");
	printf("Item     Quantity       Price      Amount\n");
	printf("%s        %d            %f          %f\n",c1,amount1,r1,cost1);
	printf("%s        %d            %f          %f\n",c2,amount2,r2,cost2);
	printf("%s        %d            %f          %f\n",c3,amount3,r3,cost3);
	printf("Total Amount to be paid:-           %f\n",totcost);
	
	return 0;
}

	
	
	
