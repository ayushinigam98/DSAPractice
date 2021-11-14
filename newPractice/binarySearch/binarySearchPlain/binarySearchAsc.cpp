#include <iostream>

using namespace std;

int binarySearch(int n, int arr[], int key)
{
    int low = 0;
    int high = n-1;
    int mid;

    while(low <= high)
    {
        mid = low + (high - low)/2;

        if(key == arr[mid])
            return mid;
        else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int n, key;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cin>>key;
    //initialized the sorted array

    cout<<binarySearch(n, arr, key);

    return 0;
}