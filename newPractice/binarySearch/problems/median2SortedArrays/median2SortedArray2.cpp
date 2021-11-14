#include <iostream>
#include <climits>
using namespace std;

double median(int n1, int arr1[], int n2, int arr2[])
{
    int low = 0;
    int high = n1-1;
    int p1, p2;

    while(low <= high)
    {
        p1 = low + (high - low)/2;
        p2 = (n1 + n2)/2 - (p1+1) - 1;

        if(p1 < n1 - 1 && p2 < n2 - 1)
        {
            if(arr1[p1] <= arr2[p2+1] && arr2[p2] <= arr1[p1+1])
            {
                break;
            }
            else if(arr1[p1] > arr2[p2+1])
            {
                high = p1 - 1;
            }
            else
            {
                low = p1 + 1; 
            }
        }
        else if(p1 == n1-1)
        {
            if(arr1[p1] <= arr2[p2+1])
                break;
            else
                high = p1 - 1;
        }
        else
        {
            if(arr2[p2] <= arr1[p1+1])
                break;
            else
                low = p1 + 1;
        }
    }
    
    if(high == -1)
    {
        p1 = -1;
        p2 = (n1+n2)/2 - (p1+1) - 1;
    }

    if((n1+n2)%2 == 0)
    {
        return (double) (max(p1>=0?arr1[p1]:INT_MIN, p2>=0?arr2[p2]:INT_MIN) + 
                min((p1<n1-1)?arr1[p1+1]:INT_MAX, (p2<n2-1)?arr2[p2+1]:INT_MAX))/2;
    }   
    else
    {
        return (double) min((p1<n1-1)?arr1[p1+1]:INT_MAX, (p2<n2-1)?arr2[p2+1]:INT_MAX);
    }

}

int main()
{
    int n1, n2;
    
    cin>>n1;
    int arr1[n1];
    for(int i=0; i<n1; i++)
    {
        cin>>arr1[i];
    }

    cin>>n2;
    int arr2[n2];
    for(int i=0; i<n2; i++)
    {
        cin>>arr2[i];
    }

    if(n1>n2)
    {
        cout<<median(n2, arr2, n1, arr1);             
    }
    else
    {
        cout<<median(n1, arr1, n2, arr2);    
    }

    return 0;
}