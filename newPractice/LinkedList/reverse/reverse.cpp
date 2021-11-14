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

void print(Node* node)
{
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

Node* reverse(Node* root)
{
    Node* prev = NULL;
    Node* current = root;
    Node* nextNode = root->next;

    while(current != NULL)
    {
        current->next = prev;
        prev = current;
        current = nextNode;
        if(nextNode != NULL)
            nextNode = nextNode->next;
    }

    return prev;
}

Node* otherReverse(Node* root)
{
    if(root == NULL)
        return root;

    Node* prev  = root;
    Node* current = root->next;

    prev->next = NULL;

    while(current != NULL)
    {
        Node* temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    } 

    return prev;
}

int main()
{
    int n;
    cin>>n;

    int x;
    cin>>x;

    Node* root = new Node(x);
    Node* current = root;

    for(int i=1; i<n; i++)
    {
        cin>>x;
        current->next = new Node(x);
        current = current->next;
    }    
    print(root);
    root = otherReverse(root);
    print(root);

    return 0;
}
