#include <stdio.h>
#include <stdlib.h>

int main(){

	printf("This program prints the size of various data-types:\n");
	printf("Size of char is: %ld\n",sizeof(char));
	printf("Size of int is: %ld\n",sizeof(int));
	printf("Size of float is: %ld\n",sizeof(float));
	printf("Size of double is: %ld\n",sizeof(double));
	printf("Size of long int is: %ld\n",sizeof(long int));
	printf("Size of long long int is: %ld\n",sizeof(long long int));
	printf("Size of long double is: %ld\n",sizeof(long double));

	return 0;	
}
