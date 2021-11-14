#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void print(int n, vector<int> &arr)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int parent(int i)
{
    return (i-1)/2;
}

int left(int i)
{
    return 2*i + 1;
}

int right(int i)
{
    return 2*i + 2;
}

void heapify(vector<int> &heap, int i, int heapLenght)
{
    int largest = i;
    int leftChild = left(i);
    int rightChild = right(i);

    if(leftChild < heapLenght && heap[largest] < heap[leftChild])
    {
        largest = leftChild;
    }
    if(rightChild < heapLenght && heap[largest] < heap[rightChild])
    {
        largest = rightChild;
    }

    if(largest != i)
    {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        heapify(heap, largest, heapLenght);
    }
}

int maxKey(vector<int> q, int heapSize)
{
    if(heapSize)
    {
        return q[0];
    }

    return -1;
}

int extractMaxKey(vector<int> &q, int &heapSize)
{
    int largest;

    if(heapSize)
        largest = q[0];
    else 
        return -1;
    
    q[0] = q[heapSize-1];
    heapSize--;

    heapify(q, 0, heapSize);

    return largest;
}

void increaseKey(vector<int> &q, int i, int key)
{
    if(q[i] > key)
        return;
    
    while(i > 0 && key > q[parent(i)])
    {
        q[i] = q[parent(i)];
        i = parent(i);
    }
    q[i] = key;
}

void insert(vector<int> &q, int key, int &heapSize)
{
    heapSize++;
    if(q.size() >= heapSize)
        q[heapSize-1] = INT_MIN;
    else
        q.push_back(INT_MIN);

    increaseKey(q, heapSize-1, key);
}

int main()
{
    vector<int> q;
    int heapSize = 0;

    while(true)
    {
        cout<<"\n-------\n1. insert\n";
        cout<<"2. extract max key\n";
        cout<<"3. print max key\n";
        cout<<"4. increase a key\n";
        cout<<"5. print the priority queue\n--------\n";

        int choice;
        int key;
        cin>>choice;

        switch (choice)
        {
            case 1:
                cout<<"key to insert: ";   
                cin>>key;
                insert(q, key, heapSize);
                break;
            case 2:
                key = extractMaxKey(q, heapSize);
                cout<<key;
                break;
            case 3:
                key = maxKey(q, heapSize);
                cout<<key;
                break;
            case 4:
                cout<<"which key to increase: ";
                int i;
                cin>>i;
                cout<<"what value: ";
                cin>>key;
                increaseKey(q, i, key);
                break;
            case 5:
                print(heapSize, q);
                break;
            
            default:
                break;
        }
    }

    return 0;
}