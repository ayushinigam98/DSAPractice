#include <iostream>
#include <climits>
using namespace std;

int editDistance(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    int operations[n1+1][n2+1];

    //base case
    for(int i=0; i<n1; i++)
    {
        operations[i][0] = i;
    }

    for(int i=0; i<n2; i++)
    {
        operations[0][i] = i;
    }

    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            operations[i][j] = INT_MAX;
            
            if(str1[i-1] == str2[j-1])
            {
                operations[i][j] = min(operations[i][j], operations[i-1][j-1]);
            }
            operations[i][j] = min(operations[i][j], 1 + operations[i-1][j]);
            operations[i][j] = min(operations[i][j], 1 + operations[i][j-1]);
            operations[i][j] = min(operations[i][j], 1 + operations[i-1][j-1]);
        }
    }

    return operations[n1][n2];
}

int main()
{
    string str1;
    string str2;

    cin>>str1;
    cin>>str2;

    cout<<editDistance(str1, str2);

    return 0;
}