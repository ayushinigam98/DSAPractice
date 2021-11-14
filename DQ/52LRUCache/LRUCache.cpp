#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int key;
    int value;

    Node* next;
    Node* prev;

    Node(int k, int v)
    {
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
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

    Node* getTop()
    {
       return tail; 
    }

    void add(int key, int value)
    {
        Node* node = new Node(key, value);

        if(head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        }

    }

    int removeOldest()
    {
        int key = -1;

        if(head != NULL)
        {
            key = head->key;  
            if(head->next != NULL)
                head->next->prev = NULL;  
            head = head->next;
        }

        return key;
    }

    void placeAtFront(Node* node)
    {
        if(node->next != NULL)
            node->next->prev = node->prev;
        else
            tail = node->prev;

        if(node->prev != NULL)
            node->prev->next = node->next;
        else    
            return; //because its already at the head
        
        node->next = head;
        node->prev = NULL;
        if(head != NULL)
            head->prev = node;
        head = node;
    }

    void print()
    {
        Node* node = head;

        while(node != NULL)
        {
            cout<<node->key<<" "<<node->value<<"|";
            node = node->next;
        }
    }

};

class LRUCache
{
    private:
    LinkedList list;
    unordered_map<int, Node*> map;
    int size;

    public:
    LRUCache()
    {
        size = 0;
    }

    void set(int key, int value)
    {
        list.add(key, value);
        map[key] = list.getTop();
        size++;

        if(size >= 5)
        {
            int removeKey = list.removeOldest();
            map.erase(removeKey);
            size--;
        }

        list.print();
    }

    int get(int key)
    {
        if(map.find(key) != map.end())
        {
            Node* node = map.find(key)->second;
            list.placeAtFront(node);
            return node->key;
        } 
        else
        {
            return -1;
        }
    }

    void print()
    {
        list.print();
    }
    
};

int main()
{
    LRUCache lRUCache;

    while(true)
    {
        int choice;
        int key, value;
        cout<<"\n--------------------\n";
        cout<<"1. get"<<endl;
        cout<<"2. set"<<endl;

        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"key: ";
                cin>>key;
                cout<<"value: ";
                cout<<lRUCache.get(key);
                cout<<endl;
                break;
            
            case 2:
                
                cout<<"key: ";
                cin>>key;
                cout<<"value: ";
                cin>>value;

                lRUCache.set(key, value);

                break;
            
            case 3:
                lRUCache.print();
                break;

            default:
                break;
        }
    }


    return 0;
}