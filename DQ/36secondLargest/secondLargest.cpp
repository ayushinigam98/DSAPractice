#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int data;

    Node(int d)
    {
        left = NULL;
        right = NULL;
        data = d;  
    }
};

void print(Node* node)
{
    if(node == NULL)
        return;

    cout<<node->data<<" ";
    print(node->left);
    print(node->right);
}

int secondLargest(Node* root)
{
    if(root == NULL)
        return -1;

    Node* node = root;
    Node* nodeParent = NULL;
    
    while(node->right != NULL)
    {
        nodeParent = node;
        node = node->right;
    }

    if(node->left != NULL)
        return node->left->data;
    else if(nodeParent != NULL)
        return nodeParent->data;
    else
        return -1;

}

int ctoi(char ch)
{
    return (((int)ch) - ((int)'0'));
}

int main()
{

    string str;
    cin>>str;

    queue<Node*> q;
    Node* root = new Node(ctoi(str[0])); 
    q.push(root);

    for(int i=1; i<str.length(); i = i+2)
    {
        Node* current = q.front();
        q.pop();
    
        if(str[i] != 'N')
        {
            current->left = new Node(ctoi(str[i]));
            q.push(current->left);
        }
        if(str[i+1] != 'N')
        {
            current->right = new Node(ctoi(str[i+1]));
            q.push(current->right);
        }
    
    }

    print(root);

    cout<<secondLargest(root);

    return 0;
}