#include <stdio.h>

int main() {
	float r;
	float cir, area;
	const float pi = 3.142;
	
	printf("Enter radius of circle: ");
	scanf("%f", &r);
	
	cir = 2 * pi * r;
	area = pi * r * r;
	
	printf("Circumference of circle is: %f units\n", cir);
	printf("Area of circle is: %f square units\n", area);
	
	return 0;
	
}
