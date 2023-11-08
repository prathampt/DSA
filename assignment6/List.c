#include <stdio.h>
#include <stdlib.h>
#include "List.h"

void init(Sparse *s){
    s->header = NULL;
    s->row = 0;
    s->col = 0;
    return;
}

void append(Sparse *s, int row, int col, int val){

    if (val == 0) return;

    Node * nn = (Node *)malloc(sizeof(Node));

    if (!nn) return;

    nn->next = NULL;
    nn->row = row;
    nn->col = col;
    nn->val = val;

    if (s->header == NULL)
    {
        s->header = nn;
        return;
    }

    Node * p = s->header;

    while (p->next)
    {
        p = p->next;
    }

    p->next = nn;    
    return;
}

void display(Sparse s){
    int row = s.row, col = s.col;
    Node * p = s.header;

    printf("Displaying the sparse matrix:\n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {   
            if (p != NULL && p->row == i && p->col == j)
            {
                printf("%3d", p->val);                
                p = p->next;
            }
            else
            {
                printf("%3d", 0);
            }                       
        }
        printf("\n");
    }
    
    return;
}

Sparse * add(Sparse s1, Sparse s2){
    if (s1.row != s2.row || s1.col != s2.col) return NULL;   

    Sparse * s3 = (Sparse *)malloc(sizeof(Sparse));
    init(s3);
    s3->row = s1.row;
    s3->col = s2.col;

    Node *p = s1.header, *q = s2.header;

    while (p && q)
    {
        if (p->row == q->row)
        {
            if (p->col == q->col)
            {
                append(s3, p->row, q->col, p->val + q->val);
                p = p->next;
                q = q->next;
            }
            else if (p->col < q->col)
            {
                append(s3, p->row, p->col, p->val);
                p = p->next;
            }
            else
            {
                append(s3, q->row, q->col, q->val);
                q = q->next;
            }
        }
        else if (p->row < q->row)
        {
            append(s3, p->row, p->col, p->val);
            p = p->next; 
        }
        else
        {
            append(s3, q->row, q->col, q->val);
            q = q->next;
        }   
    }

    while (p)
    {
        append(s3, p->row, p->col, p->val);
        p = p->next;
    }

    while (q)
    {
        append(s3, q->row, q->col, q->val);
        q = q->next;
    }     
    
    return s3;
}

Sparse * subtract(Sparse s1, Sparse s2){
    if (s1.row != s2.row || s1.col != s2.col) return NULL;   

    Sparse * s3 = (Sparse *)malloc(sizeof(Sparse));
    init(s3);
    s3->row = s1.row;
    s3->col = s2.col;

    Node *p = s1.header, *q = s2.header;

    while (p && q)
    {
        if (p->row == q->row)
        {
            if (p->col == q->col)
            {
                append(s3, p->row, q->col, p->val - q->val);
                p = p->next;
                q = q->next;
            }
            else if (p->col < q->col)
            {
                append(s3, p->row, p->col, p->val);
                p = p->next;
            }
            else
            {
                append(s3, q->row, q->col, - q->val);
                q = q->next;
            }
        }
        else if (p->row < q->row)
        {
            append(s3, p->row, p->col, p->val);
            p = p->next; 
        }
        else
        {
            append(s3, q->row, q->col, - q->val);
            q = q->next;
        }
    }

    while (p)
    {
        append(s3, p->row, p->col, p->val);
        p = p->next;
    }

    while (q)
    {
        append(s3, q->row, q->col, - q->val);
        q = q->next;
    }        
    
    return s3;
}

void readFromFile(char *fileName, Sparse *s){
    FILE * fptr;
    int row, col, val;

    fptr = fopen(fileName, "r");
    if (!fptr) return;
    
    fscanf(fptr, "%d", &row);
    fscanf(fptr, "%d", &col);

    s->row = row;
    s->col = col;
    s->header = NULL;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            fscanf(fptr, "%d", &val);
            if (val)
            {
                append(s, i, j, val);
            }                      
        }
    }

    fclose(fptr);
    return;
}

void writeIntoFile(char *fileName, Sparse s){
    FILE * fptr;
    int row = s.row, col = s.col, val;

    fptr = fopen(fileName, "w");
    if (!fptr) return;

    fprintf(fptr, "%d\n%d\n", row, col);

    Node * p = s.header;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (p != NULL && p->row == i && p->col == j)
            {
                fprintf(fptr, "%d ", p->val);
                p = p->next;
            }
            else
            {
                fprintf(fptr, "0 ");
            }                       
        }
        fprintf(fptr, "\n");
    }
    
    fclose(fptr);
    return;

}