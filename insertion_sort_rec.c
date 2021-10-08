#include <stdio.h>
#include <stdlib.h>

void input(int *, int);
void display_array(int *, int);
void insertion_sort(int *, int);

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
void insertion_sort(int* arr, int n)
{
    if (n <= 1)
        return;
    insertion_sort( arr, n-1 );
    int last = arr[n-1];
    int j = n-2;
    while (j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
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
    insertion_sort(arr, n);
    display_array(arr, n);
}