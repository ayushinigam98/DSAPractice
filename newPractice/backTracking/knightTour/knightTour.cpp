#include <iostream>
#include <vector>
using namespace std;

int directions = 8;
int di[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dj[] = {1, -1, 1, -1, 2, -2, 2, -2};

bool inBoundary(int i, int j, int n)
{
    return (i>=0 && i<n && j>=0 && j<n);
}

void print(vector<vector<int>> &move, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<move[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool tour(vector<vector<int>> &move, int i, int j, int steps, int n)
{
    if(steps == n*n)
    {
        //print all the moves
        print(move, n);
        return true;
    }

    for(int d=0; d<directions; d++)
    {
        int nexti = i + di[d];
        int nextj = j + dj[d];

        if(inBoundary(nexti, nextj, n) && move[nexti][nextj] == 0)
        {
            move[nexti][nextj] = steps+1;
            if(tour(move, nexti, nextj, steps+1, n))
                return true;
            else
                move[nexti][nextj] = 0;
        }
        
    }

    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> move(n);

    for(int i=0; i<n; i++)
    {
        move[i] = vector<int>(n);
        for(int j=0; j<n; j++)
        {
            move[i][j] = 0;
        }
    }
    move[0][0] = 1;
    tour(move, 0, 0, 1, n);


    return 0;
}