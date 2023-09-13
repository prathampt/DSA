#include <stdio.h>
#include <stdlib.h>

int ** addMatrix(int matrixA[3][3], int matrixB[3][3]){

	int sum[3][3] = malloc(9*sizeof(int));
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			sum[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}
	return sum;
	
}

void printMatrix(int matrix[3][3]){
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d", matrix[i][j]);
		}
	}
	return;
}

int main(){
	int matrixA[3][3] = {1,1,1,1,1,1,1,1,1};
	int matrixB[3][3] = {1,1,1,1,1,1,1,1,1};
	
	int ** sumM = addMatrix(matrixA, matrixB, 3, 3);
	
	printMatrix(sumM);
	
	return 0;
	

}
