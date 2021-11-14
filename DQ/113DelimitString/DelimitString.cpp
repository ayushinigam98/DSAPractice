#include <iostream>

using namespace std;

int numWords(string str)
{
    int space = 0;

    for(int i=0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
            space++;
    }

    return space+1;
}

string findWord(int &i, int change, string str)
{
    string word = "";

    for(; str[i] != ' ' && str[i] != '\0'; i+=change)
    {
        word = word + str[i];
    }

    i+=change;
    return word;
}

string reverse(string word)
{
    int i = 0; 
    int j = word.length() - 1;

    while(i<j)
    {
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
        i++;
        j--;
    }

    return word;
}

string delimit(string str)
{
    string rev1 = "";
    string rev2 = "";
    
    int n = numWords(str);
    
    int windex = 0;
    for(int i=0; i<n/2; i++)
    {
        rev1 = findWord(windex, 1, str) + rev1;
        
        if(i != n/2-1)
            rev1 = " " + rev1;      
    }
    
    windex = str.length() - 1;
    for(int i=0; i<n/2; i++)
    {
        rev2 = rev2 + reverse(findWord(windex, -1, str));
        if(i != n/2-1)
            rev2 = rev2 + " ";
    }

    cout<<rev1<<" "<<rev2<<endl;

    if(n % 2 == 1)
        return (rev2 + (rev2==""?"":" ") + reverse(findWord(windex, -1, str)) + (rev1==""?"":" ") + rev1);
    else
        return (rev2 + (rev2==""?"":" ") +  rev1);
}

int main()
{
    string str;

    getline(cin, str);
    //cout<<str;
    cout<<delimit(str);

    return 0;
}