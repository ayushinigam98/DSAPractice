#include <iostream>

using namespace std;

int minJumps(int n, int jumps[])
{
    int jumpsToEnd[n];

    //base case
    jumpsToEnd[n-1] = 0;

    for(int i=n-2; i>=0; i--)
    {
        int j = jumps[i];

        jumpsToEnd[i] = n+1;

        while(j>0)
        {
            if(i+j<n && jumpsToEnd[i+j]<n)
            {
                jumpsToEnd[i] = min(jumpsToEnd[i], 1 + jumpsToEnd[i+j]);
            }
            j--;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(jumpsToEnd[i] == n+1)
            jumpsToEnd[i] = -1;
        cout<<jumpsToEnd[i]<<" ";
    }

    return jumpsToEnd[n-1];
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

    minJumps(n, arr);

    return 0;
}