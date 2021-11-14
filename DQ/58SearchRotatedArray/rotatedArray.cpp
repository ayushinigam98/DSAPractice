#include <iostream>

using namespace std;

int rotatedSearch(int n, int arr[], int x)
{
    int low = 0;
    int high = n-1;
    int mid;

    while(low <= high)
    {
        mid = low + (high - low)/2;
       
        //check which half of the array it is in
        if(arr[mid] == x)
        {
            return mid;
        }
        else if(arr[low] <= arr[mid])
        {
            if(x < arr[mid] && x >= arr[low])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if(x > arr[mid] && x <= arr[high] )
            {
                low = mid  + 1;
            }
            else
            {
                high = mid - 1;
            }
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

    int x;
    cin>>x;

    cout<<rotatedSearch(n, arr, x);

    return 0;
}