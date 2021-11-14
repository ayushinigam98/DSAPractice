#include <iostream>

using namespace std;

int LCS(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();

    int LCS[n1+1][n2+1];

    for(int i=0; i<=n1; i++)
    {
        LCS[i][0] = 0;
    }

    for(int i=0; i<=n2; i++)
    {
        LCS[0][i] = 0;
    }

    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else
            {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }

    return LCS[n1][n2];

}

int main()
{
    string str1;
    string str2;

    cin>>str1;
    cin>>str2;

    cout<<LCS(str1, str2);

    return 0;
}