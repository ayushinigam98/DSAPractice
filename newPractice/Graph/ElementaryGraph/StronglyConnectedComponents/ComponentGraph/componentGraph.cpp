#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Edge
{
    int u;
    int v;

    Edge()
    {

    }

    Edge(int valU, int valV)
    {
        u = valU;
        v = valV;
    }
};

void initialize(int n, int arr[], int x)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = x;
    }
}

void DFS(int u, int color[], vector<int> adj[], stack<int> &s, int c, int component[])
{
    //color the node discovered
    color[u] = 1;
    component[u] = c;
    //explore the neighbours
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(color[v] == 0)
        {
            DFS(v, color, adj, s, c, component);
        }
    }   

    // color the node finished
    color[u] = 2;
    
    s.push(u);
}

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int vertexU(Edge E)
{
    return E.u;
}

int vertexV(Edge E)
{
    return E.v;
}

void countSort(vector<Edge> &edges, int c, int (*vertex) (Edge))
{
    int n = edges.size();
    
    int C[c];

    initialize(n, C, 0);

    for(int i=0; i<n; i++)
    {
        C[vertex(edges[i])]++;
    }

    for(int i=1; i<n; i++)
    {
        C[i] = C[i] + C[i-1];
    }

    Edge sortedEdges[n];

    for(int i = n-1; i>=0; i--)
    {
        sortedEdges[C[vertex(edges[i])] - 1] = edges[i];
        C[vertex(edges[i])]--;
    }


    for(int i=0; i<n; i++)
    {
        edges[i] = sortedEdges[i];
    }
}

void sort(vector<Edge> &edges, int c)
{
    countSort(edges, c, &vertexV);
    countSort(edges, c, &vertexU);
}


vector<Edge> DFS_visit(int V, vector<int> adj[])
{
    int c = 1;
    int component[V];

    stack<int> s;
    int color[V];

    // initialization
    // color all the vertices white
    initialize(V, color, 0);

    // first DFS
    for(int i=0; i<V; i++)
    {
        if(color[i] == 0)
        {
            DFS(i, color, adj, s, c, component);
        }
    }

    
    // transpose
    vector<int> adjTrans[V];

    for(int u=0; u<V; u++)
    {
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];

            adjTrans[v].push_back(u);
        }
    }

    // second DFS
    initialize(V, color, 0);
    c = 0;
    while(!s.empty())
    {
        int u = s.top();
        s.pop();

        if(color[u] == 0)
        {
            DFS(u, color, adjTrans, s, c, component);
            c++;
        }
    }
    
    // add the edges
    vector<Edge> edges;
    
    for(int u=0; u<V; u++)
    {
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];

            if(component[u] != component[v])
            {
                Edge e;
                e.u = component[u];
                e.v = component[v];
                edges.push_back(e);
            }
        }
    }

    //sort
    sort(edges, c);
 
    //remove excess
    int n = edges.size();
    
    Edge e;
    e.u = -1;
    e.v = -1;

    vector<Edge> edgesFinal;
    
    for(int i=0; i<n; i++)
    {
        if(e.u != edges[i].u || e.v != edges[i].v)
        {
            e = edges[i];
            edgesFinal.push_back(e);
        }
    }

    return edgesFinal;
}

int main()
{
    int V, E;
    cin>>V;  
    cin>>E;

    vector<int> adj[V];  

    for(int i=0; i<E; i++)
    {
        int u, v;
        cin>>u;
        cin>>v;

        adj[u].push_back(v);
    }

    vector<Edge> edges = DFS_visit(V, adj);

    for(int i=0; i<edges.size(); i++)
    {
        cout<<"("<<edges[i].u<<","<<edges[i].v<<")"<<endl;
    }

    return 0;
}