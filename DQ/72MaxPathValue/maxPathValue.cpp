#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void initialize(int n, int arr[], int x)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = x;
    }
}

bool DFS(int u, int color[], vector<int> adj[], unordered_map<char, int> &map, vector<vector<int>> &pathValue, string str)
{
    color[u] = 1;

    if(adj[u].size() == 0)
    {
        pathValue[u][map.find(str[u])->second] = 1;
        return false;
    }

    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        
        if(color[v] == 0)
        {
            if(DFS(v, color, adj, map, pathValue, str))
                return true;

            for(int i=0; i<map.size(); i++)
            {
                pathValue[u][i] = max(pathValue[u][i], pathValue[v][i]);
            }
       }
       else if(color[v] == 1)
       {
           return true; 
       }
    }

    pathValue[u][map.find(str[u])->second]++; 

    return false;
}

void maxPathValue(int V, vector<int> adj[], unordered_map<char, int> &map, string str)
{
    int color[V];
    initialize(V, color, 0);
    
    int characters = map.size();
    vector<vector<int>> pathValue(V);

    //base case
    for(int i=0; i<V; i++)
    {
        pathValue[i] = vector<int>(characters);
        for(int j=0; j<characters; j++)
        {
            pathValue[i][j] = 0;
        }
    }

    for(int i=0; i<V; i++)
    {
        if(color[i] == 0)
        {
            if(DFS(i, color, adj, map, pathValue, str))
            {
                cout<<"infinity";
                return;
            }
        }
    }

    int maximum = 0;

    for(int i=0; i<V; i++)
    {
        for(int j=0; j<characters; j++)
        {
            maximum = max(maximum, pathValue[i][j]);
        }
    }

    cout<<maximum;
    
    return ;
}

int main()
{

    string str;
    cin>>str;

    int V = str.length();
    vector<int> adj[V];

    int E;
    cin>>E;

    for(int i=0; i<E; i++)
    {
        int u, v;
        cin>>u;
        cin>>v;

        adj[u].push_back(v);
    }

    unordered_map<char, int> map;
    int count = 0;

    for(int i=0; i<V; i++)
    {
        if(map.find(str[i]) == map.end())
        {
            map[str[i]] = count;
            count++;
        }
    }

    maxPathValue(V, adj, map, str);

    return 0;
}