#include <iostream>
#include <climits>

using namespace std;

void matrixChain(int n, int p[])
{
    int M[n][n];

    //base case

    for(int i=0; i<n; i++)
    {
        M[i][i] = 0;
    }

    //recursive case
    for(int len=2; len<=n; len++)
    {
        for(int i=0; i<n-len+1; i++)
        {
            int j = i + len - 1;

            M[i][j] = INT_MAX;
            for(int k=i; k<j; k++)
            {
                M[i][j] = min(M[i][j], (M[i][k] + M[k+1][j] + p[i]*p[k+1]*p[j+1]));
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
            cout<<0<<" ";
        for(int j=i; j<n; j++)
            cout<<M[i][j]<<" ";
        cout<<endl; 
    }

}

int main()
{
    int n;
    cin>>n;

    int p[n+1];
    for(int i=0; i<n+1; i++)
    {
        cin>>p[i];
    }

    matrixChain(n, p);

    return 0;
}