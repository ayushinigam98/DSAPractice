#include <iostream>

using namespace std;

void printSpaces(int n)
{
    for(int i=0; i<n; i++)
        cout<<"| ";
    cout<<"|";
}

void printWords(string words[], int start, int end, int spaces, int leftExtraSpaces)
{
    if(start == end)
    {
        cout<<words[start];
        printSpaces(leftExtraSpaces);
        cout<<endl;
        return;
    }

    for(int i=start; i<=end; i++)
    {
        cout<<words[i];
        
        if(i != end)
            printSpaces(spaces + (i==start?leftExtraSpaces:0));
    }

    cout<<endl;
}

void justifyText(int n, string words[], int k)
{
    int spaces = words[0].length();
    int start = 0;


    for(int i=1; i<n; i++)
    {
        spaces = spaces + words[i].length() + 1;
        cout<<words[i];
        if(spaces > k)
        {
            spaces = spaces - words[i].length() - 1;
            if(start == (i-1))
                printWords(words, start, i-1, 0, k-spaces);
            else
                printWords(words, start, i-1, 1 + (k-spaces)/(i-1-start), (k-spaces)%(i-1-start));
            
            start = i;
            spaces = words[i].length();
        }
        
        if (i == (n-1))
        {
            if(start == i)
                printWords(words, start, i, 0, k-spaces);
            else
                printWords(words, start, i, 1+(k-spaces)/(i-start), (k-spaces)%(i-start));
        }
    }
}


int main()
{
    int n;
    cin>>n;
    
    string words[n];
    
    for(int i=0; i<n; i++)
    {
        cin>>words[i];
    }

    int k;
    cin>>k;

    justifyText(n, words, k);

    return 0;
}