#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool babyface(int V, vector<int> adj[])
{
    int s = 0;

    //color and teams
    int color[V];
    int team[V];

    for(int i=0; i<V; i++)
    {
        color[i] = 0;
        team[i] = -1;
    }

    //make a queue
    queue<int> q;

    //add the source to the queue
    color[s] = 1;
    team[s] = 0;
    q.push(s);

    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];

            if(color[v] == 0)
            {
                color[v] = 1;
                team[v] = team[u] == 0?1:0;
                q.push(v);   
            }
            else if(team[u] == team[v])
            {
                return false;
            }
        }
    }

    cout<<babyface(V, adj);

    return true;
    
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
        int u, v;
        cin>>u;
        cin>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}