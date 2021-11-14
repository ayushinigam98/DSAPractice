#include <iostream>

using namespace std;

int findSucessor(int n, int arr[], int key)
{
    int sucessor = -1;
    int start = 0, end = n-1, mid;

    while(start <= end)
    {
        mid = start + (end - start)/2;

        if(key >= arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            sucessor = mid;
            end = mid -1;
        }
    }
    cout<<start<<" "<<end<<endl;   

    return sucessor;
}

int main()
{
    int n, key;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cin>>key;
    //initialized

    cout<<findSucessor(n, arr, key);

}