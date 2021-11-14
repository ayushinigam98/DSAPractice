#include <iostream>
#include <vector>

using namespace std;

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void push(int &front, int &back, int queue[], int key, int n)
{
    if(front == -1)
    {
        front = 0;
        back = 0;
        queue[front] = key;
    }
    else if((back+1)%n == front)
    {   
        cout<<"queue is full";
    }
    else if(back == n-1)
    {
        back = 0;
        queue[back] = key;
    }
    else
    {
        back++;
        queue[back] = key;
    }
}

int pop(int &front, int &back, int queue[], int n)
{
    int key = -1;

    if(front == -1)
    {
        cout<<"empty";
    }
    else 
    {
        key = queue[front];
        
        if(front == back)
        {    
            front = -1;
            back = -1;
        }
        else if(front == n-1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    return key;
}

int ontop(int front, int back, int queue[])
{
    if(front == -1)
    {
        cout<<"empty";
        return -1;
    }
    else
    {
        return queue[front];
    }
}

int main()
{
    int max = 5;
    int queue[max];
    int front = -1;
    int back = -1;

    while(true)
    {
        int choice;

        cout<<"1. push\n";
        cout<<"2. pop\n";
        cout<<"3. whats on top: ";

        cin>>choice;

        switch (choice)
        {
            case 1:
                int key;
                cin>>key;
                push(front, back, queue, key, max);
                break;
            
            case 2:
                cout<<pop(front, back, queue, max);
                break;
            
            case 3:
                cout<<ontop(front, back, queue);
                break;
            case 4:
                print(max, queue);
                break;

            default:
                break;
        }
        
        cout<<"\n---------\n";
    }

    return 0;
}