#include <iostream>

using namespace std;

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int search(int n, int arr[], int x)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == x)
            return i;
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

    cout<<search(n, arr, x);

    return 0;
}