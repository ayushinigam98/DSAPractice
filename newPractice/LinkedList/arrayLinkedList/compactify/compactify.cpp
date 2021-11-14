#include <iostream>

using namespace std;

class LinkedList
{
    private:

    int *next;
    int *prev;
    int *key;
    int free;
    int Lhead;
    int Ltail;
    int len;
    int size;
    public:

    LinkedList()
    {

    }

    LinkedList(int n)
    {
        next = new int[n];
        prev = new int[n];
        key = new int[n];

        free = 0;
        Lhead = -1;
        Ltail = -1;
        for(int i=0; i<n; i++)
        {
            next[i] = i+1;
            key[i] = 0;
            prev[i] = i-1;
        }
        next[n-1] = -1;
        len = 0;
        size = n;
    }

    void add(int k)
    {  
        int temp = next[free];
        
        if(free == -1)
        {
            cout<<"no space";
            return;
        }
        len++;
        key[free] = k;

        if(Lhead == -1)
        {
            Lhead = free;
            Ltail = free;

            next[free] = -1;
            prev[free] = -1;
        }
        else
        {
            next[free] = -1;
            prev[free] = Ltail;
            next[Ltail] = free;
            Ltail = free;
        }

        free = temp;
        prev[free] = -1;
    }

    void deleteNode(int x)
    {
        if(Lhead == -1)
        {
            cout<<"its empty";
            return ;
        }

        int i;
        for(i=Lhead; i != -1 && x != key[i]; i = next[i]);

        if(i == -1)
        {
            cout<<"not present in list";
        }
        else
        {
            len--;
            if(prev[i] != -1)
            {
                next[prev[i]] = next[i];
            }
            else
            {
                Lhead = next[i];
            }

            if(next[i] != -1)
            {
                prev[next[i]] = prev[i];
            }
            else
            {
                Ltail = prev[i];
            }

            next[i] = free;
            if(free != -1)
                prev[free] = i;
            free = i;
            key[free] = -1;
        }
    
    }

    void compactify()
    {
        int li = Lhead, fi = free;
        int ln, lp, fn, fp;

        while(li != -1 && fi != -1)
        {
            for(; li<len && li != -1; li = next[li]);
            for(; fi>=len && fi != -1; fi = next[fi]);

            int templ = li == -1?-1:next[li];
            int tempf = fi == -1?-1:next[fi];

            if(li != -1 && fi != -1)
            {
                key[fi] = key[li];
                key[li] = -1;

                ln = next[li];
                lp = prev[li];
                fn = next[fi];
                fp = prev[fi];
                
                if(lp != -1)
                    next[lp] = fi;
                if(ln != -1)
                    prev[ln] = fi;
                if(fp != -1)
                    next[fp] = li;
                if(fn != -1)
                    prev[fn] = li;
                
                next[li] = fn;
                prev[li] = fp;
                next[fi] = ln;
                prev[fi] = lp;

                if(fi == free)
                {
                    free = li;
                }

                li = templ;
                fi = tempf;
            }
        }
    }

    void print()
    {
        for(int i=Lhead; i != -1; i = next[i])
        {
            cout<<"("<<next[i]<<","<<i<<","<<prev[i]<<")"<<key[i]<<" | ";
        }
        cout<<endl;

        for(int i=free; i != -1; i = next[i])
        {
            cout<<"("<<next[i]<<","<<i<<","<<prev[i]<<")"<<key[i]<<" | ";
        }
        cout<<endl;
        //plainPrint();
    }

    void plainPrint()
    {
        for(int i=0; i<size; i++)
        {
            cout<<next[i]<<" ";
        }
        cout<<endl;
        for(int i=0; i<size; i++)
        {
            cout<<key[i]<<" ";
        }
        cout<<endl;
        for(int i=0; i<size; i++)
        {
            cout<<prev[i]<<" ";
        }
        cout<<endl;
    }

};


int main()
{
    int n;
    cin>>n;
    LinkedList list(n);

    while(true)
    {
        cout<<"---------------\n";
        cout<<"1. Add an element\n";
        cout<<"2. delete\n";
        cout<<"3. print everything\n";
        cout<<"4. compactify\n";
        cout<<"------------------\n"; 

        int choice;
        cin>>choice;
        int key;

        switch (choice)
        {
            case 1:
                cout<<"enter key: ";
                cin>>key;
                list.add(key);           
                break;
            
            case 2: 
                cout<<"enter key: ";
                cin>>key;
                list.deleteNode(key);
                break;
            
            case 3:
                list.print();
                break;
            
            case 4:
                list.compactify();
                break;

            default:

                break;
        }
        cout<<"\n-------------\n";      
    }

    return 0;
}
