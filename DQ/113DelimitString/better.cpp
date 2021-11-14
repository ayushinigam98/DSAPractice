#include <iostream>

using namespace std;

string reverse(string &word, int start, int end)
{
    int i = start;
    int j = end;

    while(i<j)
    {
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
        i++;
        j--;
    }
}

void findWord(int &i, string str)
{
    for(; str[i] != ' ' && str[i] != '\0'; i++);
    i--;
}

string delimit(string str)
{
    int n = str.length();
    reverse(str, 0, n-1);
    
    int i = 0;
    while(i<n)
    {
        int start = i;
        findWord(i, str);
        reverse(str, start, i);
        i +=2;
    }

    return str;
}

int main()
{
    string str;

    getline(cin, str);
    //cout<<str;
    cout<<delimit(str);

    return 0;
}