#include <iostream>

using namespace std;

int rand5()
{

}

int rand7()
{
    int num = 25;
    
    while(num>20)
    {
        num = 5*(rand5() - 1) + (rand5() - 1);
    }

    return (num%7)+1;

}