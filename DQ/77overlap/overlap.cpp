#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct interval
{
    int start;
    int finish;

    interval()
    {

    }

    interval(int s, int f)
    {
        start = s;
        finish = f;
    }
};


bool sortHelper(interval i1, interval i2)
{
    return (i1.start <= i2.start);
}

vector<interval> overlap(int n, interval intervals[])
{
    sort(intervals, intervals + n, sortHelper);

    vector<interval> smallerInterval;

    int s = intervals[0].start;
    int f = intervals[0].finish;

    for(int i=1; i<n; i++)
    {
        if(intervals[i].start <= f)
        {
            //merge
            f = max(f, intervals[i].finish);
        }
        else
        {
            interval temp;
            temp.start = s;
            temp.finish = f;
            smallerInterval.push_back(temp);

            s = intervals[i].start;
            f = intervals[i].finish;
        }
    }

    interval temp;
    temp.start = s;
    temp.finish = f;
    smallerInterval.push_back(temp);

    return smallerInterval;
}

int main()
{
    int n;
    cin>>n;

    interval intervals[n];

    for(int i=0; i<n; i++)
    {
        cin>>intervals[i].start;
        cin>>intervals[i].finish;
    }

    vector<interval> smallerInterval = overlap(n, intervals);

    for(int i=0; i<smallerInterval.size(); i++)
    {
        cout<<smallerInterval[i].start<<" "<<smallerInterval[i].finish<<"|";
    }

    return 0;
}