#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void printString(vector<vector<int>> &canBreak, int i, int j, string str)
{
    if(canBreak[i][j] == j)
    {
        cout<<str.substr(i, j-i+1);
        return ;
    }

    printString(canBreak, i, canBreak[i][j], str);
    printString(canBreak, canBreak[i][j]+1, j, str);
}

void wordBreak(unordered_set<string> &dictionary, string str)
{
    int n = str.length();

    int canBreak[n][n];

    // base case
    for(int i=0; i<n; i++)
    {
        string s(1, str[i]);
        if(dictionary.find(s) != dictionary.end())
        {
            canBreak[i][i] = i;
        }
        else
        {
            canBreak[i][i] = -1;
        }
    }

    for(int l = 2; l <= n; l++)
    {
        for(int i=0; i<n-l+1; i++)
        {
            int j = i + l - 1;

            canBreak[i][j] = -1;

            if(dictionary.find(str.substr(i, l)) != dictionary.end())
            {
                canBreak[i][j] = j;
            }
            else
            {
                for(int k = i; k<j; k++)
                {
                    if(canBreak[i][k] != -1 && canBreak[k+1][j] != -1)
                    {
                        canBreak[i][j] = k;
                        break;
                    }
                }
            }
        }
    }



}

int main()
{   
    int n;
    cin>>n;

    unordered_set<string> dictionary;

    for(int i=0; i<n; i++)
    {
        string inputstr;
        cin>>inputstr;

        dictionary.insert(inputstr);
    }

    string str;
    cin>>str;

    wordBreak(dictionary, str);

    return 0;
}