#include<stdio.h>
#include<stdlib.h>

int n, **matrix;

int calculateMin(int *arr,int left,int right);
void printParenthesis(int left,int right,char *matName);
void allocate ();
void displayMatrix ();

void main()
{
    char matName='A'; //name of the matrices, necessary for printing parenthesized form

    //input - number of matrices
    printf("\nEnter the number of matrices:\n");
    scanf("%d",&n);

    n++; //for n matrices, n+1 inputs are required, hence the increment

    //memory alocation for array containing the rows and columns
    int *arr = (int *)calloc(n,sizeof(int));

    //orders accepted from user
    //Eg: For 3 matrices A(2*3),B(3*4) and C(4*3), the array = {2,3,4,3}
    printf("\nEnter rows of each matrices and the column of the last matrix at the end:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    //printing the orders of input matrices
    printf("\nYou've chosen matrices as follows:\n\n");
    for(int i=0;i<n-1;i++)
        printf("Matrix %c of Order (%d * %d)\n",matName++,arr[i],arr[i+1]);
    
    //allocating memory for the sequence matrix
    allocate(matrix);
    
    //calculating and printing minimum number of scalar multiplications
    printf("\nMinimum number of scalar multiplications = %d\n",calculateMin(arr,1,n-1));
    
    printf("\nThe best sequence for the multiplications is: ");
    matName = 'A'; //reinitializzed to 'A'
    printParenthesis(1,n-1,&matName); 
}
int calculateMin(int *arr,int left,int right)
{
    if(right==left) //if there is a single matrix there will be no scalar multiplication
        return 0;
    
    int i,j,min = INT_MAX;
    for(i=left;i<right;i++)
    {
        int value = calculateMin(arr,left,i) + calculateMin(arr,i+1,right) + arr[left-1]*arr[i]*arr[right]; //the last one is the value for of total scalar multiplications for two matrices
        if(min >= value)
        {
            min = value;
            matrix[left][right] = i;
        }
    }
    return min;
}

void printParenthesis(int left,int right,char *matName)
{
    //to be uncommented during testing/debugging
    //printf("%d %d %c\n",left,right,*name);
    if(left == right)
    {
        printf("%c",*matName);
        *matName = *matName + 1;
        return;
    }
    printf("(");
    printParenthesis(left,matrix[left][right],matName);
    printParenthesis(matrix[left][right]+1,right,matName);
    printf(")");
}

void allocate()
{
    int i;
    matrix = (int **)calloc(n,sizeof(int *));
        for(i=0;i<n;i++)
            matrix[i] = (int *)calloc(n,sizeof(int));
}
