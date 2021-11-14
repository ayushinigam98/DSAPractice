#include <iostream>
#include <unordered_map>

using namespace std;

int longestSubstring(int k, string str)
{
    unordered_map<char,int> map;

    int maxLen = 0;
    int chars = 0;
    int i = 0;
    int j = -1;

    cout<<j<<" "<<str.length();
    while(j<str.length() || j == -1)
    {
        
    }

    return maxLen;
}

int main()
{
    int k;
    cin>>k;

    string str;
    cin>>str;

    cout<<longestSubstring(k, str);

    return 0;
}