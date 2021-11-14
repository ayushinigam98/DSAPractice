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

void DFS_visit(int u, int color[], vector<int> adj[], vector<int> &cycleVertices)
{
    color[u] = 1;
    cycleVertices.push_back(u);
    //cout<<u<<" ";
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(color[v] == 0)
        {
            DFS_visit(v, color, adj, cycleVertices);
        }
        else if(color[v] == 1)
        {
            // print out the cycle
            cout<<"cycle: ";
            int j;
            for(j = cycleVertices.size() - 1; j>=0 && cycleVertices[j] != v; j--);
            for(; j<cycleVertices.size(); j++)
            {
                cout<<cycleVertices[j]<<" ";
            }
            cout<<endl;
        }
    }

    color[u] = 2;
    cycleVertices.pop_back();
}

void DFS(int V, vector<int> adj[])
{
    int color[V];
    initialize(V, color, 0);
    vector<int> cycleVertices;

    for(int u=0; u<V; u++)
    {
        if(color[u] == 0)
        {
            DFS_visit(u, color, adj, cycleVertices);
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

    DFS(V, adj);   

    return 0;
}