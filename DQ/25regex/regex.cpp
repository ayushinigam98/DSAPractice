#include <iostream>

using namespace std;

bool matchRegex(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    
    bool match[n1+1][n2+1];

    //base case
    for(int i=0; i<=n1; i++)
    {
        match[i][0] = false;
    }

    for(int i=0; i<=n2; i++)
    {
        match[0][i] = true;
    }

    match[0][0] = true;

    //dynamic programming
    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            if((str1[i-1] == str2[j-1] || str1[i-1] == '.') && match[i-1][j-1])
            {
                match[i][j] = true;
            }
            else if( match[i-2][j] || (str1[i-1] == '*' && (str1[i-2] == str2[j-1] || str1[i-2] == '.') && match[i][j-1]))
            {
                match[i][j] = true;
            }
            else
            {
                match[i][j] = false;
            }
        }
    }

    return match[n1][n2];

}

int main()
{
    string str1, str2;

    cin>>str1;
    cin>>str2;

    cout<<matchRegex(str1, str2);

    return 0;
}