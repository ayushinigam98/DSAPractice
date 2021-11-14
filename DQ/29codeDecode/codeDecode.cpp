#include <iostream>

using namespace std;

char itc(int x)
{
    return (char)(x + (int)'0');
}

int cti(char ch)
{
    return ((int)(ch) - (int)('0'));
}

string code(string str)
{
    string coded = "";

    char ch = str[0];
    int n = 0;

    for(int i=0; str[i] != '\0'; i++)
    {
        if(str[i] == ch)
        {
            n++;
        }
        
        if ((str[i] != ch) || (str[i+1] == '\0'))
        {
            coded = coded + itc(n) + ch;
            ch = str[i+1];
            n=1;
        }
    }

    return coded;
}

string decode(string str)
{
    string decoded = "";

    for(int i=0; str[i]!='\0'; i=i+2)
    {
        int l = cti(str[i]);
        char ch = str[i+1];

        for(int j=0; j<l; j++)
        {
            decoded = decoded + ch;
        }

    }

    return decoded;
}

int main()
{

    string str;

    cin>>str;

    cout<<code(str)<<endl;
    cout<<decode(code(str))<<endl;

    return 0;
}