#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void initialize(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        arr[i] = 0;
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

tuple<int, int, int> kadane(int n, int arr[])
{
    int ll=0, rl=0, lg = 0, rg = 0;
    int globalSum = 0;
    int localSum = 0;

    for(int i=0; i<n; i++)
    {
        if(arr[i] >= arr[i] + localSum)
        {
            localSum = arr[i];
            ll = i;
            rl = i;
        }
        else
        {
            localSum = arr[i] + localSum;
            rl = i;
        }

        if(localSum>globalSum)
        {
            globalSum = localSum;
            lg = ll;
            rg = rl;
        }
    }
    
    return make_tuple(lg, rg, globalSum);
}

void maxSumRectangle(int rows, int columns, vector<vector<int>> &arr)
{
    int sum[rows];
    int maxleft = 0, maxright = 0, maxtop = 0, maxbottom = 0;
    int maxSum = 0;

    for(int i=0; i<columns; i++)
    {
        initialize(rows, sum);

        for(int j=i; j<columns; j++)
        {
            for(int k=0; k<rows; k++)
            {
                sum[k] = sum[k] + arr[k][j];
            }
            
            int top, bottom, s;
            tie(top, bottom, s) = kadane(rows, sum);
            //print(rows, sum);
            //cout<<s<<" "<<endl;
            if(s > maxSum)
            {
                maxleft = i;
                maxright = j;
                maxtop = top;
                maxbottom = bottom;
                maxSum = s;
            }
        }
    }

    cout<<maxSum<<"|"<<"("<<maxtop<<","<<maxleft<<")";
    cout<<"("<<maxtop<<","<<maxright<<")";
    cout<<"("<<maxbottom<<","<<maxleft<<")";
    cout<<"("<<maxbottom<<","<<maxright<<")"<<endl;

    for(int i=maxtop; i<=maxbottom; i++)
    {
        for(int j=maxleft; j<=maxright; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int rows, columns;
    cin>>rows;
    cin>>columns;

    vector<vector<int>> arr(rows);

    for(int i=0; i<rows; i++)
    {
        arr[i] = vector<int>(columns);

        for(int j=0; j<columns; j++)
        {
            cin>>arr[i][j];
        }
    }

    maxSumRectangle(rows, columns, arr);

    return 0;
}
