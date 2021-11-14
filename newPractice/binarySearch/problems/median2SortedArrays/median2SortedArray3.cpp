#include <iostream>
#include <climits>
using namespace std;

////wrong!!!

double median(int n1, int arr1[], int n2, int arr2[])
{
    int low = -1;
    int high = n1;
    int p1, p2;

    while(low <= high)
    {
        p1 = low + (high - low)/2;
        p2 = (n1 + n2)/2 - (p1+1) - 1;

        int l1 = p1>=0?arr1[p1]:INT_MIN;
        int l2 = p2>=0?arr2[p2]:INT_MIN;
        int r1 = p1+1<n1?arr1[p1+1]:INT_MAX;
        int r2 = p2+1<n2?arr2[p2+1]:INT_MAX;

        if(l1 <= r2 && l2 <= r1)
        {
            if((n1+n2)%2 == 0)
                return (max(l1,l2) + min(r1, r2))/2;
            else
                return min(r1, r2);
        }
        else if(l1 <= r2)
        {
            low = p1 + 1;
        }
        else
        {
            high = p1 - 1; 
        }
     
    }

    return 0;
    

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