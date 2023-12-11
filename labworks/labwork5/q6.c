#include <stdio.h>

int main()
{
	float num;
	printf("Enter the number:-\n");
	scanf("%f", &num);
	int no = (int)num;
	int a = no % 10;
	printf("The rightmost digit of the integral part is %d\n", a);

	return 0;
}
