#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int directions = 4;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

void fill(int rows, int columns, vector<vector<int>> &arr, int x)
{
    for(int i=0; i<rows; i++)
    {
        arr[i] = vector<int>(columns);
        for(int j=0; j<columns; j++)
        {
            arr[i][j] = x;
        }
    }
}

void fill(int rows, int columns, vector<vector<pair<int, int>>> &arr)
{
    for(int i=0; i<rows; i++)
    {
        arr[i] = vector<pair<int, int>>(columns);
        for(int j=0; j<columns; j++)
        {
            arr[i][j] = make_pair(-1, -1);
        }
    }
}

bool inBoundary(int i, int j, int rows, int columns)
{
    return (i>=0 && j>=0 && i<rows && j<columns);
}



void printPath(int i, int j, vector<vector<pair<int, int>>> &parent)
{
    if(i == -1 && j == -1)
    {
        return ;
    }
    
    printPath(parent[i][j].first, parent[i][j].second, parent);
    cout<<"("<<i<<","<<j<<")"<<" ";
}

void findShortestPath(int rows, int columns, vector<vector<int>> &grid, int starti, int startj, int endi, int endj)
{
    vector<vector<int>> color(rows);
    vector<vector<int>> d(rows);
    vector<vector<pair<int, int>>> parent(rows);

    fill(rows, columns, color, 0);
    fill(rows, columns, d, -1);
    fill(rows, columns, parent);

    queue<pair<int, int>> q;

    //source vector insertion
    q.push(make_pair(starti, startj));
    color[starti][startj] = 1;
    d[starti][startj] = 0;

    while(!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        
        for(int dir=0; dir<directions; dir++)
        {
            int nexti = u.first + di[dir];
            int nextj = u.second + dj[dir];
        
            if(inBoundary(nexti, nextj, rows, columns) && grid[nexti][nextj] == 0 && color[nexti][nextj] == 0)
            {
                color[nexti][nextj] = 1;
                d[nexti][nextj] = d[u.first][u.second] + 1;
                parent[nexti][nextj] = u;
                q.push(make_pair(nexti, nextj));
                if(nexti == endi && nextj == endj)
                {   
                    printPath(endi, endj, parent);
                } 
            }
        } 
        
        color[u.first][u.second] = 2; 
    }
}

int main()
{
    int rows, columns;

    cin>>rows;
    cin>>columns;

    vector<vector<int>> grid(rows);

    for(int i=0; i<rows; i++)
    {
        grid[i] = vector<int>(columns);
        for(int j=0; j<columns; j++)
        {
            cin>>grid[i][j];
        }
    }

    findShortestPath(rows, columns, grid, 0, 0, 3, 0);

    return 0;
}