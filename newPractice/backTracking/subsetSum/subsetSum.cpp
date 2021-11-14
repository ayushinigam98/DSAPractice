#include <iostream>
#include <string>

using namespace std;

void subsetSum(int n, int arr[], int k, int i, int sum, string str)
{
    if(sum == k)
    {
        cout<<str<<endl;
        return ;
    }
    else if(i>n || sum>k)
    {
        return ;
    }

    subsetSum(n, arr, k, i+1, sum, str);
    subsetSum(n, arr, k, i+1, sum+arr[i], (str + (str==""?"":" ") + to_string(arr[i])));
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
    subsetSum(n, arr, k, 0, 0, "");

    return 0;
}