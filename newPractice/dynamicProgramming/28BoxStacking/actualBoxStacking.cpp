#include <iostream>
#include <algorithm>
using namespace std;

struct box
{
    int l;
    int b;
    int h;

    box()
    {
        
    }

    box(int lenght, int breadth, int height)
    {
        l = lenght;
        b = breadth;
        h = height;
    }
};

bool isBoxWithin(box b1, box b2)
{
    return (b1.l <= b2.l && b1.b <= b2.b) || (b1.l <= b2.b && b1.b <= b2.l);
}

bool sortHelp(box box1, box box2)
{
    return (box1.l*box1.b <= box2.l*box2.b);
}

void print(int n, box arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<"("<<arr[i].l<<","<<arr[i].b<<")"<<","<<arr[i].h<<")"<<endl;
    }
}

int boxStacking(int n, int l[], int b[], int h[])
{
    box boxes[3*n];

    for(int i=0, j=0; i<n; i++, j+=3)
    {
        boxes[j] = *(new box(l[i], b[i], h[i]));
        boxes[j+1] = *(new box(l[i], h[i], b[i]));
        boxes[j+2] = *(new box(h[i], b[i], l[i]));
    }
    
    print(3*n, boxes);

    sort(boxes, boxes + 3*n, sortHelp);

    print(3*n, boxes);

    int stacked[3*n];
    stacked[0] = boxes[0].h;

    int maximum = 0;

    for(int i=1; i<3*n; i++)
    {
        stacked[i] = boxes[i].h;

        for(int j=0; j<i; j++)
        {
            if(isBoxWithin(boxes[j], boxes[i]))
            {
                stacked[i] = max(stacked[i], boxes[i].h + stacked[j]);
            }
        }

        maximum = max(maximum, stacked[i]);
    }

    return maximum;

}

int main()
{
    int n;
    cin>>n;

    int l[n];
    int b[n];
    int h[n];

    for(int i=0; i<n; i++)
    {
        cin>>l[i];
        cin>>b[i];
        cin>>h[i];
    }

    cout<<boxStacking(n, l, b, h);

    return 0;
}
