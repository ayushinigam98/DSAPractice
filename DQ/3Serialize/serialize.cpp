#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> serialize(Node *root) 
    {
        //Your code here
        if(root == NULL)
        {
            return vector<int>();
        }
        
        queue<Node*> q;
        vector<int> ser;
        
        q.push(root);
        ser.push_back(root->data);
        
        while(!q.empty())
        {
            Node* n = q.front();
            q.pop();
            
            if(n->left != NULL)
            {
                ser.push_back(n->left->data);
                q.push(n->left);
            }
            else
            {
                ser.push_back(-1);
            }
            
            if(n->right != NULL)
            {
                ser.push_back(n->right->data);
                q.push(n->right);
            }
            else
            {
                ser.push_back(-1);
            }
        }
        
        return ser;
        
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       if(A.size() == 0)
        return NULL;
        
       queue<Node*> q;
       
       Node* root = new Node(A[0]);
       q.push(root);
       
       for(int i=1; i<A.size(); i = i+2)
       {
           Node* n = q.front();
           q.pop();
           
           if(A[i] != -1)
           {
               n->left = new Node(A[i]);
               q.push(n->left);
           }
           else
           {
               n->left = NULL;
           }
           
           if(A[i+1] != -1)
           {
              n->right = new Node(A[i+1]);
              q.push(n->right);
           }
           else
           {
               n->right = NULL;
           }
       }
       
       return root;
       
    }

int main()
{
    int n;
    cin>>n;

    //the serialized array is the nodes line by line. if there is no node existing at a certain location then place -1;
    vector<int> ser;

    for(int i=0; i<n; i++)
    {
        cin>>ser[i];       
    }

    Node* root = deSerialize(ser);
    vector<int> serialized = serialize(root);

    for(int i=0; i<n; i++)
    {
        if(serialized[i] != ser[i])
            cout<<"failed";
    }

    
}