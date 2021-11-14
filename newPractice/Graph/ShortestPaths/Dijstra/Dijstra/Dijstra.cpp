#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct Node
{
    int id;
    int d;
    int p;

    Node()
    {

    }

    Node(int identity, int dist, int parent)
    {
        id = identity;
        d = dist;
        p = parent;
    }
};

struct compareD
{
    bool operator()(Node* node1, Node* node2)
    {
        return (node1->d >= node2->d);
    }
};

void initialize(int n, int arr[], int x)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = x;
    }
}

void relax(Node* u, Node* v, int w)
{
    if(u->d != INT_MAX && v->d > u->d + w)
    {
        v->d = u->d + w;
        v->p = u->id;
    }
}

void dijstra(int V, vector<int> adj[], vector<int> W[], int s)
{
    Node* nodes[V];

    for(int i=0; i<V; i++)
    {
        nodes[i] = new Node(i, INT_MAX, -1);
    }
    nodes[s]->d = 0;

    priority_queue<Node*, vector<Node*>, compareD> q;

    for(int i=0; i<V; i++)
        q.push(nodes[i]);
    
    while(!q.empty())
    {
        Node* u = q.top();
        q.pop();

        for(int i=0; i<adj[u->id].size(); i++)
        {
            Node* v = nodes[adj[u->id][i]];
            relax(u, v, W[u->id][i]);
        }
    }

    for(int i=0; i<V; i++)
    {
        cout<<nodes[i]->d<<" ";
    }
}

int main()
{
    int V;
    cin>>V;

    int E;
    cin>>E;

    vector<int> adj[V];
    vector<int> W[V];

    for(int i=0; i<E; i++)
    {
        int u, v, w;

        cin>>u;
        cin>>v;
        cin>>w;

        adj[u].push_back(v);
        W[u].push_back(w);
    }

    dijstra(V, adj, W, 0);

    return 0;
}