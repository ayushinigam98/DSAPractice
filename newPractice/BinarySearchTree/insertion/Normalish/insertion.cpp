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

Node* insert(Node* root, int key)
{
    Node* node = new Node(key);

    if(root == NULL)
        return node;
    
    Node* prev = NULL;
    Node* current = root;

    while(current != NULL)
    {
        prev = current;

        if(key < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

    }

    if(key < prev->data)
    {
        prev->left = node;
    }
    else
    {
        prev->right = node;
    }

    return root;
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

    int key;
    cin>>key;

    //inOrderWalk(root);
    root = insert(root, key);
    inOrderWalk(root);

    return 0;
}




