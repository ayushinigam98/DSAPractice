#include <iostream>
#include <climits>
using namespace std;

int minimumCoins(int n, int coins[], int k)
{
    int minCoins[n+1][k+1];

    //base case
    for(int i=0; i<=n; i++)
    {
        minCoins[i][0] = 0;
    }

    for(int i=0; i<=k; i++)
    {
        minCoins[0][i] = k+1;
    }

    //recursive case
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            minCoins[i][j] = minCoins[i-1][j];

            if(j>=coins[i-1])
            {
                minCoins[i][j] = min(minCoins[i][j], (1+minCoins[i][j-coins[i-1]]));
            }
        }
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            cout<<minCoins[i][j]<<" ";
        }
        cout<<endl;
    }

    return minCoins[n][k]==(k+1)?-1:minCoins[n][k];
}

int main()
{
    int n;
    cin>>n;

    int coins[n];
    for(int i=0; i<n; i++)
    {
        cin>>coins[i];
    }

    int k;
    cin>>k;

    minimumCoins(n, coins, k);

    return 0;
}