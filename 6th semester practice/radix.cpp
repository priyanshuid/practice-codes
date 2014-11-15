#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
void radix(string ar[],int st,int en,int i,int n)
{
    if(st>en || i>=n)
        return;
    int dec=en;
    int inc=st;
    while(dec>inc)
    {
        if(ar[dec].at(i)=='0' && ar[dec].at(i)=='1')
        {
            string temp=ar[dec];
            ar[dec]=ar[inc];
            ar[inc]=temp;
            inc++;
            dec--;
        }
        else if(ar[dec].at(i)=='1')
            dec--;
        else
            inc++;
    }
    int t=st;
    while(t<=en && ar[t].at(i)=='0')
        t++;
    radix(ar,st,t,i+1,n);
    radix(ar,t+1,en,i+1,n);
}
int main()
{
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++)
    {
        int n;
        cin>>n;
        string st[n];
        for(int i=0;i<n;i++)
            cin>>st[i];
        radix(st,0,n-1,00,4);
        for(int i=0;i<n;i++)
            cout<<st[i]<<endl;
    }
    return 0;
}
