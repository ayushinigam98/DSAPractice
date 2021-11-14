#include <iostream>

using namespace std;

bool interleaving(string str1, string str2, string str)
{
    int n1 = str1.length();
    int n2 = str2.length();

    bool interleaved[n1+1][n2+1];

    //base case
    interleaved[0][0] = true; 
    for(int i=1; i<=n1; i++)
    {
        if(str[i-1] == str1[i-1])
            interleaved[i][0] = interleaved[i-1][0];
        else
            interleaved[i][0] = false;
    }

    for(int i=1; i<=n2; i++)
    {
        if(str[i-1] == str2[i-1])
            interleaved[0][i] = interleaved[0][i-1];
        else
            interleaved[0][i] = false;
    }

    //recursive case
    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            interleaved[i][j] = false;

            if(str[i+j-1] == str1[i-1])
            {
                cout<<"("<<i<<","<<j<<")";
                interleaved[i][j] = interleaved[i-1][j];
            }

            if(str[i+j-1] == str2[j-1])
            {
                cout<<"("<<i<<","<<j<<")";
                interleaved[i][j] = interleaved[i][j] || interleaved[i][j-1];
            }

            cout<<endl;
        }
    }

    for(int i=0; i<=n1; i++)
    {
        for(int j=0; j<=n2; j++)
        {
            cout<<interleaved[i][j]<<" ";
        }
        cout<<endl;
    }

    return interleaved[n1][n2];

}

int main()
{
    string str1, str2, str;

    cin>>str1;
    cin>>str2;

    cin>>str;

    cout<<interleaving(str1, str2, str);

    return 0;
}