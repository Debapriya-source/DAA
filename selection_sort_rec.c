#include <stdio.h>
#include <stdlib.h>

void input(int *, int);
void display_array(int *, int);
void swap(int*,int*);
void selection_sort(int *, int);
int maxIndex(int* arr,int n);

void input(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}
void display_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void selection_sort(int* arr, int n)
{
    if(n==1) return;
    swap(&arr[maxIndex(arr,n)],&arr[n-1]); //swap the max value with the last element
    selection_sort(arr,n-1);
}
int maxIndex(int* arr,int n){
    int index=0;
    for(int i = 0; i < n ; i++ )
        if (arr[index]<arr[i])
            index = i;
    return index;        
}
void swap(int* a,int* b){
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}
void main()
{
    int *arr, n;
    printf("Enter the total number of inputs: ");
    scanf("%d", &n);
    arr = (int *)calloc(n, sizeof(int));
    printf("Enter the inputs:\n");
    input(arr, n);
    printf("The sorted order is:\n");
    selection_sort(arr, n);
    display_array(arr, n);
}