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

void print(Node* node)
{
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }

    cout<<endl;
}

int leftChild(int i)
{
    return 2*i + 1;
}

int rightChild(int i)
{
    return 2*i + 2;
}

int parent(int i)
{
    return (i-1)/2;
}

void minHeapify(Node* heap[], int i, int heapLenght)
{
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if(left < heapLenght && heap[left]->data < heap[smallest]->data)
    {
        smallest = left;
    }

    if(right < heapLenght && heap[right]->data < heap[smallest]->data)
    {
        smallest = right;
    }

    if(i != smallest)
    {
        Node* temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        minHeapify(heap, smallest, heapLenght);
    }
}

void buildMinHeap(Node* heap[], int k)
{
    for(int i = parent(k-1); i>=0; i--)
    {
        minHeapify(heap, i, k);
    }
}

Node* extractMin(Node* heap[], int k)
{
    Node* small = heap[0];
    
    heap[0] = heap[0]->next;
    minHeapify(heap, 0, k);

    return small;
}

Node* merge(Node* heap[], int k, int n)
{
    buildMinHeap(heap, k);
    
    Node* root = new Node();
    Node* start = root;
    while(n--)
    {
        start->next = extractMin(heap, k);
        cout<<start->next->data<<"*";
        start = start->next;
    }

    return root->next;
}

int main()
{
    int k;
    cin>>k;

    Node* heap[k];
    int n = 0;

    for(int i=0; i<k; i++)
    {
        int listlen;
        cin>>listlen;
        
        int x;
        cin>>x;
        
        Node* node = new Node(x);
        heap[i] = node;
        n++;
        for(int i=1; i<listlen; i++)
        {
            cin>>x;
            node->next = new Node(x);
            node = node->next;
            n++;
        }

        node->next = new Node(INT_MAX);
    }

    Node* start = merge(heap, k, n);

    print(start);

    return 0;
}