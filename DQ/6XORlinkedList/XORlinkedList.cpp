#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* prevNext;

    Node(int d)
    {
        data = d;
        prevNext = NULL;
    }
};

class linkedList
{
    private:
    Node* head;
    Node* tail;

    public:

    linkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void add(int element)
    {
       
        //create new element
        Node* node = new Node(element);

        if(head == NULL)
        {
            head = node;
            tail = node;
            node->prevNext = (Node*) ( (uintptr_t)(NULL) ^ (uintptr_t)(NULL) );
        }
        else
        {
            //get the previous of the tail
            Node* tailPrev = (Node*) ( (uintptr_t)(NULL) ^ ((uintptr_t)(tail->prevNext)) );

            //change the prevNext pointer of the current tail
            tail->prevNext = (Node*) ( (uintptr_t)(tailPrev) ^ (uintptr_t)(node) );

            //change the prevNext of the new node
            node->prevNext = (Node*) ( (uintptr_t)(tail) ^ (uintptr_t)(NULL) );

            //make the new element the new tail
            tail = node;
        }
    }

    Node* get(int index)
    {
        Node* node = head;
        Node* prev = NULL;
        while(--index)
        {
            Node* next = (Node*) ( (uintptr_t)(node->prevNext) ^ (uintptr_t)(prev) );
            prev = node;
            node = next;
        }

        return node;
    }

};

int main()
{
    linkedList list;

    while(true)
    {
        cout<<"---------------\n";
        cout<<"1. Add an element\n";
        cout<<"2. get an element\n";
        cout<<"press any key to leave\n";
        cout<<"------------------\n"; 

        int choice;
        cin>>choice;

        switch (choice)
        {
            case 1:
                cout<<"value of element: ";
                int val;
                cin>>val;
                list.add(val);
                cout<<"\nadded\n";
                break;
            case 2: 
                cout<<"index to get: ";
                int index;
                cin>>index;
                cout<<"\ngot it: "<<list.get(index)->data<<endl;
                break;
            
            default:
                break;
        }      
    }

    return 0;
}