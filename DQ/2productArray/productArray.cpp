#include <iostream>

using namespace std;

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void productArray(int n, int arr[])
{
    int prefix[n];
    int prod = 1;

    prefix[n-1] = 1;
    for(int i=n-1; i>0; i--)
    {
        prefix[i-1] = prefix[i]*arr[i];
    }
    
    for(int i=0; i<n; i++)
    {
        int temp = prod*prefix[i];
        prod = prod*arr[i];
        arr[i] = temp;
    }

    print(n, arr);
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
    //initialization done

    productArray(n, arr);

    return 0;
}