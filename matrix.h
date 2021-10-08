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
