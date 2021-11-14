#include <iostream>

using namespace std;

void printSolution(int n, int solution[], int arr[])
{
    if(solution[n] != -1)
    {
        printSolution(solution[n], solution, arr);
    }

    cout<<arr[n]<<" ";
}

void longestIncreasingSubsequence(int n, int arr[])
{
    int LIS[n];
    int S[n];

    //base case
    LIS[0] = 1;
    S[0] = -1;

    //recursive case
    cout<<endl;
    int maxIndex = 0; 
    for(int i=1; i<n; i++)
    {
        LIS[i] = 1;
        S[i] = -1;
        for(int j=0; j<i; j++)
        {
            if(arr[j] <= arr[i] && LIS[i] < (1 + LIS[j]))
            {
                LIS[i] = 1 + LIS[j];
                S[i] = j;
            }
        }

        cout<<LIS[i]<<" ";

        if(LIS[maxIndex] < LIS[i])
        {
            maxIndex = i;
        }
    }
    cout<<maxIndex<<"|";

    for(int i=0; i<n; i++)
    {
        cout<<S[i]<<" ";
    }
    cout<<"|";

    cout<<LIS[maxIndex]<<endl;

    printSolution(maxIndex, S, arr);
    
}

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    longestIncreasingSubsequence(n, arr);

    return 0;
}