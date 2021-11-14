#include <iostream>

using namespace std;

int sum(int n, int arr[])
{
    int s = 0;

    for(int i=0; i<n; i++)
    {
        s += arr[i];
    }

    return s;
}

int maximum(int n, int arr[])
{
    int el = 0;

    for(int i=0; i<n; i++)
    {
        el = max(el, arr[i]);
    }

    return el;
}

bool simulate(int n, int arr[], int time, int k)
{
    if(maximum(n, arr) > time)
        return false;

    int painters = 1;
    int sum = 0;

    for(int i=0; i<n; i++)
    {
        sum = sum + arr[i];

        if(sum > time)
        {
            sum = arr[i];
            painters++;
        }
    }

    return (painters <= k);
}

int binarySearch(int n, int arr[], int k)
{
    int high = sum(n, arr);
    int low = maximum(n, arr);
    int midTime;
    int minTime = -1;


    while(low <= high)
    {
        midTime = low + (high - low)/2;

        if(simulate(n, arr, midTime, k))
        {
            minTime = midTime;
            high = midTime - 1;
        }
        else
        {
            low = midTime + 1;
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
    //initialized the sorted array

    cout<<binarySearch(n, arr, k);

    return 0;
}