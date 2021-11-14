#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    Node* parent;
    int data;
    bool locked;
    bool descendentLocked;

    Node(int d)
    {
        left = NULL;
        right = NULL;
        parent = NULL;
        data = d;
        locked = false;
        descendentLocked = false;
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

int ctoi(char ch)
{
    return (((int)ch) - ((int)'0'));
}

bool islocked(Node* node)
{
    return node->locked;
}

bool ancestorsLocked(Node* node)
{
    if(node == NULL)
        return false;
    else if(node->locked == true)
        return true;
    else
        return ancestorsLocked(node->parent);
}

void lockAncestors(Node* node, bool value)
{
    if(node == NULL)
        return;
    
    node->descendentLocked = value;
    lockAncestors(node->parent, value);
}

bool lock(Node* node)
{
    if(node->descendentLocked || ancestorsLocked(node))
    {
        return false;
    }
    else
    {
        node->locked = true;
        lockAncestors(node->parent, true);
        return true;   
    }
}

bool unlock(Node* node)
{
    if(node->locked)
    {
        lockAncestors(node->parent, false);
        return true;
    }    
    else
    {
        return false;
    }
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
            current->left->parent = current;
            q.push(current->left);
        }
        if(str[i+1] != 'N')
        {
            current->right = new Node(ctoi(str[i+1]));
            current->right->parent = current;
            q.push(current->right);
        }
    
    }

    print(root);

    return 0;
}