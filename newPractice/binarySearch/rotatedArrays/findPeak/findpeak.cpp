#include <iostream>

using namespace std;

int findPeak(int n, int arr[])
{
    int start = 0;
    int end = n-1;
    int mid, next, prev;

    while(start <= end)
    {
        mid = start + (end - start)/2;
        next = (mid + 1)%n;
        prev = (n + mid - 1)%n;

        if(arr[start] <= arr[end])
        {
            return start;
        }
        else if(arr[mid] <= arr[next] && arr[mid] <= arr[prev])
        {
            return mid;
        }
        else if(arr[mid] <= arr[end])
        {
            end = mid - 1;
        }
        else if(arr[start] <= arr[mid])
        {
            start = mid + 1;
        }
    }

    return -1;
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
    //initialized

    cout<<findPeak(n, arr);

    return 0;
}