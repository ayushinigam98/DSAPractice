#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node()
    {

    }

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node* reverse(Node* head)
{
    Node* prev = NULL;
    Node* current = head;
    Node* next = head->next;

    while(current)
    {
        current->next = prev;
        prev = current;
        current = next;
        next = current?current->next:NULL;
    }

    return prev;
}

void print(Node* head)
{
    Node* node = head;

    while(node)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
}

int main()
{

    int n;
    cin>>n;

    Node* head = new Node(-1);

    Node* current = head;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;

        current->next = new Node(temp);
        current = current->next;
    }

    head = head->next;
    //print(head);
    print(reverse(head));

    return 0;
}