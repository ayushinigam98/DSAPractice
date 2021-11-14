#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
using namespace std;

int maxAreaHistogram(int n, int arr[])
{
    stack<int> height;
    stack<int> index;

    int area = 0;

    for(int i=0; i<n; i++)
    {
        if(height.empty() || arr[i] > height.top())
        {
            height.push(arr[i]);
            index.push(i);
        }
        else
        {
            int pos;
        
            while(!height.empty() && arr[i] <= height.top())
            {
                pos = index.top();

                if(height.top()*(i-pos) > area)
                    area = height.top()*(i-pos);

                height.pop();
                index.pop();
            }

            height.push(arr[i]);
            index.push(pos);
        }
    }

    while(!height.empty())
    {
        if(height.top()*(n-index.top()) > area)
            area = height.top()*(n-index.top());

        height.pop();
        index.pop();
    }

    return area;
}

void initializeZero(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        arr[i] = 0;
    }
}

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int maxRectangle(int rows, int columns, vector<vector<int>> &matrix)
{
    int histogram[columns];
    int area = 0;
    int localArea = 0;

    initializeZero(columns, histogram);
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            if(matrix[i][j] == 0)
                histogram[j] = 0;
            else
                histogram[j] += 1;
        }   
        print(columns, histogram);
        localArea = maxAreaHistogram(columns, histogram);

        area = max(area, localArea);
    }

    return area;
}

int main()
{

    int rows, columns;
    cin>>rows;
    cin>>columns;

    vector<vector<int>> matrix(rows);

    for(int i=0; i<rows; i++)
    {
        matrix[i] = vector<int>(columns);
        for(int j=0; j<columns; j++)
        {
            cin>>matrix[i][j];
        }
    }

    cout<<maxRectangle(rows, columns, matrix);   
 

    return 0;
}