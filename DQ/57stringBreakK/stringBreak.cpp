#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int wordend(string str, int start)
{
    int current;
    
    for(current=start; str[current]!=' ' && str[current]!='\0'; current++);

    return current-1;
}

string space(string word)
{
    return (word==""?"":" ");
}

void stringBreak(string str, int k)
{
    //create vector to hold strings
    vector<string> brokenStrings;
    brokenStrings.push_back("");

    //initialize variables to mark start and end of word
    int start = 0;
    int end;
    int n = str.length();

    //current index in the vector
    int index=0;

    while(start < n)
    {
        //get word starting at start
        end = wordend(str, start);
        string word = str.substr(start, end-start+1);

        //stick it in the vector
        if((brokenStrings[index].length() + (brokenStrings[index]==""?0:1) + word.length()) <= k)
        {
            brokenStrings[index] = brokenStrings[index] + (brokenStrings[index]==""?"":" ") + word;
        }     
        else if(word.length() <= k)
        {
            brokenStrings.push_back(word);
            index++;
        }
        else
        {
            cout<<"not possible";
            return ;
        }

        start = end + 2;
    }

    cout<<endl;
    for(int i=0; i<brokenStrings.size(); i++)
    {
        cout<<brokenStrings[i]<<endl;
    }
}

int main()
{
    string str;
    
    getline(cin, str);

    cout<<str;
    int k;
    cin>>k;

    stringBreak(str, k);

    return 0;
}
