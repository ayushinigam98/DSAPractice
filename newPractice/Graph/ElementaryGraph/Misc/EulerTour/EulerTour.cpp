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

void computeInOutDegree(int V, int in[], int out[], vector<int> adj[])
{
    initialize(V, in, 0);
    initialize(V, out, 0);

    for(int u=0; u<V; u++)
    {
        out[u] += adj[u].size(); 
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            in[v]++;
        }
    }
}

int eulerianPathStart(int V, int in[], int out[])
{
    int start = 0;

    int numStart = 0, numEnd = 0;

    for(int i=0; i<V; i++)
    {
        if((in[i]+1) == out[i])
        {
            start = i;
            numStart++;
        }
        else if(in[i] == (out[i]+1))
        {
            numEnd++;
        }
        else if(in[i] != out[i])
        {
            return -1;
        }
    }

    if((numStart == 0 && numEnd == 0) || (numStart == 1 && numEnd == 1))
        return start;
    else
        return -1;
}

void DFS(int u, int out[], stack<int> &path, vector<int> adj[])
{

   int i = adj[u].size() - out[u];

   while(i < adj[u].size())
   {
       out[u]--;
       DFS(adj[u][i], out, path, adj);
       i = adj[u].size() - out[u];
   }

   path.push(u);
}

void findEulerianPath(int V, int out[], vector<int> adj[], int start)
{
    stack<int> path;
    DFS(start, out, path, adj);

    while(!path.empty())
    {
        cout<<path.top()<<" ";
        path.pop();
    }
}

void EulerianPath(int V, vector<int> adj[])
{
    int in[V];
    int out[V];

    computeInOutDegree(V, in, out, adj);

    int start = eulerianPathStart(V, in, out);
    
    if(start>=0)
    {
        findEulerianPath(V, out, adj, start);
    }
    else
    {
        cout<<"path does not exist";
    }
}

int main()
{
    int V;
    cin>>V;

    int E;
    cin>>E;

    vector<int> adj[E];

    for(int i=0; i<E; i++)
    {
        int u, v;
        cin>>u;
        cin>>v;

        adj[u].push_back(v);
    }

    EulerianPath(V, adj);

    return 0;
}