#include <iostream>
#include <vector>

using namespace std;

void initializeZero(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
}

void largestSquare(int rows, int columns, vector<vector<int>> &grid)
{
    int maxSquare[rows][columns];

    //base case
    for(int i=0; i<columns; i++)
    {
        maxSquare[0][i] = grid[0][i];
    }
    for(int i=0; i<rows; i++)
    {
        maxSquare[i][0] = grid[i][0];
    }

    //recursive case
    int maxArea = 0;
    for(int i=1; i<rows; i++)
    {
        for(int j=1; j<columns; j++)
        {
            if(grid[i][j] == 1)
            {
                maxSquare[i][j] = 1 + min(min(maxSquare[i-1][j], maxSquare[i][j-1]), maxSquare[i-1][j-1]);
                maxArea = max(maxArea, maxSquare[i][j]);
            }
            else
            {
                maxSquare[i][j] = 0;
            }
        }
    }

    cout<<"maximum: "<<maxArea;

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

    largestSquare(rows, columns, grid);

    return 0;
}