#include <iostream>
#include <algorithm>

using namespace std;

int abs(int x)
{
    return x>=0?x:(-x);
}

int time(int n, int mice[], int holes[])
{
    sort(mice, mice+n);
    sort(holes, holes+n);

    int maximum = 0;

    for(int i=0; i<n; i++)
    {
        if(abs(mice[i] - holes[i]) > maximum)
            maximum = abs(mice[i] - holes[i]);
    }

    return maximum;
}

void initializeArr(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
}

int main()
{
    int n;
    cin>>n;
    int mice[n];
    int holes[n];
    
    initializeArr(n, mice);
    initializeArr(n, holes);

    cout<<time(n, mice, holes);

    return 0;
}