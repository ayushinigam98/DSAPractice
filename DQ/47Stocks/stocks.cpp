#include <iostream>

using namespace std;

int kadane(int n, int arr[])
{
    int globalSum = 0;
    int localSum = 0;

    for(int i=0; i<n; i++)
    {
        localSum = max(arr[i], arr[i] + localSum);
        globalSum = max(localSum, globalSum);
    }

    return globalSum;
}

int maxProfit(int n, int prices[])
{
    int difference[n-1];

    for(int i=0; i<n-1; i++)
    {
        difference[i] = prices[i+1] - prices[i];
    }

    return kadane(n-1, difference);
}

int main()
{
    int n;
    cin>>n;

    int prices[n];

    for(int i=0; i<n; i++)
    {
        cin>>prices[i];
    }

    cout<<maxProfit(n, prices);

    return 0;
}