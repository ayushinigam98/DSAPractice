#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL; 
    }
};

void printInOrder(Node* root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    printInOrder(root->left);
    printInOrder(root->right);
}   
/*
int wrong_numOfUnival(Node* node, int &num)
{
    if(node->left == NULL && node->right == NULL)
    {
        num++;
        return node->data;
    }
    
    int leftVal = numOfUnival(node->left, num);
    int rightVal = numOfUnival(node->right, num);

    if(leftVal == node->data && rightVal == node->data)
    {
        num++;
        return node->data;
    }

    return -1;
}
*/
int numOfUnival(Node* node, int &num)
{   
    int leftVal = (node->left)?numOfUnival(node->left, num):node->data;
    int rightVal = (node->right)?numOfUnival(node->right, num):node->data;

    if(leftVal == node->data && rightVal == node->data)
    {
        num++;
        return node->data;
    }

    return -1;
}

int main()
{
    //assumption: the array being passed has atleast one node, and is given in the proper format
    //format: nodes listed line by line and -1 if null

    //initializing tree
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

    for(int i=1; i<n; i = i+2)
    {
        Node* n = q.front();
        q.pop();

        if(arr[i] != -1)
        {
            n->left = new Node(arr[i]);
            q.push(n->left);
        }
        if(arr[i+1] != -1)
        {
            n->right = new Node(arr[i+1]);
            q.push(n->right);
        }
    }
    //initialized tree

    //printInOrder(root);
    //cout<<"-----"<<endl;
    int num = 0;
    numOfUnival(root, num);
    cout<<num<<endl;

    return 0;
}