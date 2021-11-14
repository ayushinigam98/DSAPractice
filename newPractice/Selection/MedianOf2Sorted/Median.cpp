#include <iostream>
#include <climits>
using namespace std;

void takeInputArray(int n, int arr[])
{
    for(int i=0; i<n; i++)
        cin>>arr[i];
}

float median(int n1, int X1[], int n2, int X2[])
{
    if(n1 > n2)
        return median(n2, X2, n1, X1);

    int low = -1;
    int high = n1-1;
    int p1, p2;
    int np = n1 + (n2 - n1)/2;

    int leftp1, leftp2, rightp1, rightp2;

    while(low <= high)
    {
        p1 = low + (high - low)/2;
        p2 = np - (p1 + 1) -1;

        leftp1 = (p1 == -1)?INT_MIN:X1[p1];
        leftp2 = (p2 == -1)?INT_MIN:X2[p2];
        rightp1 = (p1 == (n1-1))?INT_MAX:X1[p1+1];
        rightp2 = (p2 == (n2-1))?INT_MAX:X2[p2+1];

        if(leftp1 <= rightp2 && leftp2 <= rightp2)
            break;
        else if(leftp1 <= rightp2)
            low = p1+1;
        else
            high = p1-1;    
    }

    if((n1+n2) % 2 == 1)
        return max(rightp1, rightp2);
    else
        return (float)(max(leftp1, leftp2) + min(rightp1, rightp2))/2;
}

int main()
{
    int n1, n2;
    
    cin>>n1;
    int X[n1];
    takeInputArray(n1, X);

    cin>>n2;
    int Y[n2];
    takeInputArray(n2, Y);

    cout<<median(n1, X, n2, Y);

    return 0;
}