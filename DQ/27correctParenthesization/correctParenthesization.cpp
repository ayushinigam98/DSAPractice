#include <iostream>
#include <stack>

using namespace std;

char returnPair(char ch)
{
    if(ch == ')')
        return '(';
    else if(ch == '}')
        return '{';
    else if(ch == ']')
        return '[';
    else
        "";
}

bool parenthesization(string str)
{
    stack<char> s;

    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else if(!s.empty() && s.top() == returnPair(str[i]))
        {
            s.pop();
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string str;

    cin>>str;

    cout<<parenthesization(str);

    return 0;
}