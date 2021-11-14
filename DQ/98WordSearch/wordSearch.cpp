#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int directions = 4;
int inci[] = {0, 0, 1, -1};
int incj[] = {1, -1, 0, 0};

bool inBoundary(int i, int j, int row, int column)
{
    return (i>=0 && i<row && j>=0 && j<column);
}

bool recurse(int i, int j, vector<vector<char>> &grid, string word, int k, vector<vector<int>> &visited, int row, int column)
{
    if(k == word.length() - 1)
    {   
        return true;
    }

    for(int d=0; d < directions; d++)
    {
        int nexti = i + inci[d];
        int nextj = j + incj[d];

        if(inBoundary(nexti, nextj, row, column) && !visited[nexti][nextj] && word[k+1] == grid[nexti][nextj])
        {
            visited[nexti][nextj] = 1;
            if(recurse(nexti, nextj, grid, word, k+1, visited, row, column))
                return true;
            visited[nexti][nextj] = 0;
        }
    }
   

    return false;
}

bool exists(int row, int column, vector<vector<char>> &grid, string word)
{
    vector<vector<int>> visited(row);

    for(int i=0; i<row; i++)
    {
        visited[i] = vector<int>(column);
        for(int j=0; j<column; j++)
        {
            visited[i][j] = 0;
        }
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            if(word[0] == grid[i][j])
            {
                visited[i][j] = 1;
                if(recurse(i, j, grid, word, 0, visited, row, column))
                    return true;
                visited[i][j] = 0;
            }
        }
    }

    return false;
}

int main()
{
    int row, column;
    cin>>row;
    cin>>column;

    vector<vector<char>> grid(row);

    for(int i=0; i<row; i++)
    {
        grid[i] = vector<char>(column);
        for(int j=0; j<column; j++)
        {
            cin>>grid[i][j];
        }
    }

    string word;
    cin>>word;

    cout<<exists(row, column, grid, word);   

    return 0;
}