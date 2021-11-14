#include <iostream>

using namespace std;

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int horners(int n, int a[], int x)
{
    int y = 0;

    for(int i=n-1; i>=0; i--)
    {
        y = a[i] + y*x;
    }

    return y;
}

int main()
{
    int n;
    cin>>n;

    int a[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    int x;
    cin>>x;

    cout<<horners(n, a, x);

    return 0;
}