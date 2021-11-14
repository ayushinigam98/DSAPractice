#include <iostream>
//non adjacent elements
using namespace std;

int MSS(int n, int arr[])
{
    int maxSum[n];

    //base case
    maxSum[0] = arr[0];
    int maximum = arr[0];
    for(int i=1; i<n; i++)
    {
        maxSum[i] = 0;

        for(int j=0; j<i-1; j++)
        {
            maxSum[i] = max(maxSum[i], maxSum[j] + arr[i]);
        }

        maximum = max(maximum, maxSum[i]);
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

    cout<<MSS(n, arr);

    return 0;
}