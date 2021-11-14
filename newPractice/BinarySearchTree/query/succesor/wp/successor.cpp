#include <iostream>
#include <climits>
#include <queue>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    Node* p;
    int data;

    Node()
    {

    }

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
        p = NULL;
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

Node* minimum(Node* node)
{
    if(node->left == NULL)
        return node;
    else
        return minimum(node->left);
}

Node* successor(Node* root, int key)
{
    Node* x = search(root, key);

    if(x->right != NULL)
        return minimum(x->right);
    
    Node* succ = x->p;

    while(succ != NULL && succ->left != x)
    {
        x = succ;
        succ = succ->p; 
    }

    return succ;
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
            node->left->p = node;
            q.push(node->left);
        } 

        if(arr[i+1] != 1000)
        {
            node->right = new Node(arr[i+1]);
            node->right->p = node;
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

