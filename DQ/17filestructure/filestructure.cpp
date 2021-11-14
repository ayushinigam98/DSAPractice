#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int findIndentations(int start, string str)
{
    if(str[start] != '\\')
    {
        return 0;
    }

    int end;
    for(end = start; str[end] == '\\'; end=end+2);
    //example: \n\t\t\t(ch) will terminate on character (ch)
    end--;

    return (end-start+1-2)/2;
}

int findEnd(int start, string str)
{
    int end;

    for(end = start; str[end] != '\0' && str[end] != '\\'; end++);

    return --end;
}

int findindentationEnd(int start, string str)
{ 
    if(str[start] != '\\')
    {
        return start;
    }

    int end;
    for(end = start; str[end] == '\\'; end=end+2);
    //example: \n\t\t\t(ch) will terminate on character (ch)

    return end;
}

void popStack(stack<int>&s, int &top, int final)
{
    while(top > final)
    {
        s.pop();
        top--;
    }
}

string longFilePath(string files)
{
    int n = files.length();
    
    stack<int> s;
    s.push(0);
    int top = 1;

    int i = 0, j = 0;
    int indentations = 0;
    int sum = 0;

    while(i < n)
    {
        indentations = findIndentations(i, files);
        popStack(s, top, indentations+1);
        i = findindentationEnd(i, files);
        j = findEnd(i, files);

        cout<<"indexes: "<<i<<" "<<j<<" | "<<files[i]<<"-"<<files[j];
        cout<<"| "<<s.top()<<endl;

        s.push(s.top() + (j-i+1) +1);
        top++;

        if(s.top() > sum)
            sum = s.top();

        i = j+1;
    }

    cout<<--sum;

    return "";
}

int main()
{
    string files;
    cin>>files;

    cout<<longFilePath(files);

    return 0;
}