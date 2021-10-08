#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int vertex;
    struct node *next;
} node;

node *createNode(int n)
{
    node *newNode = malloc(sizeof(node));
    newNode->vertex = n;
    newNode->next = NULL;
    return newNode;
}

typedef struct QNode
{
    int data;
    struct QNode *next;
} QNode;

QNode *createQNode(int data)
{
    QNode *newNode = malloc(sizeof(QNode*));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct Queue
{
    QNode *front, *rear;
} Queue;

Queue *createQ()
{
    Queue *q = malloc(sizeof(Queue*));
    q->front = q->rear = NULL;
    return q;
}
int isEmpty(Queue *q)
{
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, int data)
{
    QNode *newNode = createQNode(data);
    if (isEmpty(q))
        q->front = q->rear = newNode;
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
int dequeue(Queue *q)
{
    int value;
    if (isEmpty(q))
        return -1;
    else
    {
        QNode *temp = q->front;
        q->front = q->front->next;
        if (q->front == NULL)
            q->rear = NULL;
        value = temp->data;
        free(temp);
        return value;
    }
}

typedef struct Graph
{
    int totalNodes;
    node **adjlist;
    int *visited;
} Graph;

Graph *createGraph(int totalNode)
{
    Graph *newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph->totalNodes = totalNode;
    newGraph->adjlist = (node**)calloc(totalNode, sizeof(node*));
    newGraph->visited = (int*)calloc(totalNode, sizeof(int));
    return newGraph;
}

void addEdge(Graph *g, int src, int dest)
{
    //printf("In the addEdge function\n");
    node *srcNode = createNode(src);
    node *destNode = createNode(dest);
    //printf("In the addEdge function: two nodes created, %d, %d\n",srcNode->vertex,destNode->vertex);
    //connecting src->dest
    //printf("In the addEdge function: connecting src->dest\n");
    if (g->adjlist[src] == NULL)
    {
        
        //srcNode->next = destNode;
        g->adjlist[src] = destNode; // head of the linked list
        //printf("In the addEdge function: head node created\n");
    }
    else
    {
        //printf("In the addEdge function: else;\n");
        node *temp = g->adjlist[src];
        //printf("In the addEdge function: else: %d\n",temp->vertex);
        while (temp->next != NULL){
            temp = temp->next;
            //printf("In the while loop temp->next = %d\n",temp->vertex);
        }
        //printf("In the addEdge function: All node travesed, last node->%d\n",temp->vertex);
        temp->next = destNode;//srcNode;
       // srcNode->next = destNode;
        //printf("In the addEdge function: src:%d->dest:%d connected\n",srcNode->vertex,destNode->vertex);
    }
    //connecting dest->src
    //printf("In the addEdge function: dest->src connection\n");
    if (g->adjlist[dest] == NULL)
    {
       // destNode->next = srcNode;
        g->adjlist[dest] = srcNode; // head of the linked list

        //printf("In the addEdge function: head created\n");
    }
    else
    {
        //printf("In the addEdge function:else\n");
        node *temp = g->adjlist[dest];
        //printf("In the addEdge function: else: %d\n",temp->vertex);
        while (temp->next != NULL){
            temp = temp->next;
        //printf("In the addEdge function: All node travesed, last node->%d\n",temp->vertex);
        }
        temp->next =srcNode;// destNode;
        //destNode->next = srcNode;
        //printf("In the addEdge function: dest:%d->src:%d connected\n",destNode->vertex,srcNode->vertex);
    }
}

void bfs(struct Graph *graph, int startVertex)
{
  Queue *q = createQ();

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q))
  {
    //printQueue(q);
    int currentVertex = dequeue(q);
    printf("Visited %d\n", currentVertex);

    node *temp = graph->adjlist[currentVertex];

    while (temp)
    {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0)
      {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}

int main()
{
  Graph *graph = createGraph(6);
printf("Graph created\n");


  addEdge(graph, 0, 1);
  //printf("1st edge added\n");
  addEdge(graph, 0, 2);
  //printf("2nd added\n");
  addEdge(graph, 1, 5);
  //printf("3rd added\n");
  addEdge(graph, 2, 4);
  addEdge(graph, 2, 3);
//   addEdge(graph, 2, 4);
//   addEdge(graph, 3, 4);
    //printf("All added\n");
    
  bfs(graph, 0);

  return 0;
}