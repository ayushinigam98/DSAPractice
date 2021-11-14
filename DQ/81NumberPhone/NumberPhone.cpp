#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void printPosibilities(string str, unordered_map<int, vector<char>> map, int number)
{
    if(number == 0)
    {
        cout<<str<<" ";
        return ;
    }

    int digit = number%10;

    vector<char> characters = map.find(digit)->second;

    for(int i=0; i<characters.size(); i++)
    {
        printPosibilities(string(1, characters[i]) + str, map, number/10);
    }
}

void Numberphone(unordered_map<int, vector<char>> map, int number)
{
    string str = "";
    printPosibilities(str, map, number);
}

int main()
{
    unordered_map<int, vector<char>> map;
    
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        //cout<<"digit: ";
        int digit;
        cin>>digit;

        //cout<<"numChars: ";
        int numChars;
        cin>>numChars;

        vector<char> temp(numChars);

        for(int j=0; j<numChars; j++)
        {
            //cout<<"char: ";
            cin>>temp[j];
            //cout<<"ho";
        }
    
        map[digit] = temp;
    }

    int number;
    cin>>number;

    Numberphone(map, number);

    return 0;
}