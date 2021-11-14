#include <iostream>

using namespace std;

void subset(int n, int set[], int k)
{
    int sumPossible[n+1][k+1];

    //base case
    for(int i=0; i<=k; i++)
    {
        sumPossible[0][i] = 0;
    }

    for(int i=0; i<=n; i++)
    {
        sumPossible[i][0] = 1;
    }

    //recursive case
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            sumPossible[i][j] = 0;

            if(j>=set[i-1] && sumPossible[i-1][j-set[i-1]])
            {
                sumPossible[i][j] = 2;
            }
            else if(sumPossible[i-1][j])
            {
                sumPossible[i][j] = 1;
            }
        } 
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            cout<<sumPossible[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=n, j=k; i>0 && j>0; i--)
    {
        if(sumPossible[i][j] == 2)
        {
            cout<<set[i-1]<<" ";
            j = j - set[i-1];
        }
    }


}

int main()
{
    int n;
    cin>>n;
    
    int set[n];
    for(int i=0; i<n; i++)
    {
        cin>>set[i];
    }

    int k;
    cin>>k;

    subset(n, set, k);   

    return 0;
}