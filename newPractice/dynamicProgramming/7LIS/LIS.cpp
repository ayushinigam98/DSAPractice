#include <iostream>

using namespace std;

int LIS(int n, int arr[])
{
    int L[n];
    int S[n];

    //base case
    L[0] = 1;
    S[0] = -1;

    for(int i=1; i<n; i++)
    {
        L[i] = 1;
        S[i] = -1;
        
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j])
            {
                if(L[i] < (1+L[j]))
                {
                    L[i] = 1 + L[j];
                    S[i] = j;
                }
            }
        }
    }

    int maximum = 0;

    for(int i=0; i<n; i++)
    {
        if(L[i] > L[maximum])
            maximum = i;
    }

    int i = maximum;
    cout<<i<<"|";
    cout<<arr[i]<<" ";
    while(S[i] > 0)
    {
        cout<<arr[S[i]]<<" ";
        i = S[i];
    }
    cout<<endl;


    return maximum;
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

    cout<<LIS(n, arr);

    return 0;
}