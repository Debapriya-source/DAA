#include<iostream>
#include<conio.h>
#include<queue>
using namespace std;

int maxNode,maxEdges;
int** adjMatrix;
bool* visited;
queue<int> q;

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
bool allVisited(){
    for (int i = 0; i < maxNode; i++)
        if(!visited[i]) return false;
    return true;
}
void displayQueue(queue<int> q)
{
	queue<int> Queue = q;
	while (!Queue.empty()) {
		cout << '\t' << Queue.front();
		Queue.pop();
	}
	cout << '\n';
}
void BFS(int src){
    //if(!q.empty()) displayQueue(q);
    //cout<<"BFS("<<src<<") ";
    if(allVisited() && q.empty()) return;
    visited[src]=true;
    for(int i =0;i<maxNode;i++){
        //cout<<"In the loop\n";
        if(!visited[i] && adjMatrix[src][i]){
            visited[i]=true;
            cout<<"\n"<<src<<"<-->"<<i<<"\n";
            q.push(i);
            //cout<<i<<" pushed\n";
        }
    }
    if(!q.empty()){
        //cout<<q.front()<<" ";
        q.pop();
        BFS(q.front());
    }
}

int main(){
    int srcNode;
    cout<<"Enter the number of nodes(The graph should be a connected graph): ";
    cin>> maxNode;
    maxEdges = maxNode*(maxNode-1)/2;
    adjMatrix = new int*[maxNode];
    visited = new bool[maxNode];
    for(int i=0;i<maxNode;i++)
        visited[i] = false;
    //creating the adjacency matrix
    for(int i=0;i<maxNode;i++)
        adjMatrix[i] = new int[maxNode];
    for(int i=0;i<maxNode;i++){
        for(int j=0;j<maxNode;j++)
            adjMatrix[i][j] = 0;
    }

    cout<<"Enter the edges\n";
    for(int i = 0 ; i<maxEdges; i++){
        int src,dest;
        char c;
        cout<<"Enter an edge(src dest): ";
        cin>> src >> dest;
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
        fflush(stdin);
        cout<<"Press any key to continue or to stop the input press q";
        c = getch();
        if(c=='q' || c=='Q')
        break;
        cout<<endl;
    }
    matDisplay(adjMatrix,maxNode);
    cout<<"Enter the src node: ";
    cin>> srcNode;
    cout<<"\nThe spanning tree is\n"<<"------------------------\n";
    q.push(srcNode);
    BFS(srcNode);
    return 0;
}