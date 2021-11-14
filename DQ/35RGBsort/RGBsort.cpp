#include <iostream>

using namespace std;

void swap(int i, int j, char arr[])
{
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void print(int n, char arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void RGBsort(int n, char colors[])
{
    int r = -1, g, b = n;

    for(int g=0; g<b; g++)
    {
        if(colors[g] == 'R')
        {
            r++;
            swap(r, g, colors);
        }
        else if(colors[g] == 'B')
        {
            b--;
            swap(b, g, colors);
            g--;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    char colors[n];

    for(int i=0; i<n; i++)
    {
        cin>>colors[i];
    }

    RGBsort(n, colors);
    print(n, colors);

    return 0;
}