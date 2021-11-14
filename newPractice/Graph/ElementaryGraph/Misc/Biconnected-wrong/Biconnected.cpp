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

void initialize(int n, int arr[], int x)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = x;
    }
}

void DFS(int u, int color[], int low[], vector<int> adj[], int d, int p)
{
    color[u] = 1;
    low[u] = d;

    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(color[v] == 0)
        {
            DFS(v, color, low, adj, d+1, u);
       
            if(low[v] > d)
            {
                cout<<u<<"-"<<v<<endl;
            }
        }

        if(v != p)
        {
            low[u] = min(low[u], low[v]);
        }

    }
}

void biconnected(int V, vector<int> adj[])
{
    int color[V];
    initialize(V, color, 0);
    
    int low[V];
    initialize(V, low, V+1);

    for(int u=0; u<V; u++)
    {
        if(color[u] == 0)
        {
            DFS(u, color, low, adj, 0, -1);
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
    
    biconnected(V, adj);

    return 0;
}