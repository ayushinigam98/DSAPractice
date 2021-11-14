#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int sortOrderHelp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int minimumRooms(int n, pair<int, int> intervals[])
{
    sort(intervals, intervals+n, sortOrderHelp);

    for(int i=0; i<n; i++)
    {
        cout<<intervals[i].first<<" "<<intervals[i].second<<endl;
    }

    return 0;

}

int main()
{
    int n;
    cin>>n;

    pair<int, int> intervals[n];

    for(int i=0; i<n; i++)
    {
        int s, f;
        cin>>s;
        cin>>f;

        intervals[i] = make_pair(s, f);
    }

    minimumRooms(n, intervals);

    return 0;
}