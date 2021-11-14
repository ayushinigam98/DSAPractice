#include <iostream>
#include <deque>

using namespace std;

void setDeque(deque<pair<int, int>> &d, int x, int i)
{
    while(!d.empty() && d.back().second <= x)
    {
        d.pop_back();
    }

    d.push_back(make_pair(i, x));
}

void printMaxArray(int k, int n, int arr[])
{
    deque<pair<int, int>> d;


    d.push_back(make_pair(0, arr[0]));
    
    for(int i=1; i<n; i++)
    {
        if(d.front().first < i-2)
        {
            d.pop_front();
        }

        setDeque(d, arr[i], i);

        if(i+1 >= k)
        {
            cout<<d.front().second<<" ";
        }
    }
}


int main()
{
    int n, k;
    cin>>k;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    printMaxArray(k, n, arr);

    return 0;
}