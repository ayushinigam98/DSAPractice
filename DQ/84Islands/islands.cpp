#include <iostream>
#include <vector>
using namespace std;

int di[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dj[] = {1, -1, 0, 0, 1, -1, 1, -1};
int directions = 8;

bool isSafe(int i, int j, int rows, int columns)
{
    return (i>=0 && j>=0 && i<rows && j< columns);
}

void DFS(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &color, int rows, int columns)
{
    color[i][j] = 1;

    for(int d=0; d<directions; d++)
    {
        int nexti = i + di[d];
        int nextj = j + dj[d];

        if(isSafe(nexti, nextj, rows, columns) && grid[nexti][nextj] == 1 && color[nexti][nextj] == 0)
        {
            DFS(nexti, nextj, grid, color, rows, columns);
        }
    }
}

int islands(int rows, int columns, vector<vector<int>> &grid)
{
    int numIslands = 0;
    vector<vector<int>> color(rows);

    for(int i=0; i<rows; i++)
    {
        color[i] = vector<int>(columns);
        for(int j=0; j<columns; j++)
        {
            color[i][j] = 0;
        }
    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            if(color[i][j] == 0 && grid[i][j] == 1)
            {
                numIslands++;
                DFS(i, j, grid, color, rows, columns);
            }
        }
    }

    return numIslands;
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

    cout<<islands(rows, columns, grid);

    return 0;
}