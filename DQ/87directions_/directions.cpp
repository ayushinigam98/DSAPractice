#include <iostream>
#include <unordered_map>
using namespace std;

void setDirections(unordered_map<string, pair<int ,int>> &dir)
{
    dir["N"] = make_pair(0, 1);
    dir["S"] = make_pair(0, -1);
    dir["E"] = make_pair(1, 0);
    dir["W"] = make_pair(-1, 0);
    dir["NE"] = make_pair(1, 1);
    dir["NW"] = make_pair(1, -1);
    dir["SE"] = make_pair(-1, 1);
    dir["SW"] = make_pair(-1, -1);
}

bool validRules(int n, int rules[])
{
    unordered_map<string, pair<int, int>> dir;
    setDirections(dir);

    unordered_map<char, pair<int, int>> map;

    for(int i=0; i<n; i++)
    {
        
    }
}

int main()
{
    int n;
    cin>>n;

    string rules[n];

    for(int i=0; i<n; i++)
    {
        cin>>rules[i];
    }

    return 0;
}