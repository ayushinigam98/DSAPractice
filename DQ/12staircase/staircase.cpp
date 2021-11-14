#include <iostream>

using namespace std;

int numWaysClimb(int k, int jumps[], int n)
{
    int numSteps[n+1];
    numSteps[n] = 1;

    for(int s=n-1; s>=0; s--)
    {
        numSteps[s] = 0;
        for(int j=0; j<k; j++)
        {
            if(s+jumps[j] <= n)
            {
                numSteps[s] += numSteps[s+jumps[j]]; 
            }
        }
    }

    return numSteps[0];
}

int main()
{

    int n;
    cin>>n;

    int k;
    cin>>k;

    int jumps[k];
    for(int i=0; i<k; i++)
    {
        cin>>jumps[i];
    }

    cout<<numWaysClimb(k, jumps, n)<<endl;

    return 0;
}