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

int* countSort(int n, int arr[], int k)
{
    int* C = new int[k+1];

    for(int i=0; i<=k; i++)
    {
        C[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        C[arr[i]]++;
    }

    for(int i=1; i<=k; i++)
    {
        C[i] = C[i] + C[i-1];
    }

    return C;
}

void query(int n, int arr[], int k)
{
    int* C = countSort(n, arr, k);


    int a, b;
    while(true)
    {
        cout<<"enter range: ";
        cin>>a;
        cin>>b;

        if(a == 0)
        {
            cout<<C[b]<<endl;
        }
        else
        {
            cout<<(C[b] - C[a-1])<<endl;
        }

        cout<<"Done? 0 - yes or 1 - no: ";
        
        cin>>a;
        
        if(a == 0)
            break;
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

    int k;
    cin>>k;

    query(n, arr, k);
    print(n, arr);

    return 0;
}