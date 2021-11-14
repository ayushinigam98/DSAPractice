#include <iostream>

using namespace std;

string reverse(string str)
{
    int l = 0;
    int r = str.length()-1;

    while(l<r)
    {
        char ch = str[l];
        str[l] = str[r];
        str[r] = ch;
        l++;
        r--;
    }

    return str;
}

void LCS(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();

    int L[n1+1][n2+1];

    //base case
    for(int i=0; i<=n1; i++)
    {
        L[i][0] = 0;
    }

    for(int i=0; i<=n2; i++)
    {
        L[0][i] = 0;
    }

    //recursive case
    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                L[i][j] = 1 + L[i-1][j-1];
            }
            else
            {
                L[i][j] = min(L[i-1][j], L[i][j-1]);
            }
        }
    }

    int i=n1, j=n2;

    while(i>0 && j>0)
    {
        if(str1[i-1] == str2[j-1])
        {
            cout<<str1[i-1]<<" ";
            i--;
            j--;
        }
        else if(L[i-1][j] > L[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

}

void LPS(string str)
{
    //cout<<reverse(str);
    LCS(str, reverse(str));
}

int main()
{
    string str;
    cin>>str;

    LPS(str); 

    return 0;
}