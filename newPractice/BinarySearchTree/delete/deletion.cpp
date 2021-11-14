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

Node* minimum(Node* node)
{
    if(node->left == NULL)
        return node;
    else
        return minimum(node->left);
}

Node* successor(Node* root, Node* x)
{
    if(x->right != NULL)
        return minimum(x->right);
    
    Node* succ = NULL;
    Node* current = root;
    //cout<<x->data<<"*";
    while(current != NULL && current->data != x->data)
    {
        //cout<<x->data<<" "<<current->data<<"|";
        if(x->data < current->data)
        {
            succ = current;
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return succ;
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

void inOrderWalk(Node* node)
{
    if(node == NULL)
        return ;
    
    inOrderWalk(node->left);
    cout<<node->data<<" ";
    inOrderWalk(node->right);
}

Node* transplant(Node* root, Node* parent, Node* child, Node* newChild)
{
    if(parent == NULL)
    {
        root = newChild;
    }
    else if(child->data < parent->data)
    {
        parent->left = newChild;
    }
    else
    {
        parent->right = newChild;
    }

    return root;
}

Node* deleteNode(Node* root, int key)
{
    Node* prev = NULL;
    Node* x = root;

    while(x != NULL && x->data != key)
    {
        prev = x;

        if(key < x->data)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    if(x->left == NULL)
    {
        root = transplant(root, prev, x, x->right);
    }
    else if(x->right == NULL)
    {
        root = transplant(root, prev, x, x->left);
    }
    else
    {
        Node* succ = successor(root, x);
        if(x->right != succ)
        {
            Node* temp = succ->right;
            succ->right = NULL;
            successor(root, succ)->left = temp;
            succ->right = x->right;   
        }
        succ->left = x->left;
        root = transplant(root, prev, x, succ);
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

    inOrderWalk(root);
    root = deleteNode(root, key);
    inOrderWalk(root);

    return 0;
}
