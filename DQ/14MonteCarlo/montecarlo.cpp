#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

bool inCircle(float x, float y)
{
    return ((x-1)*(x-1) + (y-1)*(y-1) <= 1);
}

float error(float guess, float actual)
{
    return (actual - guess);
}

float absolute(float x)
{
    return x>0?x:-x;
}

float monteCarlo()
{
    float guess = 0;
    int inside = 0;
    int total = 0;
    float actual = 3.14159;
    
    while(absolute(error(guess, actual)) > 0.0001)
    {

        if(inCircle((float) rand()/RAND_MAX, (float) rand()/RAND_MAX))
        {
            inside++;
        }

        total++;

        guess = ((float)4*inside/(float)total);
        
        cout<<guess<<" ";
        cout<<absolute(error(guess, actual))<<endl;
    }

    cout<<"pi estimated to three digits through monte carlo method: ";

    return guess;
}

int main()
{
    cout<<monteCarlo();

    return 0;
}