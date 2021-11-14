#include <iostream>

using namespace std;

void optimalGame(int n, int pots[])
{
    int player1[n][n];
    int player2[n][n];

    //base case
    for(int i=0; i<n; i++)
    {
        player1[i][i] = pots[i];
        player2[i][i] = 0;
    }

    //recursive case
    for(int l=2; l<=n; l++)
    {
        for(int i=0; i<n-l+1; i++)
        {
            int j = i + l - 1;

            if(pots[i] + player2[i+1][j] >= pots[j] + player2[i][j-1])
            {    
                player1[i][j] = pots[i] + player2[i+1][j];
                player2[i][j] = player1[i+1][j];
            }
            else
            {
                player1[i][j] = pots[j] + player2[i][j-1];
                player2[i][j] = player1[i][j-1];
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<"("<<player1[i][j]<<","<<player2[i][j]<<")" ;
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;

    int pots[n];
    for(int i=0; i<n; i++)
    {
        cin>>pots[i];
    }

    optimalGame(n, pots);

    return 0;
}