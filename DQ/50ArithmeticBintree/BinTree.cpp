#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    Node* left;
    Node* right;

    char data;

    Node(char d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void printWalk(Node* node)
{
    if(node == NULL)
    {
        return ;
    }

    cout<<node->data<<" ";
    printWalk(node->left);
    printWalk(node->right);
}

float operate(char ch, float num1, float num2)
{
    if(ch == '+')
        return num1+num2;
    else if (ch == '-')
        return num1-num2;
    else if(ch == '*')
        return ((float)num1)*((float)num2);
    else
        return ((float)num1)/((float)num2);
}

float calculate(Node* node)
{
    if(node == NULL)
    {
        return 0; 
    }
    else if(node->left == NULL && node->right == NULL)
    {
        return (float)((int) node->data - (int) '0');
    }

    return operate(node->data, calculate(node->left), calculate(node->right));
}


int main()
{
    int n;
    cin>>n;
    char arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    queue<Node*> q;
    Node* head = new Node(arr[0]);
    q.push(head);
    Node* node;
    
    for(int i=1; i<n;i=i+2)
    {
        node = q.front();
        q.pop();


        if(arr[i] != '-')
        {
            node->left = new Node(arr[i]);
            q.push(node->left);
        }
        
        if(arr[i+1] != '-')
        {
            node->right = new Node(arr[i+1]);
            q.push(node->right);
        }
    }

    printWalk(head);
    cout<<endl;
    cout<<calculate(head)<<endl;
    return 0;
}