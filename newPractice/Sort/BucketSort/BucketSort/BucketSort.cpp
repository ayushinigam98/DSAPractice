#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(int n, float arr[])
{
    vector<vector<float>> list(n);

    for(int i=0; i<n; i++)
    {
        list[((int)(arr[i]*n))].push_back(arr[i]);
    }

    for(int i=0; i<n; i++)
    {
        sort(list[i].begin(), list[i].end());
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<list[i].size(); j++)
        {
            cout<<list[i][j]<<" ";
        }
    }
}

int main()
{
    int n;
    cin>>n;

    float arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    bucketSort(n, arr);   

    return 0;
}