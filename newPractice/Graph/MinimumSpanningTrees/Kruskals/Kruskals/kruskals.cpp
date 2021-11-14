#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u;
    int v;
    int w;

    Edge()
    {

    }

    Edge(int uval, int vval, int wval)
    {
        u = uval;
        v = vval;
        w = wval;
    }
};

void makeSet(int n, int parent[], int rank[])
{
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
        rank[i] = i;
    }
}

int findSet(int x, int parent[])
{
    if(x != parent[x])
        parent[x] = findSet(parent[x], parent);
    
    return parent[x];
}

void unionSet(int x, int y, int parent[], int rank[])
{   
    x = findSet(x, parent);
    y = findSet(y, parent);

    if(rank[x]>rank[y])
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;

        if(rank[x] == rank[y])
        {
            rank[y]++;
        }
    }
}

bool sortEdge(Edge Edge1, Edge Edge2)
{
    return Edge1.w < Edge2.w;
}

void kruskals(Edge Edges[], int V, int E)
{
    sort(Edges, Edges + E, sortEdge);
    int parent[V];
    int rank[V];
    
    makeSet(V, parent, rank);

    for(int i=0; i<E; i++)
    {
        if(findSet(Edges[i].u, parent) != findSet(Edges[i].v, parent))
        {
            cout<<Edges[i].u<<"-"<<Edges[i].v<<endl;
            unionSet(Edges[i].u, Edges[i].v, parent, rank);
        }
    }
}

int main()
{
    int V;
    cin>>V;

    int E;
    cin>>E;

    Edge Edges[E];

    Edge temp;
    for(int i=0; i<E; i++)
    {
        int u, v, w;
        cin>>u;
        cin>>v;
        cin>>w;

        temp.u = u;
        temp.v = v;
        temp.w = w;

        Edges[i] = temp;
    }

    kruskals(Edges, V, E);

    return 0;
}