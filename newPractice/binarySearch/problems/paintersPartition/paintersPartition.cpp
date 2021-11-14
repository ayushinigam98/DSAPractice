#include <iostream>

using namespace std;

int sum(int n, int arr[])
{
    int sum = 0;

    for(int i=0; i<n; i++)
    {
        sum = sum + arr[i];
    }

    return sum;
}

int maximum(int n, int arr[])
{
    int max = 0;

    for(int i=0; i<n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

bool simulate(int n, int arr[], int maxtime, int k)
{
    int sum = 0;
    int painters = 1;

    for(int i=0; i<n; i++)
    {
        sum = sum + arr[i];
        
        if(arr[i] > maxtime)
        {
            return false;
        }
        else if(sum > maxtime)
        {
            sum = arr[i];
            painters++;
        }
    }

    return (painters <= k);
}

int minMaxTime(int n, int k, int arr[])
{
    //binary search on answer
    //then simulate

    int high = sum(n, arr);
    int low = maximum(n, arr);
    int mid;
    int maxtime = high;

    while(low <= high)
    {
        mid = low + (high - low)/2;

        if(simulate(n, arr, mid, k))
        {
            maxtime = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return maxtime;
}

int main()
{
    //number of sections of paintings
    int n;
    cin>>n;

    //stores number of paintings per section
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    //no. of painters
    int k;
    cin>>k;

    //we need to allocate consecutive sections of paintings to painters, so that the time for completion is minimum
    cout<<minMaxTime(n, k, arr);


    return 0;
}