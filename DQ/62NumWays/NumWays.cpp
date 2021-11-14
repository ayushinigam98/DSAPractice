#include <iostream>
#include <vector>
using namespace std;

int numWays(int rows, int columns)
{
    vector<int> ways(columns);

    for(int i=0; i<columns; i++)
    {
        ways[i] = 1;
    }

    for(int i = rows-2; i>=0; i--)
    {
        for(int j=columns-1; j>=0; j--)
        {
            int w = 0;

            if(j+1 < columns)
            {
                w += ways[j+1];
            }

            w += ways[j];
            
            ways[j] = w;
        }
    }

    return ways[0];
}

int main()
{
    int rows, columns;

    cin>>rows;
    cin>>columns;

    cout<<numWays(rows, columns);

    return 0;
}