#include <iostream>
#include <climits>
using namespace std;

int median(int n1, int n2, int arr1[], int arr2[])
{
    int low = 1;
    int high = n1;
    int mid, p1, p2;
    //mid is the guess of where the partition might be
    //indices 1 ... mid are in one partition and mid + 1 ... n1 in the other

    while(low <= high)
    {
        mid = low + (high - low)/2;
        p1 = mid;
        p2 = (n1 + n2)/2 - (mid);

        if(arr1[p1] <= arr2[p2+1] && arr2[p2] <= arr1[p1+1])
        {
            break;
        }
        else if(arr1[p1] > arr2[p2+1])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if((n1+n2) % 2 == 0)
    {
        return (max(arr1[p1], arr2[p2]) + min(arr1[p1+1], arr2[p2+1]))/2;
    }
    else
    {
        return (min(arr1[p1+1], arr2[p2+1]));
    }

}

int main()
{
    int n1, n2;
    
    //array 1
    cin>>n1;
    int arr1[n1+2];
    for(int i=1; i<=n1; i++)
        cin>>arr1[i];
    arr1[0] = INT_MIN;
    arr1[n1+1] = INT_MAX;

    //array 2
    cin>>n2;
    int arr2[n2+2];
    for(int i=1; i<=n2; i++)
        cin>>arr2[i];
    arr2[0] = INT_MIN;
    arr2[n1+1] = INT_MAX;
    
    if(n1 < n2)
        cout<<median(n1, n2, arr1, arr2);
    else
        cout<<median(n2, n1, arr2, arr1);

    return 0;
}