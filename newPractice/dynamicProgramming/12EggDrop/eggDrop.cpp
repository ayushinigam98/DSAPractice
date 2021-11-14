#include <iostream>

using namespace std;

int eggDrop(int n, int e)
{
    int drop[n+1][e+1];

    //base case
    for(int i=0; i<=e; i++)
    {
        drop[0][i] = 0;
        drop[1][i] = 1;
    }
    for(int i=0; i<=n; i++)
    {
        drop[i][0] = -1;
        drop[i][1] = i;
    }
    drop[0][0] = 0;
    //recursive case
    for(int floor=2; floor<=n; floor++)
    {
        for(int eggs=2; eggs<=e; eggs++)
        {
            drop[floor][eggs] = n+1;
            for(int i=1; i<=floor; i++)
            {
                drop[floor][eggs] = min(drop[floor][eggs], 1+max(drop[floor-i][e], drop[i-1][e-1]));
            }
        }
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=e; j++)
        {
            cout<<drop[i][j]<<" ";
        }
        cout<<endl;
    }

    return drop[n][e];
}

int main()
{
    int n;
    int e;

    cin>>n;
    cin>>e;

    eggDrop(n, e);

    return 0;
}