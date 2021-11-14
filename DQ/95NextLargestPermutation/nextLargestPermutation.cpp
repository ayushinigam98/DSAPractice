#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

void nextLargestPermutations(int n, int arr[])
{
    int replace;
    int replaceIndex;

   for(int i=n-2; i>=0; i--)
   {
       replace = INT_MAX;
       replaceIndex = -1;

       for(int j=n-1; j>i; j--)
       {
           if(arr[j] > arr[i] && arr[j] < replace)
           {
               replace = arr[j];
               replaceIndex = j;
           }
       }

       if(replaceIndex != -1)
       {
           int temp = arr[i];
           arr[i] = arr[replaceIndex];
           arr[replaceIndex] = temp;
           return ;
       }
   }

    sort(arr, arr+n);
    
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

    nextLargestPermutations(n, arr);

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}