#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int ar[100005];
int segTree[3*100005];
int lazy[3*100005];
int query(int st,int en,int l,int r,int indx)
{
    if(l>en || r< st)
        return 0;
    if(l==st && r==en)
        return segTree[indx];

    int temp;
    int mid=st+ (en-st)/2;
    if(l<=mid && r<=mid)
        temp=query(st,mid,l,r,2*indx+1);
    else if(l>mid && r>mid)
        temp=query(mid+1,en,l,r,2*indx+2);
    else
        temp=query(st,mid,l,mid,2*indx+1)+query(mid+1,en,mid+1,r,2*indx+2);
    if(lazy[indx] & 1)
        temp=r-l+1-temp;
        return temp;

}
void update(int st,int en,int l,int r,int indx)
{
    if(l> en || r<st)
        return ;
    if(l==st && r==en)
    {
            lazy[indx]++;
            segTree[indx]=en-st+1-segTree[indx];
            return;
    }

        int mid=st+(en-st)/2;
        if(l<= mid && r<=mid)
        update(st,mid,l,r,2*indx+1);
        else if(l>mid & r>mid)
        update(mid+1,en,l,r,2*indx+2);
        else
        {
            update(st,mid,l,mid,2*indx+1);
            update(mid+1,en,mid+1,r,2*indx+2);
        }
        segTree[indx]=segTree[2*indx+1]+segTree[2*indx+2];
        if(lazy[indx] & 1)
            segTree[indx]=en-st+1-segTree[indx];
            return;
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);

    memset(lazy,0,sizeof(lazy));
    memset(ar,0,sizeof(ar));
    memset(segTree,0,sizeof(segTree));
    for(int i=0;i<q;i++)
    {
        int a,b,p;
        scanf("%d%d%d",&p,&a,&b);
        if(p==1)
        {
            int indx=0;
            int v=query(0,n-1,a,b,0);
            cout<<v<<endl;
        }
        else update(0,n-1,a,b,0);

    }
       // for(int i=0;i<3*n;i++)
         //   cout<<segTree[i]<<" ";
           // cout<<endl;
    return 0;
}
