#include <iostream>
#include <string>

using namespace std;



void printPowerSet(int i, int n, int arr[], string str)
{
    if(i == n)
    {
        cout<<((str == "")?"{":", {")<<str<<"}";
        return;
    }

    printPowerSet(i+1, n, arr, str);
    printPowerSet(i+1, n, arr, str + ((str == "")?"":", ") + to_string(arr[i]));
    
}

void printPowerSetInOrder(int i, int n, int arr[], string str, int npr)
{
    if(i == n)
    {
        if(npr == 0)
            cout<<((str == "")?"{":", {")<<str<<"}";
        return;       
    }

    printPowerSetInOrder(i+1, n, arr, str, npr);

    if(npr > 0)
    {
        printPowerSetInOrder(i+1, n, arr, str + ((str == "")?"":", ") + to_string(arr[i]), npr-1);
    }
}

void printInOrder(int n, int arr[])
{
    cout<<"{ ";
    for(int i=0; i<n; i++)
    {
        printPowerSetInOrder(0, n, arr, "", i);
    }
    cout<<" }";
}

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=n-1; i>=0; i--)
    {
        cin>>arr[i];
    }

    cout<<"{ ";
    printPowerSet(0, n, arr, "");
    cout<<"}"<<endl;

    printInOrder(n, arr);

    return 0;
}