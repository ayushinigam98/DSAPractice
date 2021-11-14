#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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

void relax(int u, int v, int w, int d[], int p[])
{   
    if(d[u] != INT_MAX && d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        p[v] = u;
    }
}

void DFS(int u, int color[], vector<int> adj[], queue<int> &order)
{
    color[u] = 1;

    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(color[v] == 0)
        {
            DFS(v, color, adj, order);
        }
    }

    color[u] = 2;
    order.push(u);
}

void shortestPath(int V, vector<int> adj[], vector<int> W[], int s)
{
    int color[V];
    initialize(V, color, 0);

    queue<int> order;

    for(int i=0; i<V; i++)
    {
        if(color[i] == 0)
        {
            DFS(i, color, adj, order);
        }
    }

    int paths[V];

    while(!order.empty())
    {
        int u = order.front();
        order.pop();

        if(adj[u].size() == 0)
        {
            paths[u] = 0;
        }
        else
        {
            paths[u] = 0;
            for(int i=0; i<adj[u].size(); i++)
            {
                int v = adj[u][i];
                paths[u] += 1 + paths[v];
            }
        }

    }

    print(V, paths);
}

int main()
{
    int V;
    cin>>V;

    int E;
    cin>>E;

    vector<int> adj[V];
    vector<int> W[V];

    for(int i=0; i<E; i++)
    {
        int u, v, w;

        cin>>u;
        cin>>v;
        cin>>w;

        adj[u].push_back(v);
        W[u].push_back(w);
    }

    shortestPath(V, adj, W, 0);

    return 0;
}