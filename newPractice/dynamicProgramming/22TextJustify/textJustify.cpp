#include <iostream>
#include <math.h>
using namespace std;

void printLine(int n, int lineBreak[], string words[])
{
    if(n<=0)
        return;

    printLine(lineBreak[n]-1, lineBreak, words);

    for(int i=lineBreak[n]; i<=n; i++)
    {
        cout<<words[i-1]<<" ";
    }
    cout<<endl;
}

void textJustify(int n, string words[], int width)
{
    int spaceSquare[n+1];
    int lineBreak[n+1];
    //base case
    spaceSquare[0] = 0;
    lineBreak[0] = -1;
    //recursive case
    for(int i=1; i<=n; i++)
    {
        int characters = -1;
        spaceSquare[i] = width*width+1;
    
        for(int j=i; j>=1; j--)
        {
            characters += words[j-1].length() + 1;
    
            if(characters > width)
                break;

            if((spaceSquare[j-1] + pow(width-characters, 2)) < spaceSquare[i])
            {
                spaceSquare[i] = spaceSquare[j-1] + pow(width-characters, 2);
                lineBreak[i] = j;
            } 
        }
    }

    printLine(n, lineBreak, words);
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

    int width;
    cin>>width;

    textJustify(n, words, width);

    return 0;
}