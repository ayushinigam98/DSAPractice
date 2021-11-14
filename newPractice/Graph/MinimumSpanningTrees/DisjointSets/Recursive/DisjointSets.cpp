#include <iostream>

using namespace std;

void makeSet(int n, int parent[], int rank[])
{
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findSet(int x, int parent[])
{
    if(x != parent[x])
        parent[x] = findSet(parent[x], parent);
    
    return parent[x];
}

void link(int x, int y, int parent[], int rank[])
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

}

void unionSet(int x, int y, int parent[], int rank[])
{
    link(findSet(x, parent), findSet(y, parent), parent, rank);
}

int main()
{
    int n = 5;
    int parent[n];
    int rank[n];

    makeSet(n, parent, rank);

    return 0;
}