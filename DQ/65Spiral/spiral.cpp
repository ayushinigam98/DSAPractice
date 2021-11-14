#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void print()
{

}

void spiral(vector<vector<int>> arr, int rows, int columns)
{

}

int main()
{
    int rows, columns;
    cin>>rows;
    cin>>columns;
    vector<vector<int>> arr(columns);

    for(int i=0; i<rows; i++)
    {
        arr[i] = vector<int>(columns);
        for(int j=0; j<columns; j++)
        {
            cin>>arr[i][j];
        }
    }

    spiral(arr, rows, columns);

    return 0;
}