#include <iostream>

using namespace std;

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void add(int n, int A[], int B[], int C[])
{
    int carryOver = 0;
    int sum = 0;

    for(int i=n-1; i>=0; i--)
    {
        sum = A[i] + B[i] + carryOver;

        carryOver = sum/2;
        C[i+1] = sum%2;
    }
    
    C[0] = carryOver;
}

int main()
{
    int n;
    cin>>n;

    int A[n];
    int B[n];
    int C[n+1];

    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    
    for(int i=0; i<n; i++)
    {
        cin>>B[i];
    }

    add(n, A, B, C);
    print(n+1, C);

    return 0;
}