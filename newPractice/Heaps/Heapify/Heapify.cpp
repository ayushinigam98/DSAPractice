#include <iostream>

using namespace std;

void print(int n, int arr[])
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

void heapify(int heap[], int i, int heapLenght)
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

int main()
{
    int n;
    cin>>n;

    int heap[n];
    int heapLenght = n;
    for(int i=0; i<n; i++)
    {
        cin>>heap[i];
    }

    int index;
    cin>>index;

    heapify(heap, index, heapLenght);
    print(heapLenght, heap);

    return 0;
}