#include <iostream>

using namespace std;

int regEx(string str, string pattern)
{
    int n = str.length();
    int np = pattern.length();

    /*
        match[i][j] = 
            if(str1[i] == pattern[j] || pattern[j] == '.') | 
                then match[i-1][j-1]
            if pattern[j] == '*' | 
                (then match[i][j-2] || if(str1[i] == pattern[j-1] || pattern[j-1] == '.') then match[i-1][j]])
            false 
    */

   //base case
    bool match[n+1][np+1];

    for(int i=0; i<=n; i++)
    {
        match[i][0] = false;
    }
    match[0][0] = true;
    for(int i=1; i<=np; i++)
    {
        if(pattern[i-1] == '*')
        {
            match[0][i] = match[0][i-2];
        }
        else
        {
            match[0][i] = false;
        }
    }

    //recursive case
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=np; j++)
        {
            if(str[i-1] == pattern[j-1] || pattern[j-1] == '.')
            {
                match[i][j] = match[i-1][j-1];
            }
            else if(pattern[j-1] == '*')
            {
                match[i][j] = match[i][j-2];
                
                if(str[i-1] == pattern[j-1-1] || pattern[j-1-1] == '.')
                {
                    match[i][j] = (match[i][j] || match[i-1][j]);
                }
            }
            else
            {
                match[i][j] = false;
            }
        }
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=np; j++)
        {
            cout<<match[i][j]<<" ";
        }
        cout<<endl;
    }

    return match[n][np];

}

int main()
{
    string str1;
    string str2;

    cin>>str1;
    cin>>str2;

    cout<<regEx(str1, str2);

}