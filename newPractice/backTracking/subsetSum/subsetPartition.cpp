#include <iostream>
#include <string>

using namespace std;

void subsetSum(int n, int arr[], int k, int i, int sum, string str, int total)
{
    if((total - sum) == sum)
    {
        cout<<str<<endl;
        return ;
    }
    else if(i>n || (sum>(total - sum)))
    {
        return ;
    }

    subsetSum(n, arr, k, i+1, sum, str, total);
    subsetSum(n, arr, k, i+1, sum+arr[i], (str + (str==""?"":" ") + to_string(arr[i])), total);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int total = 0;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        total = total + arr[i];
    }

    int k;
    cin>>k;
    subsetSum(n, arr, k, 0, 0, "", total);

    return 0;
}