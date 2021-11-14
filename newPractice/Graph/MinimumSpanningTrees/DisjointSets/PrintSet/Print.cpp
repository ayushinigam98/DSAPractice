#include <iostream>

using namespace std;

void makeSet(int n, int parent[], int rank[], int next[])
{
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
        next[i] = i;
    }
}

int findSet(int x, int parent[])
{
    int root = x;
    while(root != parent[root])
    {
        root = parent[root];
    }

    int current = x;
    while(current != root)
    {
        int temp = parent[current];
        parent[current] = root;
        current = temp;
    }

    return root;
}

int fiondSet(int x, int parent[])
{
    if(x != parent[x])
        parent[x] = findSet(parent[x], parent);
    
    return parent[x];
}

void link(int x, int y, int parent[], int rank[], int next[])
{
    if(rank[x] > rank[y])
    {
        parent[y] = x;
    }
    else 
    {
        parent[x] = y;        
        
        if(rank[y] == rank[x])
            rank[y]++;
    }

    int temp = next[y];
    next[y] = next[x];
    next[x] = temp;

}

void unionSet(int x, int y, int parent[], int rank[], int next[])
{
    link(findSet(x, parent), findSet(y, parent), parent, rank, next);
}

void printSet(int x, int next[])
{
    int current = next[x];
    while(current != x)
    {
        cout<<current<<" ";
        current = next[current];
    }
    cout<<x<<endl;
}

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n = 5;
    int parent[n];
    int rank[n];
    int next[n];
    makeSet(n, parent, rank, next);
    unionSet(0, 1, parent, rank, next);
    unionSet(2, 3, parent, rank, next);
    //print(n, parent);
    unionSet(0, 4, parent, rank, next);
    //print(n, parent);
    printSet(4, next);
    printSet(3, next);
    return 0;
}