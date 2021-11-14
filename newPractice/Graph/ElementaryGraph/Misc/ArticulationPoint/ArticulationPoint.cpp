#include <iostream>
#include <vector>

using namespace std;

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void DFS(int p, int u, int r, int color[], vector<int> adj[], int low[], int d)
{
    color[u] = 1;
    low[u] = d;

    int descendents = 0;    
    bool isArticulation = false;
    
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(color[v] == 0)
        {
            DFS(u, v, r, color, adj, low, d+1);
            
            //check if v or its descendents have a back edge to u's ancestors
            if(low[v] >= d)
                isArticulation = true;

            descendents++;
        }

        // calulate low value of u
        if(p != v)
            low[u] = min(low[u], low[v]);

    }

    if((u == r && descendents>=2) || (u!=r && isArticulation))
    {
        cout<<u<<" ";
    }

}

void initialize(int n, int arr[], int x)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = x;
    }
}

void articulationPoints(int V, vector<int> adj[])
{
    int color[V];
    initialize(V, color, 0);
    
    int low[V];
    initialize(V, low, V+1);

    for(int u=0; u<V; u++)
    {
        if(color[u] == 0)
        {
            DFS(-1, u, u, color, adj, low, 0);
        }
    }

}

int main()
{
    int V;
    cin>>V;

    int E;
    cin>>E;

    vector<int> adj[V];

    for(int i=0; i<E; i++)
    {
        int u, v;
        cin>>u;
        cin>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    articulationPoints(V, adj);

    return 0;
}