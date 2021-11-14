#include <iostream>

using namespace std;

void initialize(int n, int arr[], int x)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = x;
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

int bishopPairsAttacked(int n, pair<int, int> bishops[]) 
{
    int d1[2*n - 1];
    int d2[2*n - 1];

    initialize(2*n-1, d1, 0);
    initialize(2*n-1, d2, 0);

    int attacks = 0;

    for(int k=0; k<n; k++)
    {
        auto [i, j] = bishops[k];
        if(i != -1)
        {
            attacks += d1[i+j];
            attacks += d2[i-j+n-1];
            d1[i+j]++;
            d2[i-j+n-1]++;
        }
    }

    return attacks;
}

int main()
{
    int n;
    cin>>n;

    pair<int, int> bishops[n];

    for(int i=0; i<n; i++)
    {
        int x, y;
        cin>>x;
        cin>>y;
        bishops[i] = make_pair(x, y);
    }

    cout<<bishopPairsAttacked(n, bishops);

    return 0;
}