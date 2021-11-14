#include <iostream>

using namespace std;

void initialize(int n, int arr[], int x)
{
    for(int i=0; i<n; i++)
        arr[i] = x;
}

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void countingSort(int n, int arr[], int k)
{
    int B[n];
    int C[k+1];

    initialize(k+1, C, 0);

    // total number of elements of value i
    for(int i=0; i<n; i++)
    {
        C[arr[i]]++;
    }

    //total elements smaller than or equal to i
    for(int i=1; i<=k; i++)
    {
        C[i] = C[i-1] + C[i];
    }

    for(int i=n-1; i>=0; i--)
    {
        B[C[arr[i]]-1] = arr[i];
        C[arr[i]]--;
    }

    for(int i=0; i<n; i++)
    {
        arr[i] = B[i];
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

    int k;
    cin>>k;

    countingSort(n, arr, k);
    print(n, arr);

    return 0;
}