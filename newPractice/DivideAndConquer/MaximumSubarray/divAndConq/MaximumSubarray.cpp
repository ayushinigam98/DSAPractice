#include <iostream>
#include <climits>
#include <tuple>
#include <climits>
using namespace std;

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

tuple<int, int, int> maxCrossing(int low, int mid, int high, int arr[])
{
    int sum;
    int leftSum, leftIndex;
    int rightSum, rightIndex;

    sum = 0;
    leftIndex = -1;
    leftSum = INT_MIN;

    for(int i=mid; i>=low; i--)
    {
        sum = sum + arr[i];
        if(sum > leftSum)
        {
            leftSum = sum;
            leftIndex = i;
        }
    }

    sum = 0;
    rightIndex = -1;
    rightSum = INT_MIN;

    for(int i=mid+1; i<=high; i++)
    {
        sum = sum + arr[i];
        if(sum > rightSum)
        {
            rightSum = sum;
            rightIndex = i;
        }
    }
    cout<<low<<" "<<mid<<" "<<high<<"--"<<leftIndex<<" "<<rightIndex<<" "<<leftSum + rightSum<<endl;
    return make_tuple(leftIndex, rightIndex, leftSum + rightSum);
}

tuple<int, int, int> maxSubarray(int low, int high, int arr[])
{
    if(low == high)
    {
        return make_tuple(low, high, arr[low]);
    }
    else
    {   
        int mid = low + (high - low)/2;
        
        int leftLowIndex, leftHighIndex, rightLowIndex, rightHighIndex, crossLowIndex, crossHighIndex;
        int leftSum, rightSum, crossSum;

        tie(leftLowIndex, leftHighIndex, leftSum) = maxSubarray(low, mid, arr);
        tie(rightLowIndex, rightHighIndex, rightSum) = maxSubarray(mid+1, high, arr);
        tie(crossLowIndex, crossHighIndex, crossSum) = maxCrossing(low, mid, high, arr);

        if(crossSum >= leftSum && crossSum >= rightSum)
            return make_tuple(crossLowIndex, crossHighIndex, crossSum);
        else if(rightSum >= leftSum)
            return make_tuple(rightLowIndex, rightHighIndex, rightSum);
        else
            return make_tuple(leftLowIndex, leftHighIndex, leftSum);
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

    int low, high, sum;
    
    tie(low, high, sum) = maxSubarray(0, n-1, arr);
    
    cout<<low<<" ";
    cout<<high<<" ";
    cout<<sum<<" ";
    
    return 0;
}