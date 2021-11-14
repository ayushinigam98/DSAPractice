#include <iostream>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

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
    int min;
    int max;
    int numNodes;

    TreeInfo()
    {

    }

    TreeInfo(bool bst, int minimum, int maximum, int num)
    {
        isBST = bst;
        min = minimum;
        max = maximum;
        numNodes = num;
    }
};

void walk(Node* node)
{
    if(node == NULL)
    {
        return ;
    }

    cout<<node->data<<" ";
    walk(node->left);
    walk(node->right);
}

TreeInfo* largestBST(Node* node, int pData, int &largest)
{
    if(node == NULL)
    {
        return new TreeInfo(true, pData, pData, 0);
    }

    TreeInfo* leftTree = largestBST(node->left, node->data, largest);
    TreeInfo* rightTree = largestBST(node->right, node->data, largest);

    TreeInfo* treeInfo;
    if(leftTree->isBST && rightTree->isBST &&  leftTree->max <= node->data && node->data <= rightTree->min)
    {
        treeInfo = new TreeInfo(true, leftTree->min, rightTree->max, leftTree->numNodes + rightTree->numNodes + 1);
        largest = max(largest, treeInfo->numNodes);   
    }
    else
    {
        treeInfo = new TreeInfo(false, 0, 0, 0);
    }

    return treeInfo;
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
    
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    
    Node* current;

    for(int i=1; i<n; i +=2)
    {
        current = q.front();
        q.pop();

        if(arr[i] != -100)
        {
            current->left = new Node(arr[i]);
            q.push(current->left);
        }

        if(arr[i+1] != -100)
        {
            current->right = new Node(arr[i+1]);
            q.push(current->right);
        }
    }

    //walk(root);

    int largest = 0;
    largestBST(root, root->data, largest);
    cout<<largest;

    return 0;
}