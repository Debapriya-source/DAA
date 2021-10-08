#include<stdio.h>
#include<stdlib.h>

int **matAlc(int row,int column);
void input(int**,int,int);
void display(int** matrix,int row,int column);
int **matMul(int** mat1,int** mat2,int r1,int c1,int c2);
int main()
{
    int **a,**b,r1,r2,c1,c2;
    printf("\nNumber of rows of the 1st matrix=");
    scanf("%d",&r1);
    printf("\nNumber of columns of the 1st matrix=");
    scanf("%d",&c1);
    printf("\nNumber of rows of the 2nd matrix=");
    scanf("%d",&r2);
    printf("\nNumber of columns of the 2nd matrix=");
    scanf("%d",&c2);
    if(c1==r2)
    {
        a=matAlc(r1,c1);
        input(a,r1,c1);
        b=matAlc(r2,c2);
        input(b,r2,c2);
        printf("The multiplication is...\n-------------------------\n");
        display(a,r1,c1);
        printf("*\n");
        display(b,r2,c2);
        printf("------------------------\n");
        display(matMul(a,b,r1,c1,c2),r1,c2); //c1 or r2 same thing
    }
    else
        printf("Given matrix cannot be multiplied!\n");
}

int **matAlc(int row,int column)
{
    int **matrix=(int**)calloc(row,sizeof(int*));
    for (int i = 0; i < row; i++)
    {
        matrix[i]=(int*)calloc(column,sizeof(int));
    }
    return matrix;
}
void input(int **matrix,int row,int column)
{
    printf("Input the matrix: \n");
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            scanf("%d",&matrix[i][j]); 
            printf("Input done!\n");
}

void display(int** matrix,int row,int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
    
}

int **matMul(int** mat1,int** mat2,int r1,int c1,int c2)
{
    int **res;
    res=matAlc(r1,c2);
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)            
                res[i][j]+=mat1[i][k]*mat2[k][j];      
    }
    return res;
}
