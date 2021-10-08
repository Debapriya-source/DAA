#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Edge
{
    public:
    int src,dest,weight;
};
int maxNode,maxEdges;

bool sort_by_weight(Edge edge1,Edge edge2){
    return edge1.weight<edge2.weight;
}

int find_parent(int node, int *parent)
{   
    if (node == parent[node]) return node;
    return find_parent(parent[node], parent);
}

void printEdges(vector<Edge> edge){
    cout<<"The spanning tree is:\n"<<"------------------\n";
    for(int i=0;i<edge.size();i++){
        cout<<edge[i].src<<"<-->"<<edge[i].dest<<"("<<edge[i].weight<<")\n";
    }
}
void kruskalSpanningTree(vector<Edge> edge){
    int i=0,edges=0;// counter for total included edges

    vector<Edge> result;//to store the final sorted edges

    int* parent = new int[maxNode];//to store the parent nodes of each nodes
    for(int i=0 ;i<maxNode;i++)
        parent[i]=i;    //initially assumming that each node is parent of their own

    sort(edge.begin(),edge.end(),sort_by_weight);//sorting the input edges

    while(edges<maxNode-1){
        Edge currentEdge = edge[i];
        //If the current edge not create any cycle, we can store it else pass
        //To check a cycle we need to figure out if the src and dest node has same parent or not       
        if(find_parent(currentEdge.src,parent)!=find_parent(currentEdge.dest,parent)) //if there is no cycle
        {    
            result.push_back(currentEdge);
            parent[currentEdge.src] = currentEdge.dest;
            edges++;
        }
        i++;
    }
    printEdges(result);
}

int main(){
    char c;
    int src,dest,weight;
    vector<Edge> edge;
    cout<<"Enter the number of total nodes: ";
    cin>> maxNode;
    maxEdges = maxNode*(maxNode-1)/2;
    cout<<"Enter the edges with their weights(the graph should be weighted connected and undirected):\n";
    for(int i=0;i<maxEdges;i++){
        Edge *e = new Edge;
        cout<<"Enter edge(src dest weight): ";
        cin>> src >> dest >> weight;
        e->src = src;
        e->dest = dest;
        e->weight = weight;
        edge.push_back(*e);
        cout<<"press any key to continue or press q to stop input ";
        c = getch();
        if(c=='q' || c=='Q') break;
        cout<<"\n";
    }
    kruskalSpanningTree(edge);
    return 0;
}

