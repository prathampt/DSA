#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init(Polynomial *p){
    p->maxDegree = -1;
    p->header = NULL;
    return;
}

/* // This function append the node even if the node of same degree is already present...
void append(Polynomial *p, int degree, int coefficient){
    if (coefficient == 0) return;

    Node * nn = (Node *) malloc(sizeof(Node));

    if (!nn) return;

    nn->degree = degree;
    nn->coefficient = coefficient;
    nn->next = NULL;

    if (!(p->header)){
        p->header = nn;
        return;
    }        

    Node * temp = p->header;

    while (temp->next)
    {
        temp = temp->next;
    }
    
    temp->next = nn;

    return;
}
*/

// The following function will check for the presence of node of same degree and will modify it if already present,
// else will append a new node, this function will add the node in descending order only...
void append(Polynomial *p, int degree, int coefficient){
    if (coefficient == 0) return;
    int insert = 0;

    Node * temp = p->header;

    if (temp){

        while (temp->next)
        {
            if (temp->next->degree < degree)
            {
                insert = 1;
                break;
            }
            
            else if (temp->degree == degree)
            {
                temp->coefficient += coefficient;
                return;
            }
            temp = temp->next;            
        }

        if (temp->degree == degree)
        {
            temp->coefficient += coefficient;
            return;
        }              
    }

    Node * nn = (Node *) malloc(sizeof(Node));

    if (!nn) return;

    nn->degree = degree;
    nn->coefficient = coefficient;
    nn->next = NULL;

    if (insert){
        nn->next = temp->next;
        temp->next = nn;
    }
    else if (temp) {
        temp->next = nn;
    }
    else{
        p->header = nn;
        p->maxDegree = degree;
    }

    return;    
}

void getPolynomial(Polynomial *p, int maxDegree){
    int num;

    for (int i = maxDegree; i >= 0; i--){
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &num);
        append(p, i, num);
    }

    return;
}

void randomPolynomial(Polynomial *p, int maxDegree){
    int num;

    for (int i = maxDegree; i >= 0; i--){
        append(p, i, rand() % 201 - 100);
    }

    return;
}

void display(Polynomial p){
    Node * temp = p.header;

    while (temp)
    {   
        if (temp->degree == 0) {
            printf("(%d)\n", temp->coefficient);
            return;
        }
        else if (temp->coefficient == 1)
        {
            if (temp->degree == 1)
            {
                printf("x + ");
            }
            printf("x^(%d) + ", temp->degree);
        }
        else if (temp->degree == 1)
        {
            printf("(%d)x + ", temp->coefficient);
        }
        else
        {
            printf("(%d)x^(%d) + ", temp->coefficient, temp->degree);
        }
        temp = temp->next;
    }

    printf("\b\b   \n");
    return;    
}

Polynomial * add(Polynomial *p1, Polynomial *p2){
    Polynomial * answer = (Polynomial *)malloc(sizeof(Polynomial));
    
    init(answer);

    Node *p = p1->header, *q = p2->header; 

    while (p && q)
    {
        if (p->degree == q->degree)
        {
            append(answer, p->degree, p->coefficient + q->coefficient);
            p = p->next;
            q = q->next;
        }
        else if (p->degree > q->degree)
        {
            append(answer, p->degree, p->coefficient);
            p = p->next;
        }
        else 
        {
            append(answer, q->degree, q->coefficient);
            q = q->next;
        }        
    }

    while (p)
    {
        append(answer, p->degree, p->coefficient);
        p = p->next;
    }

    while (q)
    {
        append(answer, q->degree, q->coefficient);
        q = q->next;
    }
    
    return answer;    
}

Polynomial * subtract(Polynomial *p1, Polynomial *p2){
    Polynomial * answer = (Polynomial *)malloc(sizeof(Polynomial));
    
    init(answer);

    Node *p = p1->header, *q = p2->header; 

    while (p && q)
    {
        if (p->degree == q->degree)
        {
            append(answer, p->degree, p->coefficient - q->coefficient);
            p = p->next;
            q = q->next;
        }
        else if (p->degree > q->degree)
        {
            append(answer, p->degree, p->coefficient);
            p = p->next;
        }
        else 
        {
            append(answer, q->degree, - q->coefficient);
            q = q->next;
        }        
    }

    while (p)
    {
        append(answer, p->degree, p->coefficient);
        p = p->next;
    }

    while (q)
    {
        append(answer, q->degree, - q->coefficient);
        q = q->next;
    }
    
    return answer;
}

Polynomial * multiply(Polynomial *p1, Polynomial *p2){
    Polynomial * answer = (Polynomial *)malloc(sizeof(Polynomial));
    
    init(answer);

    Node *p = p1->header, *q = p2->header;

    while (p)
    {
        q = p2->header;
        while (q)
        {
            append(answer, p->degree + q->degree, p->coefficient * q->coefficient);
            q = q->next;
        }
        p = p->next;
    }
    
    return answer;
}