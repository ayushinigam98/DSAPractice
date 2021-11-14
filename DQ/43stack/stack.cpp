#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Stack
{
    private:
    Node* top;
    int largest;

    public:

    Stack()
    {
        largest = INT_MIN;
        top = NULL;
    }

    void push(int value)
    {
        if(top == NULL)
        {
            largest = value;
        }
        else if(value > largest)
        {
            int temp = largest;
            largest = value;
            value = 2*value - temp;
        }

        Node* node = new Node(value);
        node->next = top;
        top = node;
    }

    int pop()
    {
        int poped = -1;
        
        if(top != NULL)
        {
            poped = top->data;
            top = top->next;
        }

        if(poped > largest)
        {
            int temp = largest;
            largest = 2*largest - poped;
            poped = temp;
        }

        return poped;
    }

    int max()
    {
        return largest;
    }

};



int main()
{
    Stack stack;
    int choice;

    while(true)
    {
        cout<<"-----------------\n";
        cout<<"1. push\n";
        cout<<"2. pop\n";
        cout<<"3. max\n";
        cout<<"-----------------\n";

        cin>>choice;

        switch (choice)
        {
            case 1:
                int value;
                cin>>value;
                stack.push(value);
                cout<<endl;
                break;
            case 2:
                cout<<stack.pop();
                cout<<endl;
                break;
            case 3:
                cout<<stack.max();
                cout<<endl;
                break;
            default:
                break;
        }
    }

    return 0;
}