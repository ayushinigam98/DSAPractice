#include <iostream>

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

Node* removeKFromEnd(Node* root, int k)
{
    Node* kNode = root;
    Node* node = root;
    int nodeIndex = 1;
    
    while(node != NULL)
    {
        if(nodeIndex > (k+1))
        {
            kNode = kNode->next;
        }

        node = node->next;
        nodeIndex++;
    }

    if(kNode == root)
        root = root->next;
    else
    {
        kNode->next = kNode->next->next;
    }

    return root;
}

void print(Node* root)
{
    while(root != NULL)
    {
        cout<<root->data<<" ";
        root = root->next;
    }

    cout<<endl;
}

int main()
{
    int n, k;
    
    //number of nodes
    cin>>n;

    int val;
    
    //the value of node
    cin>>val;
    Node* root = new Node(val);
    Node* node = root; 
    
    for(int i=1; i<n; i++)
    {
        //value of ith node
        cin>>val;
        node->next = new Node(val);
        node = node->next;
    }

    //kth element from the end to remove
    cin>>k;

    print(removeKFromEnd(root, k));

    return 0;
}