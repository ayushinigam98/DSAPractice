#include <iostream>

using namespace std;

void print(int arr[], int n)
{
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void record(int id, int &head, int arr[], int N)
{
    if(head == -1)
    {
        head = 0;
        arr[head] = id;
    }
    else
    {
        head = (head+1)%N;
        arr[head] = id;
    }
}

int get_last(int i, int head, int arr[], int N)
{
    return arr[(head - (i-1) + N)%N];
}

int main()
{
    cout<<"max No. of elements in that can be stored: "<<endl;
    int N;
    cin>>N;
    int arr[N];
    int head = -1;

    int opt;
    bool loop = true;
    while(loop)
    {
        cout<<"---------"<<endl;
        cout<<"1. store record ID"<<endl;
        cout<<"2. get ith from the end record"<<endl;
        cout<<"3. leave"<<endl;
        cout<<"---------"<<endl;

        cin>>opt;

        switch (opt)
        {
            case 1:
                cout<<"get the id: ";
                int id;
                cin>>id;
                record(id, head, arr, N); 
                print(arr, N);               
                break;
            
            case 2:
                cout<<"get i: ";
                int i;
                cin>>i;
                cout<<get_last(i, head, arr, N)<<endl;                
                break;
            
            case 3:
                loop = false;                
                break;

            default:
                cout<<"unknown"<<endl;
        }
    }

    return 0;
}