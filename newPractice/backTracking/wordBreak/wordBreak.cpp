#include <iostream>
#include <unordered_set>

using namespace std;

void printWordBreak(string str, unordered_set<string> &dictionary, int i, string wordBreak)
{

    if(i == str.length())
    {
        cout<<"("<<wordBreak<<")";
        return;
    }

    int strLen = str.length();
    string word = "";
    
    for(int start=i; start<strLen; start++)
    {
        word = word + str[start];

        if(dictionary.find(word) != dictionary.end())
        {
            string temp = wordBreak + (wordBreak==""?"":" ") + word;
            printWordBreak(str, dictionary, start+1, temp);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    unordered_set<string> dictionary;
    
    for(int i=0; i<n; i++)
    {
        string input;
        cin>>input;
        dictionary.insert(input);
    }
    

    string str;
    cin>>str;
    
    printWordBreak(str, dictionary, 0, "");

    return 0;
}