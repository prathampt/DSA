#include <stdio.h>
#include <stdlib.h>

void printMatrix(int * matrix, int m, int n);
int * getMatrix(int m, int n);
void printSumRow(int * array, int m, int n);
void printSumColumn(int * array, int m, int n);

int main(){
    int m,n;
    printf("Enter size of matrix: ");
    scanf("%d %d", &m, &n);


    printf("Enter all the elements of the matrix.\n");
    int * matrix = getMatrix(m, n);

    printf("Matrix:\n");
    printMatrix(matrix, m, n);

    printSumRow(matrix, m, n);
    printSumColumn(matrix, m, n);

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

void printSumRow(int * array, int m, int n){
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += *(array + n * i + j);
        }
        printf("Sum of Row %d is: %d\n", i+1, sum);
        
    }
    printf("\n");
    return;
}

void printSumColumn(int * array, int m, int n){
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += *(array + n * j + i);
        }
        printf("Sum of Column %d is: %d\n", i+1, sum);
        
    }
    printf("\n");
    return;
}