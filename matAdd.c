#include <stdlib.h>
#include <stdio.h>
int **matAllocate(int,int);
void matInput(int**,int,int);
void matDisplay(int**,int,int);

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
int main()
{
		int r,c;
		int **A,**B,**C;
		printf("Enter the number of rows and columns: ");
		scanf("%d%d",&r,&c);
		A=matAllocate(r,c);
		B=matAllocate(r,c);
		C=matAllocate(r,c);
		printf("Enter the elements of matrix A:\n");
		matInput(A,r,c);
		printf("Enter the elements of matrix B:\n");
		matInput(B,r,c);
		C=matAdd(A,B,r,c);
		matDisplay(C,r,c);
		return 0;
}

