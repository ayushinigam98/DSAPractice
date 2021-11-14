#include <iostream>

using namespace std;

void longestSubstring(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();

    int longest[n1+1][n2+1];

    //base case
    for(int i=0; i<=n1; i++)
    {
        longest[i][0] = 0;
    }

    for(int i=0; i<=n2; i++)
    {
        longest[0][i] = 0;
    }

    //recursive case
    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                longest[i][j] = 1 + longest[i-1][j-1];
            }
            else
            {
                longest[i][j] = 0;
            }
        }
    }

    for(int i=0; i<=n1; i++)
    {
        for(int j=0; j<=n2; j++)
        {
            cout<<longest[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    string str1;
    string str2;

    cin>>str1;
    cin>>str2;

    longestSubstring(str1, str2);

    return 0;
}