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

void DFS(int u, int color[], vector<int> adj[], stack<int> &s, int c, int component[])
{
    //color the node discovered
    color[u] = 1;
    component[u] = c;
    //explore the neighbours
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(color[v] == 0)
        {
            DFS(v, color, adj, s, c, component);
        }
    }   

    // color the node finished
    color[u] = 2;
    
    s.push(u);
}

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void DFS_visit(int V, vector<int> adj[])
{
    int c = 1;
    int component[V];

    stack<int> s;
    int color[V];

    // initialization
    // color all the vertices white
    initialize(V, color, 0);

    for(int i=0; i<V; i++)
    {
        if(color[i] == 0)
        {
            DFS(i, color, adj, s, c, component);
        }
    }

    initialize(V, color, 0);
    c = 1;
    //transpose
    vector<int> adjTrans[V];

    for(int u=0; u<V; u++)
    {
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];

            adjTrans[v].push_back(u);
        }
    }


    while(!s.empty())
    {
        int u = s.top();
        s.pop();

        if(color[u] == 0)
        {
            DFS(u, color, adjTrans, s, c, component);
            c++;
        }
    }
    cout<<endl;

    for(int i=0; i<V; i++)
    {
        cout<<component[i]<<" ";
    }

}

int main()
{
    int V, E;
    cin>>V;  
    cin>>E;

    vector<int> adj[V];  

    for(int i=0; i<E; i++)
    {
        int u, v;
        cin>>u;
        cin>>v;

        adj[u].push_back(v);
    }

    DFS_visit(V, adj);

    return 0;
}