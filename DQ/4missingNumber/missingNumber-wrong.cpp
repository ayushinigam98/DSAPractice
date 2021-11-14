#include <iostream>

using namespace std;

int partition(int n, int arr[])
{
    int posn = 0;
    int right = n-1;
    int left = 0;

    while(left <= right)
    {
        if(arr[left] <= 0)
        {
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
            right--;
        }
        else
        {
            posn++;
            left++;
        }
    }

    return posn;
}

int betterPartition(int n, int arr[])
{
    int posn = 0;
    int i = -1;

    for(int j=0; j<n; j++)
    {
        if(arr[j] > 0)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            posn++;
        }
    }

    return posn;
}

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int lowestPositiveMissingNumber(int n, int arr[])
{
    int posn = partition(n, arr);

    for(int i=0; i<posn; i++)
    {
        if(arr[i] <= posn && arr[arr[i]-1] > 0)
        {
            arr[arr[i]-1] = -arr[arr[i]-1];
        }
    }

    for(int i=0; i<posn; i++)
    {
        if(arr[i] > 0)
        {
            return (i+1);
        }
    }

    return posn+1;
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

    cout<<lowestPositiveMissingNumber(n, arr)<<endl;

    return 0;
}