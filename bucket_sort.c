#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
} typedef node;

void bucket_sort(int *, int);
int get_max(int *, int);
node* insert(node *head, int data);
void display_bucket(node *bucket);
node *sort_bucket(node *bucket);
void swap(int *a, int *b);

int BUCKETS;
int get_max(int *arr, int size)
{
  int max = arr[0];
  for (int i = 0; i < size; i++)
    max = (arr[i] > max) ? arr[i] : max;
  return max;
}
node *insert(node *head, int data)
{
  node *temp = head;
  node *newNode = (node *)calloc(1, sizeof(node));
  newNode->data = data;
  if (head == NULL)
  {
    head = newNode;
    head->next = NULL;
    return head;
  }
  else
  {
    while (head->next)
      head = head->next;
    head->next = newNode;
  }
  return temp;
}

void bucket_sort(int *arr, int size)
{
  BUCKETS = (get_max(arr, size) / 5) + 1;
  node **bucket = (node **)calloc(BUCKETS, sizeof(node *));
  for (int i = 0; i < size; i++)
    bucket[arr[i] / 5] = insert(bucket[arr[i] / 5], arr[i]);
  for (int i = 0; i < BUCKETS; i++)
    bucket[i] = sort_bucket(bucket[i]);
  for (int i = 0; i < BUCKETS; i++)
    display_bucket(bucket[i]);
  printf("\n");
}
void display_bucket(node *bucket)
{
  if (!bucket)
    return;
  while (bucket)
  {
    printf("%d ", bucket->data);
    bucket = bucket->next;
  }
}

node *sort_bucket(node *bucket)
{
  node *head = bucket;
  for (node *i = head; i && i->next!=NULL; i = i->next)
  {
    for (node *j = i->next; j!=NULL; j = j->next)
    {
      if (i->data > j->data)
        swap(&i->data, &j->data);
    }
  }
  return head;
}
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
void main()
{
  int n;
  printf("Total number of inputs: ");
  scanf("%d", &n);
  int *arr = (int *)calloc(n, sizeof(int));
  printf("Enter the elements:\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  bucket_sort(arr, n);
}
