#include <iostream>

using namespace std;

int rodCutting(int lenght, int p[])
{
    int cost[lenght+1];

    //base case
    cost[0] = 0;

    //recursive case
    for(int l=1; l<=lenght; l++)
    {
        cost[l] = 0;
        for(int cut=1; cut<=l; cut++)
        {
            if(p[cut-1] + cost[l-cut] > cost[l])
            {
                cost[l] = p[cut-1] + cost[l-cut];
            }
        }
    }

    return cost[lenght];
}

int main()
{
    int l;
    cin>>l;
    int p[l];
    
    for(int i=0; i<l; i++)
    {
        cin>>p[i];
    }

    cout<<rodCutting(l, p);
    return 0;
}