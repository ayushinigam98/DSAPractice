#include <iostream>

using namespace std;

void takeInputArray(int n, int arr[], string str)
{
    //cout<<str<<endl; 
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
}

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void jobSchedulingProblem(int n, int start[], int finish[], int value[])
{
    int maxProfit[n];

    //base case
    maxProfit[0] = value[0];

    for(int i=1; i<n; i++)
    {
        maxProfit[i] = value[i];
        for(int j=i-1; j>=0; j--)
        {
            if(finish[j] <= start[i])
            {
                if((value[i] + maxProfit[j]) > maxProfit[i])
                {
                    maxProfit[i] = (value[i] + maxProfit[j]);
                }
            }
        }
    }

    print(n, maxProfit);

}
/*
6
enter start times:
1 2 4 6 5 7
enter end times:
3 5 6 7 8 9
enter value of each task:
5 6 5 4 11 2
*/
int main()
{
    int n;
    cin>>n;

    int start[n];
    int finish[n];
    int value[n];

    takeInputArray(n, start, "enter start times: ");
    takeInputArray(n, finish ,"enter end times: ");
    takeInputArray(n, value, "enter value of each task: ");

    jobSchedulingProblem(n, start, finish, value);

    return 0;
}