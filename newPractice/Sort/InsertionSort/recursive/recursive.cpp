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
    if(n <= 1)
        return ;
    
    insertionSort(n-1, arr);
    
    int key = arr[n-1]; 
    int j;

    for(j = n-2; j>=0 && key < arr[j]; j--)
    {
        arr[j+1] = arr[j];
    }

    arr[j+1] = key;
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