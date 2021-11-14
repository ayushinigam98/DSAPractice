#include <iostream>

using namespace std;

void permutations(int n, int arr[], int taken[], string perm)
{
    if(perm.length() >= n)
    {
        cout<<perm<<endl;
        return ;
    }

    for(int i=0; i<n; i++)
    {
        if(!taken[i])
        {
            taken[i] = 1;
            permutations(n, arr, taken, perm + (char)((int)'0' + arr[i]));
            taken[i] = 0;
        }
    }
    
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    int taken[n];

    for(int i=0; i<n; i++)
    {
        taken[i] = 0;
        cin>>arr[i];
    }

    string perm = "";

    permutations(n, arr, taken, perm);

    return 0;
}