#include <iostream>
#include <algorithm>

using namespace std;

void printPair(int n, int arr[], int k)
{
    sort(arr, arr + n);  

    int left = 0;
    int right = n-1;
    int sum;

    while(left < right)
    {
        sum = arr[left] + arr[right];

        if(sum == k)
        {
            cout<<arr[left]<<" "<<arr[right]<<endl;
            left++;
            right--;
        }
        else if(sum < k)
            left++;
        else
            right--;
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