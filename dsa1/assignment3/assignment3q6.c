#include <stdio.h>
#include <stdlib.h>

void printMatrix(int * matrix, int m, int n);
int * getMatrix(int m, int n);
int * getDiagonal(int * matrix, int m, int n);
int sum(int * array, int n);

int main(){
    int m,n;
    printf("Enter size of matrix: ");
    scanf("%d %d", &m, &n);


    printf("Enter all the elements of the matrix.\n");
    int * matrix = getMatrix(m, n);

    printf("Matrix:\n");
    printMatrix(matrix, m, n);

    int * diag = getDiagonal(matrix, m, n);

    printf("Diagonal Matrix:\n");
    printMatrix(diag, 1, m);

    printf("Sum of diagonal elements is: %d\n", sum(diag, m));

    return 0;
}

int * getMatrix(int m, int n){
    int * array = malloc(m*n*sizeof(int));

    printf("Enter matrix: ");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            scanf("%d", (array + n * i + j));
        }
        
    }
    
    return array;

}

void printMatrix(int * matrix, int m, int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d ", *(matrix + n * i + j));
        }
        printf("\n");
        
    }
    printf("\n");
    return;
}

int * getDiagonal(int * matrix, int m, int n){
    int * array = malloc(m*sizeof(int));

    for (int i = 0; i < m; i++)
    {
        *(array+i) = *(matrix + n * i + i);
    }

    return array;
}

int sum(int * array, int n){
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += *(array+i);
    }
    return s;
}