#include <iostream>
#include <climits>
using namespace std;

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void initialize(int start, int end, int arr[], int L[], int n)
{
    for(int i=start, k=0; i<=end; i++, k++)
    {
        L[k] = arr[i];
    }
    L[n] = INT_MAX;
}

void merge(int start, int mid, int end, int arr[])
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int L1[n1+1];
    int L2[n2+1];

    initialize(start, mid, arr, L1, n1);
    initialize(mid+1, end, arr, L2, n2);

    int i1 = 0, i2 = 0;

    for (int k = start; k <= end; k++)
    {
        if(L1[i1] < L2[i2])
        {
            arr[k] = L1[i1++];
        }
        else
        {
            arr[k] = L2[i2++];
        }
    }
     
    //print(end - start+1, arr);
}

void mergeSort(int start, int end, int arr[])
{
    if(start < end)
    {
        int mid = start + (end - start)/2;

        mergeSort(start, mid, arr);
        mergeSort(mid+1, end, arr);

        merge(start, mid, end, arr);
    }
}

bool sumExists(int n, int arr[], int sum)
{
    mergeSort(0, n-1, arr);

    int low = 0, high = n-1;

    while(low < high)
    {
        if(arr[low] + arr[high] == sum)
            return true;
        else if(arr[low] + arr[high] < sum)
            low++;
        else
            high--;
    }   

    return false;
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

    int sum;
    cin>>sum;

    cout<<sumExists(n, arr, sum);

    return 0;
}