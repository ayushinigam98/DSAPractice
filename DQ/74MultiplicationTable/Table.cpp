#include <iostream>

using namespace std;

int numXs(int n, int x)
{
    int num = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(x == i*j)
                num++;
        }
    }

    return num;
}

int main()
{
    int n, x;

    cin>>n;
    cin>>x;

    cout<<numXs(n, x);

    return 0;
}