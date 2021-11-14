#include <iostream>

using namespace std;

int NUM = 10000;

int makePair(int n1, int n2)
{
    return n1 + n2*NUM;
}

int leftUnpair(int n)
{
    return n/NUM;
}

int rightUnpair(int n)
{
    return n%NUM;
}

int main()
{
    int n1, n2;
    
    cin>>n1;
    cin>>n2;

    cout<<leftUnpair(makePair(n1,n2));
    cout<<rightUnpair(makePair(n1,n2));

    return 0;
}