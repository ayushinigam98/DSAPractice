#include <iostream>
#include <algorithm>
using namespace std;

bool isBoxWithin(int l1, int b1, int h1, int l2, int b2, int h2)
{
    if(l1 <= l2 && b1 <= b2 && h1 <= h2)
        return true;
    else
        return false;
}

void boxStacking(int n, int l[], int b[], int h[])
{
    int boxes[n];

    //base case
    boxes[0] = 1;

    //recursive case
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(isBoxWithin(l[j], b[j], h[j], l[i], b[i], h[i])
                || isBoxWithin(b[j], l[j], h[j], l[i], b[i], h[i])
                || isBoxWithin(h[j], b[j], l[j], l[i], b[i], h[i])
                || isBoxWithin(b[j], h[j], l[j], l[i], b[i], h[i])
                || isBoxWithin(h[j], l[j], b[j], l[i], b[i], h[i])
                || isBoxWithin(l[j], h[j], b[j], l[i], b[i], h[i]))
            {
                boxes[i] = max(boxes[i], boxes[j] + 1);
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<boxes[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;

    int l[n];
    int b[n];
    int h[n];

    for(int i=0; i<n; i++)
    {
        cin>>l[i];
        cin>>b[i];
        cin>>h[i];
    }

    boxStacking(n, l, b, h);

    return 0;
}
