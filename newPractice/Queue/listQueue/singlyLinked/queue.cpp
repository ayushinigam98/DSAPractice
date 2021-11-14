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

class queue
{
    private: 

    Node* front;
    Node* back;

    public:

    queue()
    {
        front = NULL;
        back = NULL;
    }

    void push(int key)
    {
        Node* node = new Node(key);
        
        if(front == NULL)
        {    
            front = node;
            back = node;
        }
        else
        {
            back->next = node;
            back = node;
        }
    }

    int pop()
    {
        if(front == NULL)
        {
            cout<<"empty";
            return -1;
        }
        else
        {
            int key = front->data;
            front = front->next;
            return key;
        }
    }

    int ontop()
    {
        if(front == NULL)
        {
            cout<<"empty";
            return -1;
        }
        else
        {
            return front->data;
        }
    }
};

int main()
{
    queue s;

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