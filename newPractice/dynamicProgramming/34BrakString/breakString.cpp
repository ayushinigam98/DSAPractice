#include <iostream>
#include <climits>
using namespace std;

int breakString(int n, int k, int L[])
{
    int CutPoints[k+2];

    CutPoints[0] = 0;
    for(int i=1; i<=k; i++)
    {
         CutPoints[i] = L[i-1];
    }
    CutPoints[k+1] = n;

    // cost[i][j] = cost of cutting the string from after cutpoint i to cutpoint j
    
    // base case
    // cost[i][i+1] = 0; i both the cutpoints are already cut (after i and after i+1)
    int NcutPoints = k+2;
    int Cost[NcutPoints][NcutPoints];

    for(int i=0; i<NcutPoints; i++)
    {
        Cost[i][i] = 0;
    }

    for(int i=0; i<NcutPoints-1; i++)
    {
        Cost[i][i+1] = 0;
    }

    //recursive case

    for(int len = 3; len <= NcutPoints; len++)
    {
        for(int i=0; i<NcutPoints-len+1; i++)
        {
            int j = i + len - 1;
            
            Cost[i][j] = INT_MAX; 
            for(int cut=i+1; cut<j; cut++)
            {
                Cost[i][j] = min(Cost[i][j], Cost[i][cut] + Cost[cut][j] + CutPoints[j] - CutPoints[i]);
            }

        }
    }

    for(int i=0; i<NcutPoints; i++)
    {
        for(int j = i; j<NcutPoints; j++)
        {
            cout<<Cost[i][j]<<" ";
        }
        cout<<endl;
    }

    return Cost[0][NcutPoints-1];
}

int main()
{
    int n;
    cin>>n;

    int k;
    cin>>k;
    int L[k];

    for(int i=0; i<k; i++)
    {
        cin>>L[i];
    }

    cout<<breakString(n, k, L);
}