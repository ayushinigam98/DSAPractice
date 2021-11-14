#include <iostream>

using namespace std;

struct Interval
{
    int start;
    int finish;

    Interval()
    {

    }

    Interval(int s, int f)
    {
        start = s;
        finish = f;
    }
};

int maxJobs(int n, Interval intervals[])
{
    if(n <= 0)
        return -1;

    int num = 1;
    int f = intervals[0].finish;

    for(int i=1; i<n; i++)
    {
        if(intervals[i].start >= f)
        {
            num++;
            f = intervals[i].finish;
        }
    }

    return num;
}

int main()
{
    int n;
    cin>>n;

    Interval intervals[n];

    for(int i=0; i<n; i++)
    {
        cin>>intervals[i].start;
        cin>>intervals[i].finish;
    }

    cout<<maxJobs(n, intervals);

    return 0;
}