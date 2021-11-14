#include <iostream>
#include <unordered_set>

using namespace std;

void printPair(int n, int arr[], int k)
{
    unordered_set<int> s;

    for(int i=0; i<n; i++)
    {
        if(s.find(k-arr[i]) != s.end())
            cout<<arr[i]<<" "<<k - arr[i]<<endl;
        else
            s.insert(arr[i]);
    }

}

int main()
{
    //initialize the array and k value
    int n, k;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cin>>k;
    //done

    printPair(n, arr, k);

    return 0;
}