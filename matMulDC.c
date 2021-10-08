#include<stdio.h>
#include<stdlib.h>

int **matrix_allocate(int row, int column) {
    int **matrix =(int**)malloc(row*sizeof(int*));
    for (int i = 0; i < row; i++) {
        matrix[i] =(int*)malloc(column*sizeof(int));
    }
    return matrix;
}
int **matrix_add(int **a, int **b, int row) {
    int **c = matrix_allocate(row, row);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}
int** matrix_multiply(int **A, int **B, int row){
    int **C = matrix_allocate(row, row);
    if (row == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        int row2 = row / 2;
        int **a11 = matrix_allocate(row2, row2);
        int **a12 = matrix_allocate(row2, row2);
        int **a21 = matrix_allocate(row2, row2);
        int **a22 = matrix_allocate(row2, row2);
        int **b11 = matrix_allocate(row2, row2);
        int **b12 = matrix_allocate(row2, row2);
        int **b21 = matrix_allocate(row2, row2);
        int **b22 = matrix_allocate(row2, row2);

        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < row2; j++) {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + row2];
                a21[i][j] = A[i+row2][j];
                a22[i][j] = A[i+row2][j + row2];
                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j+row2];
                b21[i][j] = B[i+row2][j];
                b22[i][j] = B[i+row2][j+row2];
            }
        }

        int **c11 = matrix_add(matrix_multiply(a11, b11, row2),
                               matrix_multiply(a12, b21, row2), row2);
        int **c12 = matrix_add(matrix_multiply(a11, b12, row2),
                               matrix_multiply(a12, b22, row2), row2);
        int **c21 = matrix_add(matrix_multiply(a21, b11, row2),
                               matrix_multiply(a22, b21, row2), row2);
        int **c22 = matrix_add(matrix_multiply(a21, b12, row2),
                               matrix_multiply(a22, b22, row2), row2);

        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < row2; j++) {
                C[i][j] = c11[i][j];
                C[i][j + row2] = c12[i][j];
                C[i+row2][j] = c21[i][j];
                C[i+row2][j + row2] = c22[i][j];
            }
        }
    }

    return C;
}

int main() {
	int n,i,j;
    	printf("\nEnter the number of rows(&columns) for the matrices\t");
    	scanf("%d",&n);
    	int **A = matrix_allocate(n, n);
    	int **B = matrix_allocate(n, n);
	printf("\nEnter 1st matrix of %d*%d\n",n,n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("\n[%d][%d]= ",i,j);
	   		scanf("%d",&A[i][j]);
	  	}
	 }
	printf("\nEnter 2nd matrix of %d*%d\n",n,n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("\n[%d][%d]= ",i,j);
	   		scanf("%d",&B[i][j]);
	  	}
	 }
     	int **C=matrix_multiply(A,B,n);
	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
	    		printf("%4d",C[i][j]);
	   	}
   	printf("\n");
  	}

    
    
}
