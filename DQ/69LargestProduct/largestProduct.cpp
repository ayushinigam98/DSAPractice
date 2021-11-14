#include <iostream>
#include <vector>
using namespace std;

int maxExcluding(int n, int arr[])
{
    int maxIndex = 0;

    for(int i=1; i<n; i++)
    {
        if(arr[i] > arr[maxIndex])
            maxIndex = i;
    }    

    return maxIndex;
}

int minExcluding(int n, int arr[])
{
    int minIndex = 0;

    for(int i=1; i<n; i++)
    {
        if(arr[i] < arr[minIndex])
            minIndex = i;
    }    

    return minIndex;
}

void copyIt(int n, int arr1[], int arr2[])
{
    for(int i=0; i<n; i++)
    {
        arr1[i] = arr2[i];
    }
}

int largestProduct(int n, int arr[])
{
    int copy[n];
    copyIt(n, copy, arr);

    int totalMin = arr[minExcluding(n, arr)];
    int totalMax = arr[maxExcluding(n, arr)];
    
    int index, product1 = 1;
    for(int i=0; i<3; i++)
    {
        index = maxExcluding(n, copy);
        product1 = product1*copy[index];
        copy[index] = totalMin-1;
    }

    copyIt(n, copy, arr);
    
    int product2 = 1;
    for(int i=0; i<2; i++)
    {
        index = minExcluding(n, copy);
        product2 = product2*copy[index];
        copy[index] = totalMax+1;
    }
    product2 = product2*totalMax;

    return product1>product2?product1:product2;    
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

    cout<<largestProduct(n, arr);   

    return 0;
}