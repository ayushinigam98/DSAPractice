#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void initialize(int n, int arr[], int x)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = x;
    }
}

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void DFS(int u, int color[], int low[], vector<int> adj[], int V)
{
    color[u] = 1;
    
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(color[v] == 0)
        {
            DFS(v, color, low, adj, V);
        }

        low[u] = min(low[u], min(low[v], v));
    }
}

void reachability(int V, vector<int> adj[])
{
    int color[V];
    initialize(V, color, 0);

    int low[V];
    initialize(V, low, V);

    for(int u=0; u<V; u++)
    {
        if(color[u] == 0)
        {
            DFS(u, color, low, adj, V);
        }
    }

    print(V, low);
}

int main()
{
    int V;
    cin>>V;

    int E;
    cin>>E;

    vector<int> adj[E];

    for(int i=0; i<E; i++)
    {
        int u, v;
        cin>>u;
        cin>>v;

        adj[u].push_back(v);
    }

    reachability(V, adj);

    return 0;
}