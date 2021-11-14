#include <iostream>

using namespace std;

int partition(int low, int high, int arr[])
{
    int i = low - 1;
    
    int x = arr[high];
    
    for(int j = low; j < high; j++)
    {
        if(arr[j] < x)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    i++;
    int temp = arr[i];
    arr[i] = x;
    arr[high] = temp;

    return i;
}

void quickSort(int low, int high, int arr[])
{
    if(low < high)
    {
        int q = partition(low, high, arr);

        quickSort(low, q-1, arr);
        quickSort(q+1, high, arr);
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

    quickSort(0, n-1, arr);

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}