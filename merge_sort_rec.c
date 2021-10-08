#include <stdio.h>
#include <stdlib.h>

void input(int *, int);
void display_array(int *, int);
void merge_sort(int *, int, int);
void merge(int*, int, int , int );

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
void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = l + r / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
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
    merge_sort(arr, 0, n - 1);
    display_array(arr, n);
}