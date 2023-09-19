#include <stdio.h>
#include <stdlib.h>

void printMatrix(int * matrix, int m, int n);
int * getMatrix(int m, int n);
void printUpperMatrix(int * matrix, int m, int n);
void printLowerMatrix(int * matrix, int m, int n);

int main(){
    int m,n;
    printf("Enter size of square matrix: ");
    scanf("%d", &m);
    n = m;

    printf("Enter all the elements of the matrix.\n");
    int * matrix = getMatrix(m, n);

    printf("Matrix:\n");
    printMatrix(matrix, m, n);

    printf("Upper Triangular Matrix:\n");
    printUpperMatrix(matrix, m, n);

    printf("Lower Triangular Matrix:\n");
    printLowerMatrix(matrix, m, n);    

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

void printUpperMatrix(int * matrix, int m, int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            if (i > j)
            {
                printf("%3d ", 0);
                continue;
            }
            
            printf("%3d ", *(matrix + n * i + j));
        }
        printf("\n");
        
    }
    printf("\n");
    return;
}

void printLowerMatrix(int * matrix, int m, int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            if (i < j)
            {
                printf("%3d ", 0);
                continue;
            }
            
            printf("%3d ", *(matrix + n * i + j));
        }
        printf("\n");
        
    }
    printf("\n");
    return;
}
