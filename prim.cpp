#include<iostream>
#include<conio.h>
using namespace std;

int maxNode,maxEdges;
int** adjMatrix;
bool* visiting;

void matDisplay(int** matrix,int order)
{
	printf("\n");
		int i,j;
		for(i=0;i<order;i++)
		{
			for(j=0;j<order;j++)
			printf("%d ",matrix[i][j]);
			printf("\n");
		}
}
void primSpanningTree(int src){
    visiting[src]=true;
    int edges=0,row,col;//edges is the counter for the number of edges row and col is to store the indexes
    while(edges<maxNode-1){
        int minValue = 999999; // Initializing the minimum value of a paticular row with a very large value
        for (int i = 0; i < maxNode; i++)
        {
            if(visiting[i])
            for (int j = 0; j < maxNode; j++)
            {
                if(!visiting[j] && adjMatrix[i][j])
                    if(adjMatrix[i][j] < minValue)
                    {
                        minValue = adjMatrix[i][j];
                        row = i;
                        col = j;
                    }
            }    
        }
        cout<<row<<"<-->"<<col<<"("<<adjMatrix[row][col]<<")\n";
        visiting[col]=true;
        edges++;
    }
}

int main(){
    cout<<"Enter the number of nodes(The graph should be a weighted undirected connected graph): ";
    cin>> maxNode;
    maxEdges = maxNode*(maxNode-1)/2;
    adjMatrix = new int*[maxNode];
    visiting = new bool[maxNode];
    for(int i=0;i<maxNode;i++)
        visiting[i] = false;
    //creating the adjacency matrix
    for(int i=0;i<maxNode;i++)
        adjMatrix[i] = new int[maxNode];
    for(int i=0;i<maxNode;i++){
        for(int j=0;j<maxNode;j++)
            adjMatrix[i][j] = 0;
    }

    cout<<"Enter the edges\n";
    for(int i = 0 ; i<maxEdges; i++){
        int src,dest,cost;
        char c;
        cout<<"Enter an edge(src dest cost): ";
        cin>> src >> dest >> cost;
        adjMatrix[src][dest] = cost;
        adjMatrix[dest][src] = cost;
        fflush(stdin);
        cout<<"Press any key to continue or to stop the input press q";
        c= getch();
        if(c=='q' || c=='Q')
        break;
        cout<<endl;
    }
    matDisplay(adjMatrix,maxNode);
    cout<<"\nThe minimum spanning tree is\n"<<"------------------------\n";
    primSpanningTree(0);
    return 0;
}