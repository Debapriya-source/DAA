#include <stdio.h>
#include <stdlib.h>

int *heap;

void input(int);
void display(int);
void create_max_heap(int);
void create_min_heap(int);
void max_heapify(int, int);
void heap_sort(int,int);
void min_heapify(int, int);
void swap(int, int);

void main()
{
    int n,c;
    printf("Enter the total number of elements: ");
    scanf("%d", &n);
    heap = (int *)calloc(n, sizeof(int));
    printf("Enter %d elements:\n", n);
    input(n);
    printf("The elements are: ");
    display(n);
    printf("1.Ascending order heap sort.\n2.Descending order heap sort\n");
    scanf("%d",&c);
    switch(c){
        case 1:
        create_max_heap(n);
        break;
        case 2:
        create_min_heap(n);
        break;
        default:
        printf("Invalid choice\n");
    }
    heap_sort(n,c);
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
    for (int i = length / 2 - 1; i >= 0; i--)
        min_heapify(i, length);
}
void create_max_heap(int length)
{
    //loop is starting from n/2 to ignore the leaf nodes
    for (int i = length / 2 - 1; i >= 0; i--)
        max_heapify(i, length);
}
void max_heapify(int currentNodeIndex, int length)
{
    int left = 2 * currentNodeIndex + 1;
    int right = 2 * currentNodeIndex + 2;
    int max = currentNodeIndex;
    if (left < length && heap[left] > heap[max])
        max = left;
    if (right < length && heap[right] > heap[max])
        max = right;
    if (max != currentNodeIndex)
    {
        swap(currentNodeIndex, max);
        max_heapify(max, length); //after swapping the maximum element we have to make sure that the swapped element is also satisfying the heap property or not
    }
}
void min_heapify(int currentNodeIndex, int length)
{
    int left = 2 * currentNodeIndex + 1;
    int right = 2 * currentNodeIndex + 2;
    int min = currentNodeIndex;
    if (left < length && heap[left] < heap[min])
       min = left;
    if (right < length && heap[right] < heap[min])
        min = right;
    if (min != currentNodeIndex)
    {
        swap(currentNodeIndex, min);
        min_heapify(min, length); //after swapping the maximum element we have to make sure that the swapped element is also satisfying the heap property or not
    }
}
void heap_sort(int length,int option){
    if(length<=0) return;
    swap(0,length-1);
    if(option==1) max_heapify(0,length-1);
    else min_heapify(0,length-1);
    heap_sort(length-1,option);
}