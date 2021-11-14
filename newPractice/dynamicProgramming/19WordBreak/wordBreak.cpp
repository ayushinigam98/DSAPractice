#include <iostream>
#include <unordered_set>

using namespace std;

void wordBreak(unordered_set<string> &dictionary, string str)
{
    int n = str.length();
    bool canBreak[n][n];

    //base case
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            canBreak[i][j] = false;
        }
    }
    for(int i=0; i<n; i++)
    {
        string s(1, str[i]);
        canBreak[i][i] = (dictionary.find(s) != dictionary.end())?true:false;
    }

    //recursive case
    for(int l=2; l<=n; l++)
    {
        for(int i=0; i<n-l+1; i++)
        {
            int j = i + l - 1;
            
            canBreak[i][j] = false;
            
            if(dictionary.find(str.substr(i, l)) != dictionary.end())
            {
                canBreak[i][j] = true;
            }
            else
            {
                for(int cut = i; cut<j; cut++)
                {
                    if(canBreak[i][cut] && canBreak[cut+1][j])
                    {
                        canBreak[i][j] = true;
                        break;
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<canBreak[i][j]<<" ";
        }
        cout<<endl;
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