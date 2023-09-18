#include <stdio.h>

int main() {
	float f,c;
	char ch;
	printf("Enter f if you want to convert from fahrenheit to celsius or enter c for reverse...\n");
	scanf("%c", &ch);
	
	switch (ch) {
		case 'f':
			printf("Enter temperature in fahrenheit: ");
			scanf("%f",&f);
			
			c = (f - 32) * 5 / 9;
			
			printf("The same temperature in celsius is %.2f\n", c);
			break;
		case 'c':
			printf("Enter temperature in celsius: ");
			scanf("%f",&c);
			
			f = (9 * c / 5) + 32;
			
			printf("The same temperature in fahrenheit is %.2f\n", f);
			break;
		default:
			printf("You entered worng value!\n");
	}
	return 0;
}
