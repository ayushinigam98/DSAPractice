#include <iostream>
#include <algorithm>
using namespace std;

struct job
{
    int id;
    int deadline;
    int profit;

    job()
    {

    }

    job(int i, int d, int p)
    {
        id = i;
        deadline = d;
        profit = p; 
    }
};

bool sortJobs(job job1, job job2)
{
    return job1.profit >= job2.profit;
}

int maxDeadline(int n, job jobs[])
{
    int maximum = 0;

    for(int i=0; i<n; i++)
    {
        if(jobs[i].deadline > maximum)
        {
            maximum = jobs[i].deadline;
        }
    }

    return maximum;
}

void printArr(int n, bool arr[])
{
    for(int i=0; i<n; i++)
    {
        arr[i] = false;
    }
}

int maxProfit(int n, job jobs[])
{
    sort(jobs, jobs+n, sortJobs);

    int nslots = maxDeadline(n, jobs);
    bool slots[nslots];
    printArr(n, slots);

    int globalProfit = 0;
    int k = 0;
    
    for(int i=0; i<n; i++)
    {
        for(int s=jobs[i].deadline-1; s>=0; s--)
        {
            if(!slots[i])
            {
                slots[i] = true;
                globalProfit += jobs[i].profit;
                k++;
            }
        }

    }    

    return globalProfit;
}

int main()
{
    int n;
    cin>>n;

    job jobs[n];

    for(int i=0; i<n; i++)
    {
        cin>>jobs[i].id;
        cin>>jobs[i].deadline;
        cin>>jobs[i].profit; 
    }

    cout<<maxProfit(n, jobs);

    return 0;
}