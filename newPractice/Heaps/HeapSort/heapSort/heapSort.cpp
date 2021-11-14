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

    if(left < heapLenght && heap[left] > heap[largest])
    {
        largest = left;
    }

    if(right < heapLenght && heap[right] > heap[largest])
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
    }
}

void sort(int n, int arr[])
{
    buildHeap(n, arr);
    int heapLenght = n;
    for(int i=n-1; i>=1; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapLenght--;

        heapify(0, arr, heapLenght);
    }
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

    sort(n, arr);
    print(n, arr);

    return 0;
}