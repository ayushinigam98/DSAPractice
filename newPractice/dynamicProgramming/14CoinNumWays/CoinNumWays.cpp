#include <iostream>

using namespace std;

int coinNumWays(int n, int coins[], int k)
{
    int numWays[n+1][k+1];

    //base case
    for(int i=0; i<=k; i++)
    {
        numWays[0][i] = 0;
    }
    
    for(int i=0; i<=n; i++)
    {
        numWays[i][0] = 1;
    }

    //recursive case
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            numWays[i][j] = numWays[i-1][j];

            if(j>=coins[i-1])
            {
                numWays[i][j] = numWays[i][j] + numWays[i][j-coins[i-1]];
            }
        }
    }

    return numWays[n][k];
}

int main()
{
    int k;
    cin>>k;

    int n;
    cin>>n;

    int coins[n];
    for(int i=0; i<n; i++)
    {
        cin>>coins[i];
    }

    cout<<coinNumWays(n, coins, k);

    return 0;
}