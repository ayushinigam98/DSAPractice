#include <iostream>

using namespace std;



struct Node
{
    Node* left;
    Node* right;

    char ch;

    Node(char c)
    {
        ch = c;
        left = NULL;
        right = NULL;
    }
};

Node* buildTreeHelper(char preOrder[], int &index, char inOrder[], int left, int right)
{
    //base case
    if(left>right)
    {
        return NULL;
    }
    
    //find the label of the root
    char root = preOrder[index];
    //create the root of this subtree
    Node* node = new Node(root);
    //increase the index by one
    index++;
    //search for the elements to be places to the left and right of the root
    for(int i=left; i<=right; i++)
    {
        if(root == inOrder[i])
        {
            node->left = buildTreeHelper(preOrder, index, inOrder, left, i-1);
            node->right = buildTreeHelper(preOrder, index, inOrder, i+1, right);
        }
    }

    return node;

}

Node* buildTree(int n, char preOrder[], char inOrder[])
{
    int index = 0;
    return buildTreeHelper(preOrder, index, inOrder, 0, n-1);
}

void preOrderWalk(Node* node)
{
    if(node == NULL)
    {
        return ;
    }
    
    cout<<node->ch<<" ";
    preOrderWalk(node->left);
    preOrderWalk(node->right);
}

void inOrderWalk(Node* node)
{
    if(node == NULL)
    {
        return ;
    }

    inOrderWalk(node->left);
    cout<<node->ch<<" ";
    inOrderWalk(node->right);
}

int main()
{ 
    int n;
    cin>>n;

    char preOrder[n];
    char inOrder[n];

    for(int i=0; i<n; i++)
    {
        cin>>preOrder[i];
    }

    for(int i=0; i<n; i++)
    {
        cin>>inOrder[i];
    }

    Node* root = buildTree(n, preOrder, inOrder);
    
    preOrderWalk(root);
    cout<<endl;
    inOrderWalk(root);

    return 0;
}