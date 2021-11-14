#include <iostream>
#include <cmath>
using namespace std;

void randomize(int low, int high, int arr[])
{
    int randomNum = low + (high - low)*((float) rand()/RAND_MAX);

    int temp = arr[high];
    arr[high] = arr[randomNum];
    arr[randomNum] = temp;
}

int randomizedPartition(int low, int high, int arr[])
{
    randomize(low, high, arr);

    int i = low - 1;
    int x = arr[high];

    for(int j = low; j < high; j++)
    {
        if(arr[j] < x)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;           
        }
    }

    i++;
    int temp = arr[i];
    arr[i] = x;
    arr[high] = temp;

    return i;
}

int randomizedSelect(int low, int high, int arr[], int i)
{
    if(low == high)
        return arr[low];

    int q = randomizedPartition(low, high, arr);

    int k = q - low + 1;

    if(i == k)
        return arr[q];
    else if(i < k)
        return randomizedSelect(low, q-1, arr, i);
    else
        return randomizedSelect(q+1, high, arr, i-k);
}

void kClosest(int n, int arr[], int k)
{
    int median;

    if(n%2 == 0)
        median = randomizedSelect(0, n-1, arr, n/2);
    else 
        median = randomizedSelect(0, n-1, arr, (n+1)/2);
    
    int dist[n];

    for(int i=0; i<n; i++)
    {
        dist[i] = abs(arr[i] - median);
    }

    randomizedSelect(0, n-1, dist, k);

    for(int i=0; i<k; i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
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

    kClosest(n, arr, k);

    return 0;
}