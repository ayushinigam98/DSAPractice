#include <iostream>

using namespace std;

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void merge(int na, int nb, int A[], int B[])
{
    int C[na+nb];

    int ia = 0;
    int ib = 0;
    int k = 0;

    while(ia<na && ib<nb)
    {
        if(A[ia] < B[ib])
        {
            C[k++] = A[ia++]; 
        }
        else
        {
            C[k++] = B[ib++];
        }
    }

    while (ia<na)
    {
        C[k++] = A[ia++];
    }

    while(ib<nb)
    {
        C[k++] = B[ib++];
    }

    print(na+nb, C);
    
}

int main()
{
    int na, nb;
    
    cin>>na;

    int A[na];
    for(int i=0; i<na; i++)
    {
        cin>>A[i];
    }
    
    cin>>nb;

    int B[nb];
    for(int i=0; i<nb; i++)
    {
        cin>>B[i];
    }

    merge(na, nb, A, B);

    return 0;
}   