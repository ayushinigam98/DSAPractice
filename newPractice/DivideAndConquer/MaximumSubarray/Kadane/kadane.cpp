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

int kadane(int n, int arr[])
{
    int currentMax = arr[0];
    int globalMax = arr[0];

    for(int i=1; i<n; i++)
    {
        currentMax = max(currentMax + arr[i], arr[i]);
        globalMax = max(globalMax, currentMax);
    }

    return globalMax;
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

    cout<<kadane(n, arr);

    return 0;
}