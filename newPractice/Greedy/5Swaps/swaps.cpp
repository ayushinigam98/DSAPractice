#include <iostream>

using namespace std;

void swap(int l, int r, string &str)
{
    char temp = str[l];
    str[l] = str[r];
    str[r] = temp;
}

int balanceSwaps(string str)
{
    int n = str.length();

    int swaps = 0;

    int l = 0;
    int r = n-1;

    int openl = 0;
    int closedl = 0;

    int openr = 0;
    int closedr = 0;

    while(l<=r)
    {
        if(openl >= closedl)
        {
            cout<<"l-before: "<<l<<" |";
            if(str[l] == '[')
                openl++;
            else
                closedl++;
            
            if(openl >= closedl)
                l++;
            cout<<"l-after: "<<l<<endl;
        }
        else if(closedr >= openr)
        {
            cout<<"r-before: "<<r<<" |";
            if(str[r] == ']')
                closedr++;
            else
                openr++;

            if(closedr >= openr)
                r--;
            cout<<"r-after: "<<r<<endl;
        }
        else
        {
            cout<<"("<<l<<","<<r<<")"<<endl;
            swap(l,r, str);
            l++;
            r--;
            openl = 0;
            closedl = 0;
            openr = 0;
            closedr = 0;
            swaps++;
        }

    }

    return swaps;   
}

int main()
{
    string str;
    cin>>str;

    cout<<balanceSwaps(str);

    return 0;
}