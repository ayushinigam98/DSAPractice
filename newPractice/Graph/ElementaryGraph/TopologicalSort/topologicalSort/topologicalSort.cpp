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

void DFS(int u, vector<int> adj[], int color[], stack<int> &order)
{
    color[u] = 1;

    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(color[v] == 0)
        {
            DFS(v, adj, color, order);
        }
    }

    color[u] = 2;
    order.push(u);
}

void topologicalOrder(int V, vector<int> adj[])
{
    stack<int> order;

    int color[V];
    initialize(V, color, 0);

    for(int i=0; i<V; i++)
    {
        if(color[i] == 0)
        {
            DFS(i, adj, color, order);
        }
    }

    while(!order.empty())
    {
        cout<<order.top()<<" ";
        order.pop();
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
    }

    topologicalOrder(V, adj);

    return 0;
}