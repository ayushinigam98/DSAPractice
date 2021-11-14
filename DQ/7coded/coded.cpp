#include <iostream>

using namespace std;


void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int numchar(char ch)
{
    return ((int)ch - (int)'0');
}

int possiblecodes(string str)
{
    int n = str.length();
    //codes[n] = codes[n-1] (only if n and n-1 form valid sequence, then add->) + codes[n-2]
    int codes[n+1];

    //base cases
    codes[0] = 1;
    codes[1] = (numchar(str[0]) == 0)?0:1;

    for(int i=2; i<=n; i++)
    {
        codes[i] = 0;
        
        if(numchar(str[i-1]) > 0)
        {
            codes[i] = codes[i-1];
        }

        int number = numchar(str[i-2])*10 + numchar(str[i-1]);
        if( 10 <= number && number <= 26)
        {
                codes[i] = codes[i] + codes[i-2];
        }

    }

    return codes[n];
}

int main()
{
    string str;
    cin>>str;

    cout<<possiblecodes(str);

    return 0;
}