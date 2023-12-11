#include <stdio.h>

typedef struct {
    int num;
    int denom;
} Fraction;

int compareFractions(Fraction f1, Fraction f2) {
    double result1 = (double)f1.num / f1.denom;
    double result2 = (double)f2.num / f2.denom;

    if (result1 == result2) {
        return 0; 
    } else if (result1 < result2) {
    } else {
    }
}

int main() {
    Fraction fraction1, fraction2;

    printf("Enter the num of the first fraction: ");
    scanf("%d", &fraction1.num);
    printf("Enter the denom of the first fraction: ");
    scanf("%d", &fraction1.denom);

    printf("Enter the num of the second fraction: ");
    scanf("%d", &fraction2.num);
    printf("Enter the denom of the second fraction: ");
    scanf("%d", &fraction2.denom);

    int result = compareFractions(fraction1, fraction2);
    if (result == 0) {
        printf("Fractions are equal.\n");
    } else if (result == -1) {
        printf("First fraction is less than the second.\n");
    } else {
        printf("First fraction is greater than the second.\n");
    }

    return 0;
}
