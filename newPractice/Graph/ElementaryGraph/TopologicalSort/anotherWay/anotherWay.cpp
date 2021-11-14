#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void initialize(int n, int arr[], int x)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = x;
    }
}

void topologicalOrder(int V, vector<int> adj[])
{
    queue<int> q;
    int inDegree[V];
    initialize(V, inDegree, 0);

    for(int u=0; u<V; u++)
    {
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            inDegree[v]++;
        }
    }

    for(int u=0; u<V; u++)
    {
        if(inDegree[u] == 0)
            q.push(u);
    }

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        cout<<u<<" ";

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];

            inDegree[v]--;

            if(inDegree[v] == 0)
                q.push(v);
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
    }

    topologicalOrder(V, adj);

    return 0;
}