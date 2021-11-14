#include <iostream>
#include <vector>

using namespace std;

void moveStack(int start, int end, int helper, int n)
{
    if(n==0)
    {
        return ;
    }
    else
    {
        moveStack(start, helper, end, n-1);

        cout<<"move plate number"<<n<<" from pole"<<start<<" to pole"<<end<<endl;

        moveStack(helper, end, start, n-1);
    }
}
int main()
{   int n;
    cin>>n;
    
    moveStack(1, 2, 3, n);

    return 0;
}