#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;


void DFS(string u, unordered_map<string, int> &color, unordered_map<string, vector<string>> &adj, stack<string> &order)
{
    //color the vertice grey
    color.find(u)->second = 1;

    vector<string> adjU = adj.find(u)->second; 
    for (auto v : adjU)
    {
        if(color.find(v)->second == 0)
        {
            DFS(v, color, adj, order);
        }   
    }

    order.push(u);
    color.find(u)->second = 2;
}

void topologicalSort(int n, unordered_map<string, vector<string>> &adj)
{
    stack<string> order;
    
    //do depth first seach, and make a list of the nodes in the order of finishing time
    unordered_map<string, int> color;

    for(unordered_map<string, vector<string>>::iterator itr = adj.begin(); itr != adj.end(); itr++)
    {
        color[itr->first] = 0;
    } 

    
    for(unordered_map<string, vector<string>>::iterator itr = adj.begin(); itr != adj.end(); itr++)
    {
        if(color.find(itr->first)->second == 0)
        {
            DFS(itr->first, color, adj, order);
        }
    }

    while(!order.empty())
    {
        cout<<order.top()<<" ";
        order.pop();
    }
}

int main()
{
    int n;
    cin>>n;
    string courses[n];

    // get the list of courses
    for(int i=0; i<n; i++)
    {
        cin>>courses[i];
    }

    unordered_map<string, vector<string>> adj;
    
    // add empty lists to all the nodes vlaues
    for(int i=0; i<n; i++)
    {
        vector<string> temp;
        adj[courses[i]] = temp;
    }

    int E;
    cin>>E;
    //fill up the lists with adjacent neigbours
    for(int i=0; i<E; i++)
    {
        string course1, course2;
        cin>>course1;
        cin>>course2;

        if(adj.find(course1) != adj.end())
        {
            adj.find(course2)->second.push_back(course1);
            //cout<<adj.find(course1)->second[0];
        }
    }

    topologicalSort(n, adj);

    return 0;
}