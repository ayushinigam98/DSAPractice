#include <iostream>

using namespace std;

void subsets(string str, int i, string sub)
{
    if(i >= str.length())
    {
        cout<<sub<<endl;
        return ;
    }

    subsets(str, i+1, sub);
    subsets(str, i+1, (sub + str[i]));
}

int main()
{
    string str;

    cin>>str;

    subsets(str, 0, "");
}