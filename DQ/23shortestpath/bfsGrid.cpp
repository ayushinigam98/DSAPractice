#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int diri[] = {0, 0, 1, -1};
int dirj[] = {1, -1, 0, 0};
int directions = 4;

void print(int rows, int columns, vector<vector<bool>> &arr)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printi(int rows, int columns, vector<vector<int>> &arr)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void initializeArray(int rows, int columns, vector<vector<int>> &arr)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            arr[i].push_back(0);
        }
    }
}

bool inBoundary(int i, int j, int rows, int columns)
{
    return (i>=0 && i<rows && j>=0 && j<columns);
}

int findMinSteps(int rows, int columns, vector<vector<bool>> &room, int starti, int startj, int endi, int endj)
{
    vector<vector<int>> color(rows);
    vector<vector<int>> distance(rows);

    //initialize the color of all the nodes to white
    initializeArray(rows, columns, color);
    initializeArray(rows, columns, distance);
    //create queue to store the nodes
    queue<pair<int, int>> q;

    //add the source node
    q.push(make_pair(starti, startj));

    //color start node grey
    color[starti][startj] = 1;
    //and the dist 0
    distance[starti][startj] = 0;

    //current values of i and j
    int i, j;
    
    while(!q.empty())
    {
        //get the next node in the breath
        i = q.front().first;
        j = q.front().second;
        q.pop();

        //go through all the neighbours of the current node and add them to the list
        for(int d=0; d<directions; d++)
        {
            int ni = i + diri[d]; 
            int nj = j + dirj[d];

            //check if neighbour is in boundary, a room and undiscovered
            if(inBoundary(ni, nj, rows, columns) && room[ni][nj] && (color[ni][nj] == 0))
            {
                //color it discovered, that is grey
                color[ni][nj] = 1;
                //add it to the queue
                q.push(make_pair(ni, nj));
                //add its distance
                distance[ni][nj] = distance[i][j] + 1;

                if(ni == endi && nj == endj)
                    return distance[ni][nj];
            }
        }
        //color the current node black
        color[i][j] = 2;
    }

    return -1;

}

int main()
{
    int rows, columns;
    cin>>rows;
    cin>>columns;

    vector<vector<bool>> room(rows);

    for(int i=0; i<rows; i++)
    {
        //room[i] = vector<bool>();
        
        for(int j=0; j<columns; j++)
        {
            int x;
            cin>>x;
            room[i].push_back(x);
        }
    }

    int starti, startj, endi, endj;
    cin>>starti;
    cin>>startj;
    cin>>endi;
    cin>>endj;

    cout<<findMinSteps(rows, columns, room, starti, startj, endi, endj);

    return 0;
}