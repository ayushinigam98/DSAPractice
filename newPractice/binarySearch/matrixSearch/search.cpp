#include <iostream>
#include <vector>

using namespace std;

void find(int n, int m, vector<vector<int>> &arr, int key)
{
    int i = 0;
    int j = m-1;

    while(i>=0 && i<n && j>=0 && j<m)
    {
        if(key == arr[i][j])
        {
            cout<<i<<" "<<j;
            return;
        }
        else if(key < arr[i][j])
        {
            j--;
        }
        else
        {
            i++;
        } 
    }

    cout<<"not found";
}

int main()
{
    int n, m, key;
    cin>>n;
    cin>>m;
    vector<vector<int>> arr(n);
    for(int i=0; i<n; i++)
    {
        arr[i] = vector<int>(m);
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
        }
    }
    cin>>key;

    find(n, m, arr, key);

    return 0;
}