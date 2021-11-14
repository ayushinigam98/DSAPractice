#include <iostream>
#include <vector>

using namespace std;

void push(vector<int> &stack, int key)
{
    stack.push_back(key);
}

int pop(vector<int> &stack)
{
    if(stack.size())
    {
        int key = stack[stack.size() - 1];
        stack.pop_back();
        return key;
    }
    else
    {
        cout<<"empty";
    }
}

void top(vector<int> &stack)
{
    if(stack.size())
        cout<<stack[stack.size()-1]<<endl;
    else
        cout<<"empry"<<endl;
}

int main()
{
    vector<int> stack;

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
                push(stack, key);
                break;
            
            case 2:
                cout<<pop(stack);
                break;
            
            case 3:
                top(stack);
                break;
            
            default:
                break;
        }
    }

    return 0;
}