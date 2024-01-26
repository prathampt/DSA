#include <stdio.h>

int main(){
	int bSalary, percent;
	double DA;
	
	printf("Enter your basic salary: ");
	scanf("%d", &bSalary);
	
	if (bSalary >= 10000 && bSalary <= 20000){
		percent = 10;	
	}
	else if (bSalary > 20000 && bSalary <= 50000){
		percent = 15;	
	}
	else if (bSalary > 50000 && bSalary <= 100000){
		percent = 20;	
	}
	else{
		percent = 0;
	}
	
	if (percent == 0){
		printf("DA is not given!\n");
	}
	else {
		DA = (double) percent * bSalary / 100; 
		printf("DA is Rupees: %.2f\n", DA);
	}
	
	return 0;
}
