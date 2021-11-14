// profit(i, k) = profit(i-1, k)
// profit(i, k) = profit(j, k-1) + cost[i] - cost[j]
//
//

#include <iostream>

using namespace std;

void maxProfit(int n, int price[], int k)
{
    int profit[n][k+1];

    //base case
    for(int i=0; i<=k; i++)
    {
        profit[0][i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        profit[i][0] = 0;
    }

    //recursive case
    for(int day=1; day<n; day++)
    {
        for(int t=1; t<=k; t++)
        {
            profit[day][t] = profit[day-1][t];

            for(int prevDay=0; prevDay<day; prevDay++)
            {
                profit[day][t] = max(profit[day][t], price[day] - price[prevDay] + profit[prevDay][t-1]);
            }

        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            cout<<profit[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;

    int price[n];
    for(int i=0; i<n; i++)
    {
        cin>>price[i];
    }

    int k;
    cin>>k;

    maxProfit(n, price, k);   

    return 0;
}