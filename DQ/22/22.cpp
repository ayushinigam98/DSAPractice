#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

void print(vector<vector<int>> &split, int i, int j, string str)
{
    //cout<<"hi ";
    if(split[i][j] == str.length())
    {
        cout<<str.substr(i, j-i+1)<<" ";
    }    
    else if(split[i][j] >= 0)
    {
        print(split, i, split[i][j], str);
        print(split, (split[i][j]+1), j, str);
    }
}

void breakStringToWords(int wordNum, string words[], string str)
{
    unordered_set<string> dictionary;
    int n = str.length();

    for(int i=0; i<wordNum; i++)
    {
        dictionary.insert(words[i]);
    }

    vector<vector<int>> split(n);

    for(int i=0; i<n; i++)
        split[i] = vector<int>(n);

    for(int i=0; i<n; i++)
    {
        if(dictionary.find(string(1, str[i])) == dictionary.end())
        {
            split[i][i] = -1;
        }
        else
        {
            split[i][i] = n;
        }
    }

    for(int len=2; len<=n; len++)
    {
        for(int i=0; i<=n-len; i++)
        {
            int j = i + len -1;
            
            split[i][j] = -1;
            for(int k=i; k<j; k++)
            {
                if(split[i][k]>=0 && split[k+1][j]>=0)
                {
                    split[i][j] = k;
                }
            }

            if(dictionary.find(str.substr(i, len)) != dictionary.end())
            {
                split[i][j] = n;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            cout<<0<<" ";
        }

        for(int j=i; j<n; j++)
        {
            cout<<split[i][j]<<" ";
        }
        cout<<endl;
    }

    print(split, 0, n-1, str);

}

int main()
{
    int n;
    cin>>n;
    
    string words[n];

    for(int i=0; i<n; i++)
    {
        cin>>words[i];
    }

    string str;
    cin>>str;

    breakStringToWords(n, words, str);
    
    return 0;
}