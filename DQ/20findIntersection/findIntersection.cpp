#include <iostream>

using namespace std;

struct Node
{
    Node* next;
    int value;

    Node(int v)
    {
        value = v;
        next = NULL;
    }
};

void printList(Node* root)
{
    while(root != NULL)
    {
        cout<<root->value<<" ";
        root = root->next;
    }
    cout<<endl;

}

int findLength(Node* root)
{
    int len = 0;

    while(root != NULL)
    {
        len++;
        root = root->next;
    }

    return len;
}

int intersection(Node* root1, Node* root2)
{
    int n1 = findLength(root1);
    int n2 = findLength(root2);

    if(n1 > n2)
        return intersection(root2, root1);
    
    for(int i=0; i<(n2-n1); i++)
        root2 = root2->next;

    while(root1 != NULL)
    {
        if(root1->value == root2->value)
            return root1->value;

        root1 = root1->next;
        root2 = root2->next;
    }

    return -1;
}

Node* initialize(int n)
{
    Node* root;
    Node* node;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;

        if(i==0)
        {
            root = new Node(x);
            node = root;
        }
        else
        {
            node->next = new Node(x);
            node = node->next;
        }
        
    }

    return root;
}

int main()
{
    int n1, n2;

    cin>>n1;
    Node* root1 = initialize(n1);

    cin>>n2;
    Node* root2 = initialize(n2);

    cout<<intersection(root1, root2);

    return 0;
}