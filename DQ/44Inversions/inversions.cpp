#include <iostream>

using namespace std;

int merge(int arr[], int low, int mid, int high)
{
    int inversions = 0;

    int n1 = mid - low + 1;
    int n2 = high - mid;
    
    int arr1[n1];
    int arr2[n2];

    for(int i=low; i<=mid; i++)
    {
        arr1[i-low] = arr[i]; 
    }
    for(int i=mid+1; i<=high; i++)
    {
        arr2[i-mid-1] = arr[i];
    }

    int i1 = 0, i2 = 0, i;

    for(i=low; i<=high && i1<n1 && i2<n2; i++)
    {
        if(arr1[i1] <= arr2[i2])
        {
            arr[i] = arr1[i1];
            i1++;
        }
        else
        {
            arr[i] = arr2[i2];
            i2++;
            inversions = inversions + n1 - i1 + 1;
        }
    }

    while(i1<n1)
    {
        arr[i++] = arr1[i1++];
    }

    while(i2<n2)
    {
        arr[i++] = arr2[i2++];
    }

    //cout<<inversions<<" ";

    return inversions;
}

int mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = low + (high - low)/2;

        return (mergeSort(arr, low, mid) + mergeSort(arr, mid+1, high) + merge(arr, low, mid, high));
    }
    else
    {
        return 0;
    }
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

    cout<<"inversions: "<<mergeSort(arr, 0, n-1)<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}