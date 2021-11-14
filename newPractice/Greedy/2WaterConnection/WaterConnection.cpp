#include <iostream>
#include <vector>
using namespace std;

void initialize(int n, int arr[], int x)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = x;
    }
}

void DFS(int s, int u, int adj[], int diameter[], int minDiameter)
{
    int v = adj[u];

    if(v != -1)
    {
        DFS(s, v, adj, diameter, min(minDiameter, diameter[u]));
    }
    else
    {
        cout<<s+1<<" "<<u+1<<" "<<minDiameter<<endl;
    }

}

void connections(int V, int adj[], int diameter[], int starterNode[])
{
    for(int i=0; i<V; i++)
    {
        if(starterNode[i] == 0)
        {
            DFS(i, i, adj, diameter, diameter[i]);
        }
    }
}

int main()
{
    int V;
    cin>>V;

    int p;
    cin>>p;

    int adj[V];
    initialize(V, adj, -1);
    
    int diameter[V];
    initialize(V, diameter, -1);

    int starterNode[V];
    initialize(V, starterNode, 0);

    int u, v, d;
    for(int i=0; i<p; i++)
    {
        cin>>u;
        cin>>v;
        cin>>d;

        adj[u-1] = v-1;
        diameter[u-1] = d;
        starterNode[v-1] = -1;
    }

    connections(V, adj, diameter, starterNode);

    return 0;
}