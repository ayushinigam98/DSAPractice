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

int vertexU(Edge e)
{
    return e.u;
}

int vertexV(Edge e)
{
    return e.v;
}

vector<Edge> countSort(int c, vector<Edge> edges, int (*vertex) (Edge))
{
    int n = edges.size();
    
    int count[c];
    initialize(c, count, 0);

    for(int i=0; i<n; i++)
    {
        count[vertex(edges[i])]++;
    }

    for(int i=1; i<c; i++)
    {
        count[i] = count[i] + count[i-1];
    }

    vector<Edge> edgesFinal(n);

    for(int i=n-1; i>=0; i--)
    {
        edgesFinal[count[vertex(edges[i])]-1] = edges[i];
        count[vertex(edges[i])]--;
    }

    return edgesFinal;
}

vector<Edge> radixSort(int c, vector<Edge> edges)
{
    return countSort(c, countSort(c, edges, &vertexV), &vertexU);
}

void DFS(int u, int color[], vector<int> adj[], stack<int> &order, int c, int component[])
{
    color[u] = 1;
    component[u] = c;

    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(color[v] == 0)
        {
            DFS(v, color, adj, order, c, component);
        }
    }

    color[u] = 2;
    order.push(u);
}

void transpose(int V, vector<int> adj[], vector<int> adjTranspose[])
{
    for(int u=0; u<V; u++)
    {
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            adjTranspose[v].push_back(u);
        }
    }
}

void SCC(int V, vector<int> adj[], int &c, int component[])
{
    int color[V];
    initialize(V, color, 0);

    stack<int> order;
    
    // do DFS and get order of decreasing finishing time
    for(int i=0; i<V; i++)
    {
        if(color[i] == 0)
        {
            // call DFS
            DFS(i, color, adj, order, c, component);
        }
    }

    // transpose the graph
    vector<int> adjTranspose[V];
    transpose(V, adj, adjTranspose);

    // do DFS in the order of decreasing finishing time
    initialize(V, color, 0);
    c = 0;
    
    stack<int> temp;
    
    while(!order.empty())
    {
        int u = order.top();
        order.pop();

        if(color[u] == 0)
        {
            DFS(u, color, adjTranspose, temp, c, component);
            c++;
        }
    }

    //now component has the order component number of the vertices
}

vector<Edge> componentGraph(int V, vector<int> adj[], int &c)
{
    // find the strongly connected component id for each vertex
    c = 0;
    int component[V];
    SCC(V, adj, c, component);
    
    // now add the edges of the component graph
    vector<Edge> edges;

    for(int u=0; u<V; u++)
    {
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];

            if(component[u] != component[v])
            {
                Edge temp;
                temp.u = component[u];
                temp.v = component[v];
                edges.push_back(temp);
            }
        }
    }

    //now we need to sort the edges 
    vector<Edge> sortedEdges = radixSort(c, edges);

    //now remove the extra edges
    vector<Edge> finalEdges;

    Edge e;
    e.u = -1;
    e.v = -1;
    for(int i=0; i<sortedEdges.size(); i++)
    {
        if(sortedEdges[i].u != e.u || sortedEdges[i].v != e.v)
        {
            e = sortedEdges[i];
            finalEdges.push_back(sortedEdges[i]);
        }
    }

    return finalEdges;
}

bool isSemiConnected(int V, vector<int> adj[])
{
    // get the component graph
    int Vcomponent;
    vector<Edge> edges = componentGraph(V, adj, Vcomponent);
    
    vector<int> adjComponent[Vcomponent];
    for (int i = 0; i < edges.size(); i++)
    {
        adjComponent[edges[i].u].push_back(edges[i].v);
    }
    
    // topologically sort it
    stack<int> order;
    int color[Vcomponent];
    initialize(Vcomponent, color, 0);

    for(int i=0; i<Vcomponent; i++)
    {
        if(color[i] == 0)
        {
            DFS(i, color, adjComponent, order, 1, color);
        }
    }
    
    // check if it is a linked chain
    int u = order.top();
    order.pop();
    while(!order.empty())
    {
        int v = order.top();
        order.pop();
    
        bool flag = false;
        
        for(int i=0; i<adjComponent[u].size(); i++)
        {
            if(adjComponent[u][i] == v)
            {
                flag = true;
            }
        }
        
        if(flag == false)
            return false;
        
        u = v;
    }

    return true;
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

    cout<<isSemiConnected(V, adj);

    return 0;
}