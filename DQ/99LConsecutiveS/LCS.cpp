#include <iostream>
#include <unordered_set>
using namespace std;

int LCS(int n, int arr[])
{
    unordered_set<int> set;
    int lenMax = 0;

    for(int i=0; i<n; i++)
    {
        set.insert(arr[i]);
    }

    for(int i=0; i<n; i++)
    {
        if(set.find(arr[i] - 1) == set.end())
        {
            //then arr[i] is the first element of a sequence
            int num = arr[i]+1;
            int len = 1;

            while(set.find(num) != set.end())
            {
                len++;
                num++;
            }

            if(lenMax < len)
            {
                lenMax = len;
            }
        }
    }

    return lenMax;
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

    cout<<LCS(n, arr);   

    return 0;
}