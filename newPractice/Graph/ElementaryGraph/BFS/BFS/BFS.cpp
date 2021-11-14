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

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void BFS(int V, vector<int> adj[], int s)
{
    // attributes distance, predecessor, color of the nodes
    int d[V];
    int parent[V];
    int color[V];

    initialize(V, d, -1);
    initialize(V, parent, -1);
    initialize(V, color, 0);

    // create queue
    queue<int> q;

    // add the source
    q.push(s);
    d[s] = 0;
    parent[s] = -1;
    color[s] = 1;

    int u;
    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];

            // if the neighbour v is undiscovered
            if(color[v] == 0)
            {
                // color it grey
                color[v] = 1;
                // predecessor is u
                parent[v] = u;
                // distance is
                d[v] = d[u]+1;

                //add it to the queue
                q.push(v);
            }
        }

        // since u is done being explored, color it black
        color[u] = 2;
    }

    print(V, d);
    print(V, parent);

}

int main()
{
    int V;
    cin>>V;

    vector<int> adj[V];

    int E;
    cin>>E;

    for(int i=0; i<E; i++)
    {
        int u,v;
        
        cin>>u;
        cin>>v;

        adj[u].push_back(v);
    }

    BFS(V, adj, 2);

    return 0;
}