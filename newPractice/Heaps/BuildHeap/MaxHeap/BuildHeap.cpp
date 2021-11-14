#include <iostream>

using namespace std;

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

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

void heapify(int i, int heap[], int heapLenght)
{
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);
    
    if(left < heapLenght && heap[largest] < heap[left])
    {
        largest = left;
    }
    if(right < heapLenght && heap[largest] < heap[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(largest, heap, heapLenght);
    }
}

void buildHeap(int n, int arr[])
{
    for(int i = parent(n-1); i>=0; i--)
    {
        heapify(i, arr, n);
        print(n, arr);
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    buildHeap(n, arr);

    print(n, arr);

    return 0;
}