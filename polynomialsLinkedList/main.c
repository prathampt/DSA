#include "logic.c"

int main(){
    Polynomial p1, p2;

    init(&p1);
    init(&p2);

    getPolynomial(&p1, 4);
    randomPolynomial(&p2, 3);

    printf("Polynomial 1: ");
    display(p1);
    printf("Polynomial 2: ");
    display(p2);

    Polynomial * sum = add(&p1, &p2);
    printf("Polynomial Sum: ");
    display(*sum);

    Polynomial * diff = subtract(&p1, &p2);
    printf("Polynomial Difference: ");
    display(*diff);

    Polynomial * product = multiply(&p1, &p2);
    printf("Polynomial Product: ");
    display(*product);

    return 0;
}