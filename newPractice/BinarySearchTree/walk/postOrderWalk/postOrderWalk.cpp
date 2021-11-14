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

void postOrderWalk(Node* node)
{
    if(node == NULL)
        return ;
    
    postOrderWalk(node->left);
    postOrderWalk(node->right);
    cout<<node->data<<" ";
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

    postOrderWalk(root);

    return 0;
}




