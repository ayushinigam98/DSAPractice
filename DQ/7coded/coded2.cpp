#include <iostream>

using namespace std;

void print(int n, long long int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

int possibleCodes(int n, string str)
{
    long long int codes[n+1];

    //base case:
    codes[0] = 1;
    codes[1] = 1;

    if(str[0] == '0')
        return 0;

    for(int i=2; i<=n; i++)
    {
        codes[i] = 0;

        if(str[i-1] != '0')
        {
            codes[i] += codes[i-1]; 
        }

        if((str[i-2] == '1' && str[i-1] <= '9') || (str[i-2] == '2' && str[i-1] <= '6'))
        {
            codes[i] += codes[i-2];
        }
    }

    return codes[n];
}

int main()
{
    string str;
    cin>>str;
    
    int n = str.length();

    cout<<possibleCodes(n, str);

    return 0;
}