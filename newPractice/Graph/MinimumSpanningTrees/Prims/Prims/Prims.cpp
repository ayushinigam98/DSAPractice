#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct NodeCompare
{
    bool operator() (pair<int, int> n1, pair<int, int> n2)
    {
        return n1.second > n2.second;
    }
};

void prims(int V, vector<int> adj[], vector<int> W[])
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
                cout<<parent[u]<<"-"<<u<<endl;
           
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

    prims(V, adj, W);

    return 0;
}