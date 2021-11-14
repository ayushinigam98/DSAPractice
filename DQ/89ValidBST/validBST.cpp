#include <iostream>
#include <climits>
#include <queue>
#include <climits>
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

struct TreeInfo
{
    bool isBST;
    int maxNode;
    int minNode;

    TreeInfo()
    {

    }

    TreeInfo(int is, int maximum, int minimum)
    {
        isBST = is;
        maxNode = maximum;
        minNode = minimum;
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

TreeInfo* validBST(Node* root, int pd)
{
    if(root == NULL)
    {
        return new TreeInfo(true, pd, pd);
    }    

    TreeInfo* left = validBST(root->left, root->data);
    TreeInfo* right = validBST(root->right, root->data);

    if(left->isBST && right->isBST && left->maxNode <= root->data && root->data <= right->minNode)
    {
        return new TreeInfo(true, right->maxNode, left->minNode);
    }
    else 
    {
        return new TreeInfo(false, 0, 0);
    }
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

    inOrderWalk(root);
    TreeInfo* treeInfo = validBST(root, root->data);
    cout<<"|| "<<treeInfo->isBST<<" ";
    return 0;
}




