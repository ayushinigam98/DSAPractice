#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void initialize(int n, int arr[], int x)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = x;
    }
}

void relax(int u, int v, int w, int d[], int p[])
{
    if(d[u] != INT_MAX && d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        p[v] = u;
    }
}


void printPath(int V, int u, int p[])
{
    for(int i=0; i<V; i++)
    {
        u = p[u];
    }

    cout<<u<<" ";
    for(int i = p[u]; i != u; i = p[i])
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

void belmanFord(int V, vector<int> adj[], vector<int> W[], int s)
{
    int d[V];
    int p[V];

    initialize(V, d, INT_MAX);
    initialize(V, p, -1);
    d[s] = 0;

    for(int i=0; i<V-1; i++)
    {
        // relax all the edges
        for(int u=0; u<V; u++)
        {
            // for each vertice u go through the neighbours as u->v is an edge
            for(int j=0; j<adj[u].size(); j++)
            {
                int v = adj[u][j];

                relax(u, v, W[u][j], d, p);
            }
        }
    }

    int c = V+1;
    for(int u=0; u<V; u++)
    {
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(d[v] > d[u] + W[u][i])
            {
                c = v;
            }
        }
    }

    printPath(V, c, p);
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

    belmanFord(V, adj, W, 0);

    return 0;
}