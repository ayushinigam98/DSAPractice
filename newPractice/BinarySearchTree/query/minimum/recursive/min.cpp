#include <iostream>
#include <climits>
#include <queue>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int data;

    Node()
    {

    }

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void inOrderWalk(Node* node)
{
    if(node == NULL)
        return ;
    
    inOrderWalk(node->left);
    cout<<node->data<<" ";
    inOrderWalk(node->right);
    
}

int minimum(Node* root)
{
    if(root->left == NULL)
        return root->data;
    else
        return minimum(root->left);
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    Node* root = new Node(arr[0]);
    
    queue<Node*> q;
    q.push(root);
    
    Node* node;

    for(int i=1; i<n; i+=2)
    {
        node = q.front();
        q.pop();

        if(arr[i] != 1000)
        {
            node->left = new Node(arr[i]);
            q.push(node->left);
        } 

        if(arr[i+1] != 1000)
        {
            node->right = new Node(arr[i+1]);
            q.push(node->right);
        }
    }

    cout<<minimum(root);
    
    return 0;
}

