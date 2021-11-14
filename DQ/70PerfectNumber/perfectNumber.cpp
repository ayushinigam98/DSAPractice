#include <iostream>

using namespace std;

int perfectNumber(int n)
{
    int pn = 19;

    while(--n)
    {
        pn = pn + 9;
    }

    return pn;
}

int main()
{
    int n;
    cin>>n;

    cout<<perfectNumber(n);

    return 0;
}