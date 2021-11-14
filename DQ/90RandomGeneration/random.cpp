#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <time.h>
using namespace std;

int random(int n, unordered_set<int> &set)
{
    while(true)
    {
        srand(time(0));
        float num = (rand()%n);
        cout<<"~ ";
        if(set.find(num) == set.end())
        {
            return num;
        }
    }
}

int randomBetter(int n, int l, int L[])
{
    unordered_map<int, int> map;

    for(int i=0; i<l; i++)
    {
        map[L[i]] = -1;
    }

    vector<int> tempWhiteList;
    for(int i = n-l; i<n; i++)
    {
        if(map.find(i) == map.end())
        {
            tempWhiteList.push_back(i);
        }
    }

    for(int i=0; i<l; i++)
    {
        if(L[i] < n-l)
        {
            map.find(L[i])->second = tempWhiteList[tempWhiteList.size()-1];
            tempWhiteList.pop_back();
        }
    }

    srand(time(0));
    int num = (rand()%(n-l));

    if(map.find(num) != map.end())
        return map.find(num)->second;
    else 
        return num;
}

int randomNumber(int n, int l, int L[])
{
    unordered_set<int> set;

    for(int i=0; i<l; i++)
    {
        set.insert(L[i]);
    }

    return random(n, set);
}

int main()
{
    int n, l;
    cin>>l;

    int L[l];

    for(int i=0; i<l; i++)
    {
        cin>>L[i];
    }

    cin>>n;

    cout<<randomBetter(n, l, L);

    return 0;
}