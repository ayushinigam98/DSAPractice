#include <iostream>

using namespace std;

void staricaseWays(int n)
{
    n++;
    int numWays[n];

    //base case
    numWays[n-1] = 1;

    //recursive case
    for(int i=n-2; i>=0; i--)
    {
        numWays[i] = 0;

        if(i+1 < n)
        {
            numWays[i] += numWays[i+1];
        }

        if(i+2 < n)
        {
            numWays[i] += numWays[i+2];
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<numWays[i]<<" ";
    }

    cout<<"\n"<<numWays[0];
}

int main()
{
    int n;
    cin>>n;

    staricaseWays(n);

    return 0;
}