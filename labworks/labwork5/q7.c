#include <stdio.h>

int main()
{
	float salary, HRA, TA;
	printf("Enter the basic salary of the employee:-\n");
	scanf("%f", &salary);

	HRA = 0.1 * salary;
	TA = 0.05 * salary;

	float totsal = salary + HRA + TA;

	printf("The gross salary is %f\n", totsal);

	return 0;
}
