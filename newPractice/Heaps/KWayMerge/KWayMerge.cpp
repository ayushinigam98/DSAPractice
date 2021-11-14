#include <iostream>
#include <climits>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node()
    {

    }

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

int parent(int i)
{
    return (i-1)/2;
}

int leftChild(int i)
{
    return (2*i + 1);
}

int rightChild(int i)
{
    return (2*i + 2);
}

void heapify(Node* lists[], int i, int heapSize)
{
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if(left < heapSize && lists[left]->data < lists[smallest]->data)
        smallest = left;
    
    if(right < heapSize && lists[right]->data < lists[smallest]->data)
        smallest = right;

    if(smallest != i)
    {
        Node* temp = lists[i];
        lists[i] = lists[smallest];
        lists[smallest] = temp;

        heapify(lists, smallest, heapSize);
    } 
}

void buildHeap(Node* lists[], int k)
{
    for(int i = parent(k-1); i>=0; i--)
    {
        heapify(lists, i, k);
    }
}

int extractMin(Node* lists[], int k)
{
    int minimum = lists[0]->data;

    lists[0] = lists[0]->next;
    heapify(lists, 0, k);

    return minimum;
}

void merge(Node* lists[], int k, int nEl)
{
    buildHeap(lists, k);

    while(nEl--)
    {
        cout<<extractMin(lists, k)<<" ";
    }
}

int main()
{
    int k;
    cin>>k;
    
    int nEl = 0;

    Node* lists[k];

    for(int i=0; i<k; i++)
    {
        int n;
        cin>>n;
        
        int x;
        cin>>x;
        
        lists[i] = new Node(x);
        Node* temp = lists[i];
        
        for(int j=1; j<n; j++)
        {
            cin>>x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        temp->next = new Node(INT_MAX);

        nEl += n;
    }

    merge(lists, k, nEl);
}