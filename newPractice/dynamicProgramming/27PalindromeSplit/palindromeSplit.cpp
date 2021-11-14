#include <iostream>

using namespace std;

void palindromeSplit(string str)
{
    int n = str.length();

    int splits[n][n];

    //base case
    for(int i=0; i<n; i++)
    {
        splits[i][i] = 0; 
    }

    for(int i=0; i<n-1; i++)
    {
        splits[i+1][i] = -1;
    }

    //recursive
    //

    for(int len=2; len<=n; len++)
    {
        for(int i=0; i<n-len+1; i++)
        {
            int j = i + len - 1;
            splits[i][j] = n+1;
            for(int k=i; k<j; k++)
            {
                splits[i][j] = min(splits[i][j], splits[i][k] + splits[k+1][j] + 1);
            }

            //the word might be a palindrome
            if(str[i] == str[j] && splits[i+1][j-1] <= 0)
            {
                splits[i][j] = 0;
            }
        }
    } 

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
            cout<<"  ";
        for(int j=i; j<n; j++)
        {
            cout<<splits[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    string str;
    cin>>str;

    palindromeSplit(str);   

    return 0;
}