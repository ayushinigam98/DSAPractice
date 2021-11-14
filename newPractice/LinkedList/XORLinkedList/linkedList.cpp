#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* np;

    Node()
    {

    }

    Node(int d)
    {
        data = d;
        np = NULL;
    }
};

class LinkedList
{
    private:
    Node* head;
    Node* tail;

    public:
    
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void add(int key)
    {
        Node* node = new Node(key);

        if(head == NULL)
        {
            head = node;
            tail = node;

            node->np = (Node*) ((uintptr_t)(NULL) ^ (uintptr_t)(NULL));
        }
        else
        {
            node->np = (Node*) ((uintptr_t)(NULL) ^ (uintptr_t)(tail));

            tail->np = (Node*) (((uintptr_t)(tail->np) ^ (uintptr_t)(NULL)) ^ (uintptr_t)(node));

            tail = node;
        }
    }

    void deleteNode(int key)
    {
        Node* node = head;
        Node* prev = NULL;
        Node* nextNode;

        while(node != NULL && node->data != key)
        {
            nextNode = (Node*) ((uintptr_t)(node->np) ^ (uintptr_t)(prev));
            prev = node;
            node = nextNode; 
        }

        if(node == NULL)
        {
            cout<<"key not present";
        }
        else
        {
            nextNode = (Node*) ((uintptr_t)(node->np) ^ (uintptr_t)(prev));

            if(prev != NULL)
                prev->np = (Node*) ((uintptr_t)(prev->np) ^ (uintptr_t)(node) ^ (uintptr_t)(nextNode));
            
            if(nextNode != NULL)
                nextNode->np = (Node*) ((uintptr_t)(nextNode->np) ^ (uintptr_t)(node) ^ (uintptr_t)(prev));
        }
    }

    int search(int key)
    {
        Node* node = head;
        Node* prev = NULL;
        Node* nextNode;
        int index = 0;

        while(node != NULL && node->data != key)
        {
            nextNode = (Node*) ((uintptr_t)(node->np) ^ (uintptr_t)(prev));
            prev = node;
            node = nextNode;
            index++; 
        }

        if(node == NULL)
            return -1;
        else    
            return index;
    }

    void print()
    {
        Node* node = head;
        Node* prev = NULL;

        while(node != NULL)
        {
            cout<<node->data<<" ";
            
            Node* nextNode = (Node*) ((uintptr_t)(node->np) ^ (uintptr_t)(prev));
            prev = node;
            node = nextNode;
        }
        cout<<endl;
    }
};

int main()
{
    LinkedList list;

    while(true)
    {
        cout<<"---------------\n";
        cout<<"1. Add an element\n";
        cout<<"2. delete\n";
        cout<<"3. search an element\n";
        cout<<"4. print everything\n";
        cout<<"press any key to leave\n";
        cout<<"------------------\n"; 

        int choice;
        cin>>choice;
        int key;

        switch (choice)
        {
            case 1:
                cout<<"value of element: ";
                cin>>key;
                list.add(key);
                cout<<"\nadded\n";
                break;
            
            case 2: 
                cout<<"value of element: ";
                cin>>key;
                list.deleteNode(key);
                break;
            
            case 3:
                cout<<"value of element: ";
                cin>>key;
                cout<<"\nthe index: "<<list.search(key);
                break;
            
            case 4: 
                list.print();
                break;
            
            default:
                break;
        }
        cout<<"\n-------------\n";      
    }

    return 0;
}
