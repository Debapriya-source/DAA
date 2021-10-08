#include <stdio.h>
#include <stdlib.h>

void input(int *, int);
void display_array(int *, int);
void swap(int*,int*);
void bubble_sort(int *, int);

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

void bubble_sort(int *arr, int n)
{   
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            swap(&arr[i], &arr[i + 1]);
    bubble_sort(arr, n - 1);
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
    bubble_sort(arr, n);
    display_array(arr, n);
}