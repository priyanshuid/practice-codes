#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int pos=-1;
int ternary_search(int ar[],int st,int en,int val)
{
    int t1=(int)(st+en)/3;
    int t2=(int)2*(st+en)/3;
    if(st>en)
        return -1;
    else
    {
        if(ar[t1]==val)
            return t1;
        else if(ar[t2]==val)
            return t2;
        else
        {
            if(ar[t1]< val)
                ternary_search(ar,st,t1,val);
            else if( ar[t2]>val)
                ternary_search(ar,t2,en,val);
            else
                ternary_search(ar,t1,t2,val);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++)
    {
        int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++)
            cin>>ar[i];
        int val;
        cin>>val;
        int pos=ternary_search(ar,0,n-1,val);
        if(pos==-1)
            cout<<"NOT FOUND"<<endl;
        else
            cout<<pos+1<<endl;
    }
    return 0;
}
