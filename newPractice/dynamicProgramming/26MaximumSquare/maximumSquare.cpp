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
    int top[columns];
    int left;
    
    for(int i=0; i<columns; i++)
    {
        top[i] = grid[0][i];
    }

    int square[rows][columns];

    //base case
    for(int i=0; i<columns; i++)
    {
        square[0][i] = grid[0][i];
    }

    for(int i=0; i<rows; i++)
    {
        square[i][0] = grid[i][0];
    }

    //recursive
    int maxArea = 0;
    for(int i=1; i<rows; i++)
    {
        left = 0;

        for(int j=1; j<columns; j++)
        {
            if(grid[i][j] == 1)
            {
                square[i][j] = min(1 + min(left, top[j]), square[i-1][j-1]+1);
                maxArea = max(maxArea, square[i][j]);
                left++;
                top[j]++;
            }
            else
            {
                square[i][j] = 0;
                left = 0;
                top[j] = 0;
            }
        }
    }

    cout<<endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            cout<<square[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
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