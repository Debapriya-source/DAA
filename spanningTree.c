#include<stdio.h>
#include<stdlib.h>

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


void dfs(Graph* g, int startvertex)
{
    node* temp = g->adjlist[startvertex];
    g->visited[startvertex] = 1;
    printf("Node visited: %d\n",startvertex);
    while (temp)
    {
        //int currentVertex = temp->vertex;
        if(!g->visited[temp->vertex])
            dfs(g, temp->vertex);
        temp = temp->next;
    }   
}

void printGraph(Graph *g)
{
  int v;
  for (v = 0; v < g->totalNodes; v++)
  {
    node *temp = g->adjlist[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp)
    {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
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

    printGraph(graph);

  return 0;
}