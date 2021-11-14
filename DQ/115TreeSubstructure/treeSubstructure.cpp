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

Node* takeInputTree()
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

    return root;
}

bool sameStructure(Node* node1, Node* node2)
{
    if(node1 == NULL || node2 == NULL)
    {
        return (!node1 && !node2);
    }

    if(!sameStructure(node1->left, node2->left))
        return false;
    
    if(!sameStructure(node2->right, node2->right))
        return false;
    
    return true;
}

bool sameSubstructure(Node* mainTree, Node* node)
{
    if(mainTree == NULL)
        return false;
    
    if(sameStructure(mainTree, node))
        return true;
    
    if(sameSubstructure(mainTree->left, node))
        return true;
    
    if(sameSubstructure(mainTree->right, node))
        return true;

    return false;
}

int main()
{
    Node* root1 = takeInputTree();
    Node* root2 = takeInputTree();

    // inOrderWalk(root1);
    // cout<<endl;
    // inOrderWalk(root2);

    cout<<sameSubstructure(root1, root2);    

    return 0;
}




