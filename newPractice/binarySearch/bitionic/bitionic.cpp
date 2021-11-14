#include <iostream>

using namespace std;

int findPeak(int n, int arr[])
{
    int low = 0;
    int high = n-1;
    int mid;

    while(low <= high)
    {
        mid = low + (high - low)/2;

        if(low == high)
        {
            return mid;
        }
        else if(mid>0 && mid<n-1)
        {
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            {
                return mid;
            }
            else if(arr[mid + 1] > arr[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else if(arr[low] > arr[high])
        {
            return low;
        }
        else
        {
            return high;
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

    cout<<findPeak(n, arr);

    return 0;
}