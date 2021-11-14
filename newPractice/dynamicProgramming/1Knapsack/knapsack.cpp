#include <iostream>

using namespace std;

int knapSack(int W, int n, int weight[], int value[])
{
    int maxValue[n+1][W+1];
    
    //base case
    for(int i=0; i<=n; i++)
    {
        maxValue[i][0] = 0;
    }
    
    for(int w=0; w<=W; w++)
    {
        maxValue[0][w] = 0;
    }
    cout<<endl;

    //recursive case

    for(int i=1; i<=n; i++)
    {
        for(int w=1; w<=W; w++)
        {
            maxValue[i][w] = maxValue[i-1][w];
            if(w - weight[i-1] >= 0)
            {
                maxValue[i][w] = max(maxValue[i-1][w], value[i-1] + maxValue[i-1][w-weight[i-1]]);
            }
        }
    }

    for(int i=0; i<=n; i++)
    {
        for(int w=0; w<=W; w++)
        {
            cout<<maxValue[i][w]<<" ";
        }
        cout<<endl;
    }

    return maxValue[n][W];

}

int main()
{
    int n;
    cin>>n;
    int weight[n];
    int value[n];
    int W;

    for(int i=0; i<n; i++)
    {
        cin>>weight[i];
    }

    for(int i=0; i<n; i++)
    {
        cin>>value[i];
    }

    cin>>W;

    cout<<knapSack(W, n, weight, value);

    return 0;
}