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

pair<int, int> deepestNode(Node* root, int pd)
{
    if(root == NULL)
        return make_pair(pd, 0);
    
    auto [leftdata, lefth] = deepestNode(root->left, root->data);
    auto [rightdata, righth] = deepestNode(root->right, root->data);

    if(lefth > righth)
    {
        return make_pair(leftdata, lefth+1);
    }
    else
    {
        return make_pair(rightdata, righth+1);
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

    //inOrderWalk(root);
    auto [data, height] = deepestNode(root, root->data);
    //inOrderWalk(root);
    cout<<data<<" "<<height;

    return 0;
}




