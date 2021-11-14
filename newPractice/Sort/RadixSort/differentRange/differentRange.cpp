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

int lastDigit(int num, int n)
{
    return num%n;
}

void count(int n, int arr[], int d[])
{
    int C[n];
    int Barr[n];
    int Bd[n];

    for(int i=0; i<n; i++)
    {
        C[i] = 0;
    }
    
    for(int i=0; i<n; i++)
    {
        C[lastDigit(d[i], n)]++;
    }

    for(int i=1; i<n; i++)
    {
        C[i] = C[i] + C[i-1];
    }

    for(int i=n-1; i>=0; i--)
    {
        int digit = lastDigit(d[i], n);
        
        Barr[C[digit] - 1] = arr[i];
        Bd[C[digit] - 1] = d[i];
        
        C[digit]--;
    }

    for(int i=0; i<n; i++)
    {
        arr[i] = Barr[i];
        d[i] = Bd[i];
    }
}

void radix(int n, int arr[], int digits)
{
    int d[n];

    for(int i=0; i<n; i++)
        d[i] = arr[i];
    
    for(int i=0; i<digits; i++)
    {
        count(n, arr, d);

        for(int i=0; i<n; i++)
            d[i] = (d[i] - lastDigit(d[i], n))/n;
    }

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

// n^3 - 1
int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int digits;
    cin>>digits;

    radix(n, arr, digits);

}