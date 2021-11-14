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


void DFS(int u, int color[], int d[], int f[], int parent[], vector<int> adj[], int &time)
{
    //set the disovery time
    time++;
    d[u] = time;

    //color the node discovered
    color[u] = 1;

    //explore the neighbours
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(color[v] == 0)
        {
            cout<<u<<"->"<<v<<" : Tree Edge"<<endl;
            parent[v] = u;
            DFS(v, color, d, f, parent, adj, time);
        }
        else if(color[v] == 1)
        {
            cout<<u<<"->"<<v<<" : Back Edge"<<endl;
        }
        else if(d[u]<f[v])
        {
            cout<<u<<"->"<<v<<" : Forward Edge"<<endl;
        }
        else
        {
            cout<<u<<"->"<<v<<" : Cross Edge"<<endl;
        }
    }   

    // color the node finished
    color[u] = 2;
    
    // fix the finishing time
    time++;
    f[u] = time;
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
    int color[V];
    int d[V];
    int f[V];
    int parent[V];

    // initialization
    // color all the vertices white
    initialize(V, color, 0);
    // set the parent to nil
    initialize(V, parent, -1);

    int time = 0;

    for(int i=0; i<V; i++)
    {
        if(color[i] == 0)
        {
            DFS(i, color, d, f, parent, adj, time);
        }
    }

    print(V, parent);
    print(V, d);
    print(V, f);

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