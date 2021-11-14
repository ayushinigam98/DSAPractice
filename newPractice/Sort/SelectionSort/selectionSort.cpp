#include <iostream>

using namespace std;

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void selectionSort(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        int small = arr[i];
        int index = i;
        for(int j = i; j<n; j++)
        {
            if(small > arr[j])
            {
                small = arr[j];
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = small;
        arr[index] = temp;
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

    selectionSort(n, arr);
    print(n, arr);

    return 0;
}