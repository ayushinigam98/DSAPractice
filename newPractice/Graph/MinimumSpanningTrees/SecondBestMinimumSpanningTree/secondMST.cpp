#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>
using namespace std;

struct NodeCompare
{
    bool operator() (pair<int, int> n1, pair<int, int> n2)
    {
        return n1.second > n2.second;
    }
};

void prims(int V, vector<int> adj[], vector<int> W[], vector<int> adjMST[], vector<int> WMST[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, NodeCompare> q;

    int key[V];
    int parent[V];
    bool selected[V];

    key[0] = 0;
    parent[0] = -1;
    selected[0] = false;
    q.push(make_pair(0, 0));

    for(int i=1; i<V; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        selected[i] = false;

        q.push(make_pair(i, INT_MAX));
    }

    while(!q.empty())
    {
        auto [u, k] = q.top();
        q.pop();

        if(!selected[u])
        {
            selected[u] = true;

            if(parent[u] != -1)
            {
                adjMST[u].push_back(parent[u]);
                adjMST[parent[u]].push_back(u);
                WMST[u].push_back(key[u]);
                WMST[parent[u]].push_back(key[u]);
            }
           
            for(int i=0; i<adj[u].size(); i++)
            {
                int v = adj[u][i];
                if(W[u][i] < key[v])
                {
                    key[v] = W[u][i];
                    parent[v] = u;
                    q.push(make_pair(v, key[v]));
                }
            }
        }
    }
}


void DFSAcyclic(int u, int x, vector<int> adj[], vector<int> W[], vector<vector<tuple<int, int, int>>> &maximum)
{
    int u1, u2, w;

    for(int i=0; i<adj[x].size(); i++)
    {
        int v = adj[x][i];

        tie(u1, u2, w) = maximum[u][v];
        if(v != u && w == -1)
        {
            if(x == u || W[x][i] > w)
                maximum[u][x] = make_tuple(x, v, x);
        }
    }
}

void secondMST(int V, vector<int> adj[], vector<int> W[])
{
    vector<int> adjMST[V];
    vector<int> WMST[V];

    prims(V, adj, W, adjMST, WMST);

    vector<vector<tuple<int, int, int>>> maximum(V);

    for(int i=0; i<V; i++)
    {
        maximum[i] = vector<tuple<int, int, int>>(V);
        for(int j=0; j<V; j++)
        {
            maximum[i][j] = make_tuple(-1, -1, -1);
        }
    }    
}

int main()
{
    int V, E;
    cin>>V;
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
        adj[v].push_back(u);
        W[u].push_back(w);
        W[v].push_back(w);
    }

    secondMST(V, adj, W);

    return 0;
}