#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    private: 
    stack<int> s1;
    stack<int> s2;

    public:
    void enqueue(int element)
    {
        s1.push(element);
    }

    void transfer(stack<int> &stack1, stack<int> &stack2)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int dequeue()
    {
        int poped = -1;

        transfer(s1, s2);

        if(!s2.empty())
        {
            poped = s2.top();
            s2.pop();
        }

        transfer(s2, s1);

        return poped;
    }


};

int main()
{   

    Queue q;

    int choice;

    while(true)
    {
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cin>>choice;
        
        switch (choice)
        {
        case 1:
            int x;
            cin>>x;
            q.enqueue(x);
            cout<<endl;
            break;
        case 2:
            cout<<q.dequeue()<<endl;
            break;
        
        default:
            break;
        }
    }    

    return 0;
}