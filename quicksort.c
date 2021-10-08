#include <stdio.h> 
#include <stdlib.h> 

void quickSort(int *arr, int n,int,int);
void swap(int *x, int *y);
void input(int *arr,int n);
void display(int *arr, int n); 

int main() 
{ 
    int n,*arr;
    printf("\nEnter number of elements:\n");
	scanf("%d",&n);

    arr = (int *)calloc(n,sizeof(int));

    printf("\nEnter %d elements:\n",n);
    input(arr,n);

    printf("\nOriginal array: \n"); 
    display(arr, n); 

	quickSort(arr, n,0,n); 

	printf("\nSorted array: \n"); 
	display(arr, n); 

	return 0; 
}

int partition(int *arr, int n, int low, int high)
{
    int pivot = arr[low];
    int i=low,j=high-1;

    while(i<j)
    {
        while (arr[i]<=pivot)
            i++;
        while (arr[j]>pivot)
            j--;
        if (i<j)
            swap(&arr[i],&arr[j]);
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void quickSort(int *arr, int n, int low, int high)
{
    int j;
    if (low<high)
    {
        j = partition(arr,n,low,high);
        quickSort(arr,n,low,j);
        quickSort(arr,n,j+1,high);
    }
}

void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
}

void input(int *arr,int n)
{
    int i;
    for (i=0;i<n;i++)
        scanf("%d",&arr[i]);
}

void display(int *arr, int n) 
{ 
	int i; 
	for (i=0; i<n; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
}