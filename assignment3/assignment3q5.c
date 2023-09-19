#include <stdio.h>
#include <stdlib.h>

int * getMatrix(int m, int n);
int * addMatrix(int * matrixA, int * matrixB, int m, int n);
int * subtractMatrix(int * matrixA, int * matrixB, int m, int n);
int * multiply(int * matrixA, int * matrixB, int m, int n);
void printMatrix(int * matrix, int m, int n);

int main(){
    int m,n;
    printf("Enter size of matrix: ");
    scanf("%d %d", &m, &n);


    printf("Enter all the elements of the matrix1.\n");
    int * matrix1 = getMatrix(m, n);

    printf("Enter all the elements of the matrix2.\n");
    int * matrix2 = getMatrix(m, n);

    printf("Matrix1:\n");
    printMatrix(matrix1, m, n);
    printf("Matrix2:\n");
    printMatrix(matrix2, m, n);

    char * chr = malloc(3 * sizeof(char));
    printf("Menu:\n1.Add 'a'\n2.Subtract 's'\n3.Multiply 'm'\n4.All 'l'\n");
    printf("Enter your choice: ");
    scanf("%s", chr);

    switch (chr[0])
    {
        case 'a':
            int * sum = addMatrix(matrix1, matrix2, m, n);
            printf("Matrix1 + Matrix2 =\n");
            printMatrix(sum, m, n);
            break;

        case 's':
            int * diff = subtractMatrix(matrix1, matrix2, m, n);
            printf("Matrix1 - Matrix2 =\n");
            printMatrix(diff, m, n);
            break;

        case 'm':
            int * pro1 = multiply(matrix1, matrix2, m, n);
            printf("Matrix1 X Matrix2^T =\n");
            printMatrix(pro1, m, m);
            int * pro2 = multiply(matrix2, matrix1, m, n);
            printf("Matrix2 X Matrix1^T =\n");
            printMatrix(pro2, m, m);
            break;
        
        default:
            int * sumX = addMatrix(matrix1, matrix2, m, n);
            printf("Matrix1 + Matrix2 =\n");
            printMatrix(sumX, m, n);

            int * diffX = subtractMatrix(matrix1, matrix2, m, n);
            printf("Matrix1 - Matrix2 =\n");
            printMatrix(diffX, m, n);

            int * pro1X = multiply(matrix1, matrix2, m, n);
            printf("Matrix1 X Matrix2^T =\n");
            printMatrix(pro1X, m, m);
            int * pro2X = multiply(matrix2, matrix1, m, n);
            printf("Matrix2 X Matrix1^T =\n");
            printMatrix(pro2X, m, m);            
    }
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

int * addMatrix(int * matrixA, int * matrixB, int m, int n){
    int * array = malloc(m*n*sizeof(int));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            *(array + n * i + j) = *(matrixA + n * i + j) + *(matrixB + n * i + j);
        }
        
    }
    
    return array;
}

int * subtractMatrix(int * matrixA, int * matrixB, int m, int n){
    int * array = malloc(m*n*sizeof(int));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            *(array + n * i + j) = *(matrixA + n * i + j) - *(matrixB + n * i + j);
        }
        
    }
    
    return array;
}

int * multiply(int * matrixA, int * matrixB, int m, int n){
    int * array = malloc(m*m*sizeof(int));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum += *(matrixA + n * i + k) * *(matrixB + n * j + k);
            }
            *(array + m * i + j) = sum;
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