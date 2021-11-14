#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct compare
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

void initialize(int n, int arr[], int x)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = x;
    }
}

bool relax(int u, int v, int w, int d[], int p[])
{
    if(d[u] != INT_MAX && d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        p[v] = u;
        return true;
    }

    return false;
}



void Dijstra(int V, vector<int> adj[], vector<int> W[], int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;

    int d[V];
    initialize(V, d, INT_MAX);

    int p[V];
    initialize(V, p, -1);

    d[s] = 0;

    for(int i=0; i<V; i++)
    {
        q.push(make_pair(i, d[i]));
    }

    while(!q.empty())
    {
        auto [u, temp] = q.top();
        q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];

            if(relax(u, v, W[u][i], d, p))
            {
                q.push(make_pair(v, d[v]));
            }
        }
    }

    for(int i=0; i<V; i++)
    {
        cout<<d[i]<<" ";
    }

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

    Dijstra(V, adj, W, 0);

    return 0;
}