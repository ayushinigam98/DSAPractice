#include <iostream>

using namespace std;

int removeBrackets(string str)
{
    int open = 0;
    int close = 0;
    int remove = 0;

    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == '(')
        {
            open++;
        }
        else if(close >= open)
        {
            remove++;
        }
        else
        {
            close++;
        }
    }
    
    remove = remove + open-close;

    return remove;
}

int main()
{
    string str;
    cin>>str;

    cout<<removeBrackets(str);

    return 0;
}