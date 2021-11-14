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

void DFS(int u, vector<int> adj[], int color[], stack<int> &order)
{
    color[u] = 1;

    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(color[v] == 0)
        {
            DFS(v, adj, color, order);
        }
    }

    order.push(u);
    color[u] = 2;
}

void topologicalSort(int V, vector<int> adj[], stack<int> &order)
{
    int color[V];
    initialize(V, color, 0);

    //stack<int> order;

    for(int i=0; i<V; i++)
    {
        if(color[i] == 0)
            DFS(i, adj, color, order);
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

int simplePath(int V, vector<int> adj[], int u, int v)
{
    stack<int> order;

    topologicalSort(V, adj, order);

    vector<int> arr;

    while(!order.empty())
    {
        if(order.top() == u)
            break;
        order.pop();
    }
    while(order.top() != v)
    {
        arr.push_back(order.top());
        order.pop();
    }
    
    arr.push_back(v);

    //dynamic programming
    int n = arr.size();
    
    int lookup[V];
    initialize(V, lookup, -1);
    for(int i=0; i<n; i++)
    {
        lookup[arr[i]] = i;
    }

    int paths[n];

    //base case
    paths[n-1] = 1;

    for(int i=n-2; i>=0; i--)
    {
        //check the neighbours
        paths[i] = 0;

        for(int j=0; j<adj[arr[i]].size(); j++)
        {
            int v = adj[arr[i]][j];
            if( i <= lookup[v] && lookup[v] < n)
            {
                paths[i] += paths[lookup[v]];
            }
        }
    }

    return paths[0];
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

    //topologicalSort(V, adj);
    int u, v;
    cin>>u;
    cin>>v;
    cout<<simplePath(V, adj, u, v);
    return 0;
}