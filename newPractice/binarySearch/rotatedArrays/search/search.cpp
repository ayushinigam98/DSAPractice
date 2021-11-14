#include <iostream>

using namespace std;

int search(int n, int arr[], int key)
{
    int start = 0;
    int end = n-1;
    int mid;

    while(start <= end)
    {
        mid = start + (end - start)/2;

        if(key == arr[mid])
        {
            return mid;
        }
        else if(arr[mid] <= arr[end])
        {
            if(key > arr[mid] && key <= arr[end])
                start = mid +1;
            else
                end = mid - 1;
        }
        else
        {
            if(key < arr[mid] && key >= arr[start])
                end = mid - 1;
            else
                start = mid + 1;
        }

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
    //initialized

    cout<<search(n, arr, key);

    return 0;
}