#include <limits.h>
#include <stdio.h>
#include<stdlib.h>
void minScalarMultiplication(int *p, int n,int **brac);
void printParenthesis(int **brac,int i, int j);
int main()
{
	int *arr,i,j,N,**bracket;
	printf("Enter the number of matrices whose minimum number of scalar multiplication you want to find.\n");
	scanf("%d",&N);
	arr=(int *)calloc(N+1,sizeof(int));
	bracket[N+1][N+1];
	bracket=(int **)calloc(N+1,sizeof(int *));
	for(i=0;i<=N;i++)
		bracket[i]=(int *)calloc(N+1,sizeof(int));
	printf("Enter the row numbers of the first N-1 matrices and row number and column number of last matrix\n");
	for(i=0;i<=N;i++)
		scanf("%d",&arr[i]);	
	
	minScalarMultiplication(arr,N+1,bracket);
	return 0;
}
void minScalarMultiplication(int *p, int n,int **brac)
{
	int m[n][n],i,j,k,q,L;
	for (i = 0; i < n; i++)
		m[i][i] = 0;
	for (L = 2; L < n; L++)
	{
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j]+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					brac[i][j] = k;
				}
			}
		}
	}

	printf("Optimal Parenthesization is :");
	printParenthesis(brac,1,n-1);
	printf("\nOptimal Cost is :%d\n ",m[1][n - 1]);
}
void printParenthesis(int **brac,int i, int j)
{
	if (i == j) 
	{
		printf("A%d",i);
		return;
	}

	printf("(");
	printParenthesis(brac,i,brac[i][j]);
	printParenthesis(brac,brac[i][j]+1,j);
	printf(")");
}
