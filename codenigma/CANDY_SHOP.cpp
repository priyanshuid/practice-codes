#include <iostream>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
using namespace std;
int flag[10000];
struct tuple
{
    int credit;
    int arrival;
    int id;
};
bool operator<(const tuple &t1, const tuple &t2)
{
    if(t1.credit < t2.credit)
        return true;
    else if(t1.credit== t2.credit)
    {
        return t1.id< t2.id;
    }
}
bool compare(tuple t1, tuple t2)
{
    if(t1.arrival <t2.arrival)
            return true;
    else if(t1.arrival==t2.arrival)
    {
        if(t1.credit > t2.credit)
            return true;
        else if(t1.credit==t2.credit)
            return t1.id<t2.id;
    }
}
int main()
{
    int n;
    cin>>n;
    memset(flag, 0 , sizeof(flag));
    tuple customer[n];
    for(int i=0;i<n;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        customer[i].id=a;
        customer[i].arrival=b;
        customer[i].credit=c;
    }
    priority_queue <tuple> Q;
    sort(customer, customer+n, compare);
    for(int i=0;i<n;i++)
        cout<<customer[i].id<<" "<<endl;
    Q.push(customer[0]);
    flag[customer[0].id]=1;
    int t=1;
    //int flag=0;
    int process_count=0;
    while(!Q.empty() && process_count!=n)
    {

        for(int i=0;i<n;i++)
        {
            if(customer[i].arrival<=t && flag[customer[i].id]==0)
             {   Q.push(customer[i]);
                    flag[customer[i].id]=1;
                    }
        }
        if(!Q.empty())
        {
            tuple k=Q.top();
            cout<<k.id<<" ";
            Q.pop();
            process_count++;
        }
        t++;

    }
    return 0;
}
