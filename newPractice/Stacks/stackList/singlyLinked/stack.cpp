#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    Node* next;
    int data;

    Node()
    {

    }

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class stack
{
    private: 

    Node* top;

    public:

    stack()
    {
        top = NULL;
    }

    void push(int key)
    {
        Node* node = new Node(key);
        
        if(top == NULL)
        {    
            top = node;
        }
        else
        {
            node->next = top;
            top = node;
        }
    }

    int pop()
    {
        if(top == NULL)
        {
            cout<<"empty";
            return -1;
        }
        else
        {
            int key = top->data;
            top = top->next;
            return key;
        }
    }

    int ontop()
    {
        if(top == NULL)
        {
            cout<<"empty";
            return -1;
        }
        else
        {
            return top->data;
        }
    }
};

int main()
{
    stack s;

    while(true)
    {
        int choice;

        cout<<"1. push\n";
        cout<<"2. pop\n";
        cout<<"3. whats on top\n ";

        cin>>choice;

        switch (choice)
        {
            case 1:
                int key;
                cout<<"key: ";
                cin>>key;
                s.push(key);
                break;
            
            case 2:
                cout<<s.pop();;
                break;
            
            case 3:
                cout<<s.ontop();;
                break;
            
            default:
                break;
        }

        cout<<"\n------\n";
    }

    return 0;
}