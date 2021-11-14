#include <iostream>

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

int largestPathToLeaf(struct Node* node, int &maxDiameter)
{
    if(node == NULL)
        return 0;
    
    int left = largestPathToLeaf(node->left, maxDiameter);
    int right = largestPathToLeaf(node->right, maxDiameter);
    
    maxDiameter = max(maxDiameter, 1+left+right);
    
    return (1 + max(left, right));
}

int diameter(Node* root)
{
    int maxDiameter = 0;

    largestPathToLeaf(root, maxDiameter);
}

int main()
{


    return 0;
}