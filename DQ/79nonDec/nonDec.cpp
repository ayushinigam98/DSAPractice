#include <iostream>
#include <climits>

using namespace std;

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool possible(int n, int arr[])
{
    if(n == 1)
        return true;

    int prev = INT_MIN;
    int modified = 0;

    for(int i=0; i<n-1; i++)
    {
        if(prev < arr[i] && arr[i] > arr[i+1] && arr[i+1] > prev)
        {
            arr[i] = (prev + arr[i+1])/2;
            cout<<"here: "<<i<<endl;;
            modified++;
            print(n, arr);
        }
        else if(prev > arr[i] && arr[i] < arr[i+1] && arr[i+1] > prev)
        {
            arr[i] = (prev + arr[i+1])/2;
            modified++;
            cout<<"here: "<<i<<"*";
            print(n, arr);
        }

        prev = arr[i];
    }

    if(arr[n-1] < arr[n-2])
    {
        arr[n-1] = arr[n-2] +1;
        modified++;
    }

    for(int i=1; i<n; i++)
    {
        if(arr[i] < arr[i-1])
            return false;
    }

    if(modified > 1)
        return false;
    cout<<endl;
    return true;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<possible(n, arr);

    return 0;
}