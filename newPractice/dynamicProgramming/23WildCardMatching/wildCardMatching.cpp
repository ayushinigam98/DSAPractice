#include <iostream>

using namespace std;
//abcd*j
//abcdkkkkkj
void wildCardMatch(string str, string pattern)
{
    //match[i, j]
    //if(pattern[j] == ? || str[i] == str[j]) match[i-1][j-1]
    //if(pattern[j] == *)  T[i-1][j] || T[i][j-1]
    //else false
    int ns = str.length();
    int np = pattern.length();
    bool match[ns+1][np+1];

    //base case
    for(int i=1; i<=ns; i++)
    {
        match[i][0] = false;
    }  

    for(int i=1; i<=np; i++)
    {
        match[0][i] = false;    
    }

    match[0][0] = true;

    //recursive case

    for(int i=1; i<=ns; i++)
    {
        for(int j=1; j<=np; j++)
        {
            if(pattern[j] == '?' || str[i] == pattern[j])
            {
                match[i][j] = match[i-1][j-1];
            }
            else if(pattern[j] == '*')
            {
                match[i][j] = (match[i-1][j] || match[i][j-1]);
            }
            else
            {
                match[i][j] = false;
            }
        }
    }

    for(int i=0; i<=ns; i++)
    {
        for(int j=0; j<=np; j++)
        {
            cout<<match[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    string str;
    cin>>str;

    string pattern;
    cin>>pattern;
    
    wildCardMatch(str, pattern);
    
    return 0;
}