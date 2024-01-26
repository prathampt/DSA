#include <stdio.h>

int main(){
	int a,b,c,large,largest;
	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);
	printf("Enter c: ");
	scanf("%d", &c);
	
	//logic
	large = ( a >= b ) ? a : b;
	largest = ( large >= c ) ? large : c;
	printf("The largest of all the numbers is %d!\n", largest);
	return 0;
}
