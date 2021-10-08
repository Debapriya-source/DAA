#include <stdio.h>
#include <stdlib.h>

int *heap,k;

void input(int);
void display(int);
void create_max_heap(int);
void create_min_heap(int);
void max_heapify(int, int);
void min_heapify(int, int);
void swap(int, int);

void main()
{
    int n;
    printf("Enter the total number of elements: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d",&k);
    heap = (int *)calloc(n, sizeof(int));
    printf("Enter %d elements:\n", n);
    input(n);
    printf("The elements are: ");
    display(n);
    create_max_heap(n);
    printf("The max heap is: ");
    display(n);
    create_min_heap(n);
    printf("The min heap is: ");
    display(n);
}

void input(int length)
{
    for (int i = 0; i < length; i++)
        scanf("%d", &heap[i]);
}
void display(int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", heap[i]);
    printf("\n");
}
void swap(int a, int b)
{
    int temp = heap[b];
    heap[b] = heap[a];
    heap[a] = temp;
}
void create_min_heap(int length)
{
    //loop is starting from n/2 to ignore the leaf nodes
    for (int i = length / k - 1; i >= 0; i--)
        min_heapify(i, length);
}
void create_max_heap(int length)
{
    //loop is starting from n/2 to ignore the leaf nodes
    for (int i = length / k - 1; i >= 0; i--)
        max_heapify(i, length);
}
void max_heapify(int currentNodeIndex, int length)
{
    int child,max = currentNodeIndex;
    for(int i=1;i<=k;i++){
        child = k*currentNodeIndex + i;
        if(child<length && heap[child]>heap[max]) max = child;
    }
    if (max != currentNodeIndex)
    {
        swap(currentNodeIndex, max);
        max_heapify(max, length); //after swapping the maximum element we have to make sure that the swapped element is also satisfying the heap property or not
    }
}
void min_heapify(int currentNodeIndex, int length)
{
     int child,min = currentNodeIndex;
    for(int i=1;i<=k;i++){
        child = k*currentNodeIndex + i;
        if(child<length && heap[child]<heap[min]) min = child;
    }
    if (min != currentNodeIndex)
    {
        swap(currentNodeIndex, min);
        min_heapify(min, length); //after swapping the maximum element we have to make sure that the swapped element is also satisfying the heap property or not
    }
}