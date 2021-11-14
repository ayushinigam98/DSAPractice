#include <iostream>

using namespace std;

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void insertionSort(int n, int arr[])
{
    for(int i=2; i<n; i++)
    {
        int key = arr[i];
        int j;
        for(j=i-1; j>=0 && arr[j]<key; j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
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

    insertionSort(n, arr);
    print(n, arr);

    return 0;
}