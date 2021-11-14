#include <iostream>
#include <vector>
using namespace std;

int remove(int rows, int columns, vector<vector<char>> &grid)
{
    int numRemove = 0;

    for(int i=0; i<columns; i++)
    {
        char compare = 'a';
        for(int j=0; j<rows; j++)
        {
            if(compare > grid[j][i])
            {
                numRemove++;
                break;
            }
            compare = grid[j][i];
        }
    }

    return numRemove;
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

    cout<<remove(rows, columns, grid);

    return 0;
}