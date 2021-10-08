#include <stdlib.h>
#include <stdio.h>
int **matAllocate(int, int);
void matInput(int **, int, int);
void matDisplay(int **, int, int);
void getCofactor(int **mat, int **temp, int c_r, int c_c, int n);
int determinantOfMatrix(int **mat, int n);

int **matAllocate(int rows, int columns)
{
    int **matrix = (int **)calloc(rows, sizeof(int *));
    int i;
    for (i = 0; i < rows; i++)
        matrix[i] = (int *)calloc(columns, sizeof(int));
    return matrix;
}
void matInput(int **matrix, int rows, int columns)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
            scanf("%d", &matrix[i][j]);
    }
}
void matDisplay(int **matrix, int rows, int columns)
{
    printf("\n");
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
void getCofactor(int **mat, int **temp, int c_r,
                 int c_c, int n)
{
    int i = 0, j = 0;

    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those
            //  element which are not in given row and
            //  column
            if (row != c_r && col != c_c)
            {
                temp[i][j++] = mat[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    //matDisplay(temp,n-1,n-1);
}
int determinantOfMatrix(int **mat, int n)
{
    int D = 0; // Initialize result

    //  Base case : if matrix contains single element
    if (n == 1)
        return mat[0][0];

    int **temp = matAllocate(n - 1, n - 1); // To store cofactors of each elements, eg. for 3x3 each element will have a 2x2 cofactor.

    int sign = 1; // To store sign

    // Iterate for each element of first row
    for (int i = 0; i < n; i++)
    {
        // Getting Cofactor of mat[0][f]
        getCofactor(mat, temp, 0, i, n);
        D += sign * mat[0][i] * determinantOfMatrix(temp, n - 1);
        // terms are to be added with alternate sign
        sign = -sign;
    }

    return D;
}
int main()
{
    int o, **A;
    printf("enter the order: ");
    scanf("%d", &o);
    A = matAllocate(o, o);
    printf("Enter the matrix:\n");
    matInput(A, o, o);
    matDisplay(A, o, o);
    printf("Determinant of the matrix is : %d\n",
           determinantOfMatrix(A, o));
    return 0;
}
