#include <iostream>
#include <vector>

using namespace std;

void push(int &top, int stack[], int key, int max)
{
    if(top == max - 1)
    {
        cout<<"stack overflow";
    }
    else
    {
        top++;
        stack[top] = key;
    }
}

int pop(int &top, int stack[])
{
    if(top)
    {
        int key = stack[top];
        top--;
        return key;
    }
    else
    {
        cout<<"empty";
    }
}

void ontop(int top, int stack[])
{
    if(top)
    {
        cout<<stack[top];
    }
    else
    {
        cout<<"empty";
    }
}

int main()
{
    int max = 5;
    int stack[max];
    int top = 0;

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
                push(top, stack, key, max);
                break;
            
            case 2:
                cout<<pop(top, stack);
                break;
            
            case 3:
                ontop(top, stack);
                break;
            
            default:
                break;
        }
    }

    return 0;
}