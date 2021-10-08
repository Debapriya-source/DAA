#include<math.h>
#include <stdlib.h>
#include <stdio.h>
int **matAllocate(int,int);
void matInput(int**,int,int);
void matDisplay(int**,int,int);
int **matMul(int**,int**,int,int);

int **matAllocate(int rows,int columns)
{
		int** matrix = (int**)calloc(rows,sizeof(int*));
		int i;
		for(i=0;i<rows;i++)
		matrix[i]=(int*)calloc(columns,sizeof(int));
		return matrix;
}
void matInput(int** matrix,int rows,int columns)
{
		int i,j;
		for(i=0;i<rows;i++)
		{
			for(j=0;j<columns;j++)
				scanf("%d",&matrix[i][j]);
		}
}
void matDisplay(int** matrix,int rows,int columns)
{
	printf("\n");
		int i,j;
		for(i=0;i<rows;i++)
		{
			for(j=0;j<columns;j++)
			printf("%d ",matrix[i][j]);
			printf("\n");
		}
}
int **matAdd(int** mat1,int** mat2,int rows,int columns)
{
		int i,j;
		int** ans=matAllocate(rows,columns);
		for(i=0;i<rows;i++)
		{
			for(j=0;j<columns;j++)
			ans[i][j]=mat1[i][j]+mat2[i][j];
		}
		return ans;
}
int** squareMatMul(int** mat1,int** mat2)
{
	int sum=0,**res=matAllocate(2,2);
	for(int i=0;i<2;i++)
		for (int j= 0;j<2;j++)
		{
			for(int k=0;k<2;k++)
				res[i][j] += mat1[i][k] * mat2[k][j];
		}
	return res;	
}

int main()
{
		int r1,r2,c1,c2;
		int **A,**B,**C,max;
		printf("Enter the number of rows and columns of first matrix: ");
		scanf("%d%d",&r1,&c1);
		printf("Enter the number of rows and columns of second matrix: ");
		scanf("%d%d",&r2,&c2);
		if(c1==r2)
		{
			max=(r1>=c2)?r1:c2;
			max=(max>=c1)?max:c1;
			if ( (log(max)/log(2)) != (int)(log(max)/log(2)) )  //making sure that the matrix is of 2^n order so that it can be divided properly...
			    max=(int)(pow(2, (int)(log(max)/log(2))+1));           
            //printf("%d\n",max); 
			A=matAllocate(max,max);
			B=matAllocate(max,max);
			C=matAllocate(max,max);
		}
		printf("Enter the elements of matrix A:\n");
		matInput(A,r1,c1);
		matDisplay(A,r1,c1);
		printf("Enter the elements of matrix B:\n");
		matInput(B,r2,c2);
		matDisplay(B,r2,c2);
		C=matMul(A,B,max,max);
		matDisplay(C,r1,c2);
		return 0;
}

int **matMul(int** mat1,int** mat2,int rows,int columns)
{
		//int i,j;
		int** ans=matAllocate(rows,columns);
		  if (rows == 2) {
        //ans[0][0] = mat1[0][0] * mat2[0][0];
        ans=squareMatMul(mat1,mat2);
    } else {
        //dividing:
        int row2 = rows/ 2;
        int **a11 = matAllocate(row2, row2);//2x2
        int **a12 = matAllocate(row2, row2);//2x2
        int **a21 = matAllocate(row2, row2);
        int **a22 = matAllocate(row2, row2);
        int **b11 = matAllocate(row2, row2);
        int **b12 = matAllocate(row2, row2);
        int **b21 = matAllocate(row2, row2);
        int **b22 = matAllocate(row2, row2);
        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < row2; j++) {
                a11[i][j] = mat1[i][j];
                a12[i][j] = mat1[i][j + row2];
                a21[i][j] = mat1[i+row2][j];
                a22[i][j] = mat1[i+row2][j + row2];
                b11[i][j] = mat2[i][j];
                b12[i][j] = mat2[i][j+row2];
                b21[i][j] = mat2[i+row2][j];
                b22[i][j] = mat2[i+row2][j+row2];
            }
        }
        //conquering:
        int **c11 = matAdd(matMul(a11, b11, row2,row2),
                               matMul(a12, b21, row2,row2), row2,row2);
        int **c12 = matAdd(matMul(a11, b12, row2,row2),
                               matMul(a12, b22, row2,row2), row2,row2);
        int **c21 = matAdd(matMul(a21, b11, row2,row2),
                               matMul(a22, b21, row2,row2), row2,row2);
        int **c22 = matAdd(matMul(a21, b12, row2,row2),
                               matMul(a22, b22, row2,row2), row2,row2);
        //combining:
        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < row2; j++) {
                ans[i][j] = c11[i][j];
                ans[i][j + row2] = c12[i][j];
                ans[i+row2][j] = c21[i][j];
                ans[i+row2][j + row2] = c22[i][j];
            }
        }
    }

    return ans;
}
