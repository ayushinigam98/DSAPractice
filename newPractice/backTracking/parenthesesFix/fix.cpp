#include <iostream>
#include <climits>
using namespace std;

void printFix(string brackets, int pos, int open, int close, string fix, int n, int &max, string &ret)
{
    if(pos >= n)
    {
        if(open == close)
        {
            int l = fix.length();

            if(l > max)
            {
                max = fix.length();
                ret = fix;
            }
            else if(l == max)
            {
                ret = ret + " " + fix;
            }
        }
        return ;
    }

    if(brackets[pos] == '(')
        open++;
    else if(brackets[pos] == ')')
        close++;

    if(close > open)
    {
        //recurse after removing
        printFix(brackets, pos+1, open, close-1, fix, n, max, ret);
    }
    else
    {
        //recurse without removing
        printFix(brackets, pos+1, open, close, (fix+brackets[pos]), n, max, ret);

        //recurse after removing
        if(brackets[pos] == '(')
            printFix(brackets, pos+1, open-1, close, fix, n, max, ret);
        else if(brackets[pos] == ')')
            printFix(brackets, pos+1, open, close-1, fix, n, max, ret);
        else
            printFix(brackets, pos+1, open, close, fix, n, max, ret);
    }

}

int main()
{

    string brackets;
    cin>>brackets;

    int n = brackets.length();
    int max = -1;
    string ret = "";
    printFix(brackets, 0, 0, 0, "", n, max, ret);   
    cout<<endl;
    cout<<ret;

    return 0;
}