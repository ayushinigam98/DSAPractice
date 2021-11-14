#include <iostream>

using namespace std;

int kadane(int n, int arr[])
{
    int globalSum = 0;
    int localSum = 0;

    for(int i=0; i<n; i++)
    {
        localSum = max(arr[i], localSum + arr[i]);

        if(localSum > globalSum)
            globalSum = localSum;
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

    cout<<kadane(n, arr);

    return 0;
}