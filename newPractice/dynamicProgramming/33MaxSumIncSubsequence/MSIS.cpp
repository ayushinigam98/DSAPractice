#include <iostream>

using namespace std;

int maxSumIncSubsequence(int n, int arr[])
{
    int MSIS[n];

    //base case
    MSIS[0] = arr[0];
    int maximum = arr[0];

    for(int i=1; i<n; i++)
    {
        MSIS[i] = arr[i];
        for(int j=0; j<i; j++)
        {
            if(arr[j] <= arr[i])
            {
                MSIS[i] = max(MSIS[i], arr[i] + MSIS[j]);
            }
        }

        if(maximum < MSIS[i])
            maximum = MSIS[i];
    }

    return maximum;
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

    cout<<maxSumIncSubsequence(n, arr);

    return 0;
}