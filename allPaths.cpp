#include <iostream>
#include <vector>
#include <conio.h>
#include <cstring>
using namespace std;

int maxNode, maxEdges;
int **adjMatrix;
bool *visited;
vector<int> path;
int path_counter;

void display(vector<int> path)
{
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << (i != path.size() - 1 ? "-->" : "\n");
}
void matDisplay(int **matrix, int order)
{
    printf("\n");
    int i, j;
    for (i = 0; i < order; i++)
    {
        for (j = 0; j < order; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
void find_path(int src, int dest)
{
    visited[src] = true;
    path.push_back(src);
    if (src == dest)
    {
        path_counter++;
        display(path);
        path.pop_back();
        visited[dest] = false;
        return;
    }
    for (int i = 0; i < maxNode; i++)
        if (adjMatrix[src][i] && !visited[i])
            find_path(i, dest);
    path.pop_back();
    visited[src] = false;
}
int main()
{
    int srcNode, destNode;
    cout << "Enter the number of nodes(The graph should be a undirected connected graph): ";
    cin >> maxNode;
    maxEdges = maxNode * (maxNode - 1) / 2;
    visited = new bool[maxNode];
    memset(visited, false, sizeof(visited));
    adjMatrix = new int *[maxNode];
    //creating the adjacency matrix
    for (int i = 0; i < maxNode; i++)
        adjMatrix[i] = new int[maxNode];
    for (int i = 0; i < maxNode; i++)
        for (int j = 0; j < maxNode; j++)
            adjMatrix[i][j] = 0;

    cout << "Enter the edges\n";
    for (int i = 0; i < maxEdges; i++)
    {
        int src, dest;
        char c;
        cout << "Enter an edge(src dest): ";
        cin >> src >> dest;
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
        fflush(stdin);
        cout << "Press any key to continue or to stop the input press q";
        c = getch();
        if (c == 'q' || c == 'Q')
            break;
        cout << endl;
    }
    matDisplay(adjMatrix, maxNode);
    cout << "Enter the src and dest node: ";
    cin >> srcNode >> destNode;
    path_counter = 0;
    find_path(srcNode, destNode);

    cout << "Total paths: " << path_counter << endl;
    return 0;
}
