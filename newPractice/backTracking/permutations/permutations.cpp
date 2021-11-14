#include <iostream>

using namespace std;

void permutations(string &str, string perm, bool taken[])
{
    if(perm.length() == str.length())
    {
        cout<<perm<<endl;
        return;
    }

    for(int i=0; i<str.length(); i++)
    {
        if(!taken[i])
        {
            taken[i] = true;
            permutations(str, perm+str[i], taken);
            taken[i] = false;
        }
    }

}

int main()
{
    string str;

    cin>>str;
    bool taken[str.length()];
    for(int i=0; i<str.length(); i++)
    {
        taken[i] = false;
    }

    cout<<"\npermutations: "<<endl;
    permutations(str, "", taken);

    return 0;
}