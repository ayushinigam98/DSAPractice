#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int n, vector<int> adj[], int colors[], int c, int u)
{
    for(int v=0; v<n; v++)
    {
        if(adj[u][v] == 1 && colors[v] == c)
        {
            return false;
        }
    }

    return true;
}

bool graphColoringHelper(int n, vector<int> adj[], int colors[], int k, int u)
{
    if(u >= n)
    {
        return true;
    }
   
    for(int c=0; c<k; c++)
    {
        if(isSafe(n, adj, colors, c, u))
        {
            colors[u] = c;
            if(graphColoringHelper(n, adj, colors, k, u+1))
                return true;
            colors[u] = -1;
        }
    }
    return false;
    
}

bool graphColoring(int n, vector<int> adj[], int k)
{
    int colors[n];
    for(int i=0; i<n; i++)
        colors[i] = -1;

    bool possible = graphColoringHelper(n, adj, colors, k, 0);

    for(int i=0; i<n; i++)
        cout<<colors[i]<<" ";
    
    return possible;
}

int main()
{
    //initializa the adjacency matrix
    //number of nodes
    int n;
    cin>>n;
    //array of vectors
    vector<int> adj[n];

    for(int i=0; i<n; i++)
    {
        adj[i] = vector<int>(n);
        for(int j=0; j<n; j++)
        {
            cin>>adj[i][j];
        }
    }

    //number of colors
    int k;
    cin>>k;

    graphColoring(n, adj, k);

    return 0;
}