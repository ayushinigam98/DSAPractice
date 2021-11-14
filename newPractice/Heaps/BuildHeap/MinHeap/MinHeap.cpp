#include <iostream>

using namespace std;

int parent(int i)
{
    return (i-1)/2;
}

int leftChild(int i)
{
    return 2*i + 1;
}

int rightChild(int i)
{
    return 2*i + 2;
}

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void heapify(int i, int heap[], int heapLenght)
{
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if(left < heapLenght && heap[left] < heap[largest])
    {
        largest = left;
    }

    if(right < heapLenght && heap[largest] <  heap[largest])
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
    for(int i=parent(n-1); i>=0; i--)
    {
        heapify(i, arr, n);
        print(n, arr);
    }

    print(n, arr);
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

    return 0;
}