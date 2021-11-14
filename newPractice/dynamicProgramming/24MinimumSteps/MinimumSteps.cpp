#include <iostream>
#include <vector>
using namespace std;

int minimumSteps(int rows, int columns, vector<vector<int>> grid)
{
    vector<vector<int>> steps(rows);

    for(int i=0; i<rows; i++)
    {
        steps[i] = vector<int>(columns);
        for(int j=0; j<columns; j++)
        {
            steps[i][j] = 0;
        }
    }

    //base case
    steps[rows-1][columns-1] = grid[rows-1][columns-1];
    
    for(int i=columns-2; i>=0; i--)
    {
        steps[rows-1][i] = grid[rows-1][i] + steps[rows-1][i+1];
    }

    for(int i=rows-2; i>=0; i--)
    {
        steps[i][columns-1] = grid[i][columns-1] + steps[i+1][columns-1];
    }

    //recursive case

    for(int i=rows-2; i>=0; i--)
    {
        for(int j=columns-2; j>=0; j--)
        {
            steps[i][j] = grid[i][j] + min(steps[i+1][j], steps[i][j+1]);
        }
    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            cout<<steps[i][j]<<" ";
        }
        cout<<endl;
    }

    return steps[0][0];

}

int main()
{
    int rows, columns;
    cin>>rows;
    cin>>columns;
    vector<vector<int>>  grid(rows);

    for(int i=0; i<rows; i++)
    {
        grid[i] = vector<int>(columns);

        for(int j=0; j<columns; j++)
        {
            cin>>grid[i][j];
        }
    }

    minimumSteps(rows, columns, grid);

    return 0;
}