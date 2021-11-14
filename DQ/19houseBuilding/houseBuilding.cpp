#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void placeMin3(pair<int, int> h[][3], vector<vector<int>> &house, int row, int k)
{
    for(int i=0; i<3; i++)
    {
        if(house[row][i] < house[row][(i+1)%3] && house[row][i] < house[row][(i-1+3)%3])
        {
            h[row][0] = make_pair(house[row][i], i);

            if(house[row][(i+1)%3] < house[row][(i-1+3)%3])
            {
                h[row][1] = make_pair(house[row][(i+1)%3], (i+1)%3);
                h[row][2] = make_pair(house[row][(i-1+3)%3], (i-1+3)%3);
            }
            else
            {
                h[row][1] = make_pair(house[row][(i-1+3)%3], (i-1+3)%3);
                h[row][2] = make_pair(house[row][(i+1)%3], (i+1)%3);
            }
        }
    }

    for(int i=3; i<k; i++)
    {
        if(house[row][i] < h[row][0].first)
        {
            h[row][2] = h[row][1];
            h[row][1] = h[row][0];
            h[row][0] = make_pair(house[row][i], i);
        }
        else if(house[row][i] < h[row][1].first)
        {
            h[row][2] = h[row][1];
            h[row][1] = make_pair(house[row][i], i);
        }
        if(house[row][i] < h[row][2].first)
        {
            h[row][2] = make_pair(house[row][i], i);
        }
    }

}

int minCost(int N, int K, vector<vector<int>> &house)
{
    pair<int, int> h[N][3];

    for(int i=0; i<N; i++)
    {
        placeMin3(h, house, i, K);
    } 

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<h[i][j].first<<" "<<h[i][j].second<<"|";
        }
        cout<<endl;
    }

    for(int i=1; i<N; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(h[i][j].second == h[i-1][0].second)
                h[i][j].first += min(h[i-1][1].first, h[i-1][2].first);
            else if(h[i][j].second == h[i-1][1].second)
                h[i][j].first += min(h[i-1][0].first, h[i-1][2].first);
            else if(h[i][j].second == h[i-1][2].second)
                h[i][j].first += min(h[i-1][0].first, h[i-1][1].first);
        }
    }

    return min(min(h[N-1][0].first, h[N-1][1].first), h[N-1][2].first);
}

int main()
{
    int N, K;
    cin>>N;
    cin>>K;

    vector<vector<int>> arr(N);

    for(int i=0; i<N; i++)
    {
        arr[i] = vector<int>(K);
        for(int j=0; j<K; j++)
        {
            cin>>arr[i][j];
        }
    }
    //initialization done

    cout<<minCost(N, K, arr);
}