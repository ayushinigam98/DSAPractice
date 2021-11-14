#include <iostream>

using namespace std;

int function(int x, int y, int b)
{
    b = -b;

    return (x & b) | (y & ~b);
}

int main()
{
    int x, y, b;

    cin>>x;
    cin>>y;
    cin>>b;

    cout<<function(x, y, b);

    return 0;
}