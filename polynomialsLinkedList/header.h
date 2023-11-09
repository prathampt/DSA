typedef struct node{
    int degree, coefficient;
    struct node * next;
}Node;

typedef struct polynomial{
    int maxDegree;
    Node * header;
}Polynomial;

void init(Polynomial *p);
void append(Polynomial *p, int degree, int coefficient);
void getPolynomial(Polynomial *p, int maxDegree);
void randomPolynomial(Polynomial *p, int maxDegree);
void display(Polynomial p);
Polynomial * add(Polynomial *p1, Polynomial *p2);
Polynomial * subtract(Polynomial *p1, Polynomial *p2);
Polynomial * multiply(Polynomial *p1, Polynomial *p2);
