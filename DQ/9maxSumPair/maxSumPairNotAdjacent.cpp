#include <iostream>

using namespace std;

int maximum(int n, int arr[])
{
    int max = 0;

    for(int i=0; i<n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int getFirst(int x, int N)
{
    return x%N;
}

int getSecond(int x, int N)
{
    return x/N;
}

//n>2 otherwise no possible answer
int maxSumPair(int n, int arr[])
{
    int N = maximum(n, arr);
    N = N+10;

    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] > max)
        {    
            max = arr[i];
        }

        arr[i] = arr[i] + N*max;
    }

    int max1 = getFirst(arr[n-2], N)>getFirst(arr[n-1], N)?getFirst(arr[n-2], N):getFirst(arr[n-1], N), max2 = getFirst(arr[n-1], N);
    int globalMaxSum = 0;
    int localMaxSum = 0;

    for(int i=n-3; i>=0; i--)
    { 
        localMaxSum = getFirst(arr[i], N) + max2;
        if((i-2)>=0)
        {
            localMaxSum = localMaxSum>(getFirst(arr[i], N) + getSecond(arr[i-2], N))?
                    localMaxSum:(getFirst(arr[i], N) + getSecond(arr[i-2], N));
        }

        globalMaxSum = (localMaxSum > globalMaxSum)?localMaxSum:globalMaxSum;

        max2 = max1;
        if(getFirst(arr[i], N) > max1)
        {
            max1 = getFirst(arr[i], N);
        }    
    }

    return globalMaxSum;
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
    //initialized

    cout<<maxSumPair(n, arr);
    
    return 0;
}