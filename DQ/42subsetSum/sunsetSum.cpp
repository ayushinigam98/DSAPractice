#include <iostream>

using namespace std;

void printSubset(int n, int arr[], int k)
{
    int possible[n+1][k+1];

    //base cases 
    for(int i=1; i<=k; i++)
    {
        possible[0][i] = 0;
    }

    for(int i=0; i<=n; i++)
    {
        possible[i][0] = 1;
    }

    //other cases

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            possible[i][j] = 0;
            
            if(possible[i-1][j])
            {
                possible[i][j] = 1;
            }
            
            if(j>=arr[i-1] && possible[i-1][j-arr[i-1]])
            {
                possible[i][j] = 2;
            }
        }
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            cout<<possible[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=n, j=k;i>=0;i--)
    {
        if(possible[i][j] == 2 && j>=arr[i-1])
        {  
            cout<<arr[i-1]<<" ";
            j = j - arr[i-1];
        }
       
    }
}

int main()
{
    int n, k;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cin>>k;

    printSubset(n, arr, k);
    //print out all the sibsets of the 
    return 0;
}