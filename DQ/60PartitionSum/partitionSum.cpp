#include <iostream>

using namespace std;

bool partition(int n, int arr[])
{
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum = sum + arr[i];
    }

    if(sum%2 == 1)
        return false;
    
    sum = sum/2;

    int sumPossible[n+1][sum+1];

    //base case
    for(int i=0; i<=sum; i++)
    {
        sumPossible[0][i] = 0;
    }

    for(int i=0; i<=n; i++)
    {
        sumPossible[i][0] = 1;
    }

    // recursive case
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            sumPossible[i][j] = sumPossible[i-1][j];

            if(!sumPossible[i][j] && j>=arr[i-1])
            {
                sumPossible[i][j] = sumPossible[i-1][j-arr[i-1]];
            }
        }
    }

    return sumPossible[n][sum];
}

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<partition(n, arr);
}