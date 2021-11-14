#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class stack
{
    private: 

    queue<int> q1;
    queue<int> q2;
    

    public:

    stack()
    {
        
    }

    void push(int key)
    {
        q1.push(key);
    }

    int pop()
    {
        int key = -1;

        while(!q1.empty())
        {
            key = q1.front();
            
            if(q1.size() != 1)
            {
                q2.push(key);
            }

            q1.pop();
        }

        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }

        return key;
    }
};

int main()
{
    stack s;

    while(true)
    {
        int choice;

        cout<<"1. push\n";
        cout<<"2. pop\n";
        cin>>choice;

        switch (choice)
        {
            case 1:
                int key;
                cout<<"key: ";
                cin>>key;
                s.push(key);
                break;
            
            case 2:
                cout<<s.pop();;
                break;
                   
            default:
                break;
        }

        cout<<"\n------\n";
    }

    return 0;
}