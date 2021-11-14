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

Node* search(Node* node, int key)
{
    if(node == NULL || node->data == key)
        return node;
    else if(key < node->data)
        return search(node->left, key);
    else
        return search(node->right, key);
}

Node* maximum(Node* node)
{
    if(node->right == NULL)
        return node;
    else
        return maximum(node->right);
}

Node* successor(Node* root, int key)
{
    Node* x = search(root, key);

    if(x->left != NULL)
        return maximum(x->left);
    
    Node* pred = NULL;

    while(root != NULL && root->data != key)
    {
        if(key < root->data)
        {
            root = root->left;
        }
        else
        {
            pred = root;
            root = root->right;
        }
    }

    return pred;
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

    Node* nodeAns = successor(root, key);

    if(nodeAns == NULL)
        cout<<"it is max"<<endl;
    else
        cout<<nodeAns->data;
        
    return 0;
}

