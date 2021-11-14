#include <iostream>
#include <Windows.h>

using namespace std;

void func(int i)
{
    cout<<"called: "<<i<<endl;
}

int main()
{
    int i=0;
    int n;
    cin>>n;

    int milliSeconds = n*1000;

    while(true)
    {
        func(i++);
        Sleep(milliSeconds);
    }

    return 0;
}