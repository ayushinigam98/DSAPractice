#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int i, int j, int rows, int columns)
{
    return (i>=0 && i<rows && j>=0 && j<columns);
}

bool search(int rows, int columns, vector<vector<char>> &grid, int starti, int startj, int inci, int incj, string str)
{
    for(int i=starti, j=startj, index=0; index<str.length(); index++, i+=inci, j+=incj)
    {
        if(!isSafe(i, j, rows, columns) || str[index] != grid[i][j])
        {
            return false;
        }
    }

    return true;
}

pair<int, int> wordSearch(int rows, int columns, vector<vector<char>> &grid, string str)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            if(grid[i][j] == str[0])
            {
                if(search(rows, columns, grid, i, j, 0, 1, str) 
                    || search(rows, columns, grid, i, j, 0, -1, str)
                    || search(rows, columns, grid, i, j, 1, 0, str)
                    || search(rows, columns, grid, i, j, -1, 0, str))
                {
                    return make_pair(i, j);
                }
            }
        }
    }

    return make_pair(-1,-1);
}

int main()
{
    int rows, columns;
    cin>>rows;
    cin>>columns;
    
    vector<vector<char>> grid(rows);

    for(int i=0; i<rows; i++)
    {
        grid[i] = vector<char>(columns);
        for(int j=0; j<columns; j++)
        {
            cin>>grid[i][j];
        }
    }

    string str;
    cin>>str;

    pair<int, int> location = wordSearch(rows, columns, grid, str);
    cout<<"("<<location.first<<","<<location.second<<")";

    return 0;
}