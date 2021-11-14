#include <iostream>
#include <queue>
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

int maxPathToChildNode(Node* node, int &pathSum)
{
    if(node == NULL)
        return 0;

    int leftSum = maxPathToChildNode(node->left, pathSum);
    int rightSum = maxPathToChildNode(node->right, pathSum);
    cout<<leftSum<<" "<<rightSum<<" "<<node->data<<endl;
    pathSum = max(pathSum, node->data + leftSum + rightSum);

    return max(node->data, (node->data + max(leftSum, rightSum)));
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

    int pathSum = 0;
    maxPathToChildNode(root, pathSum);
    cout<<pathSum;

    return 0;
}