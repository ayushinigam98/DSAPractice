#include <iostream>
#include <climits>
#include <tuple>
#include <climits>
using namespace std;

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int maxSubarray(int n, int arr[])
{
    int sum;
    int globalSum = 0;

    for(int i=0; i<n; i++)
    {
        sum = 0;

        for(int j=i; j<n; j++)
        {
            sum += arr[j];

            globalSum = max(sum, globalSum);
        }
    }

    return globalSum;
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

    cout<<maxSubarray(n, arr);

    return 0;
}