#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int bsearch(int ar[],int st ,int en,int key)
{
    int mid=st+(en-st)/2;
    while(!(st>en))
    {
        if(key==ar[mid])
            return mid;
        else if(key< ar[mid])
            en=mid;
        else
            st=mid+1;
        mid=st+(en-st)/2;
    }
    return -1;
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
        int key;
        cin>>key;
        int pos=bsearch(ar,0,n-1,key);
        if(pos>=0)
            cout<<pos+1<<endl;
        else
            cout<<"NOT FOUND"<<endl;
    }
    return 0;
}
