#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define NEF -1000005
using namespace std;
int table[1005][1005];
int b[1005][1005];
int c[1005][1005];
int painting(int ar[],int i,int k,int n,int temp[])
{
    if(i>n)
    {
        table[i][k]=0;
        return table[i][k];
    }
    if(k==0)
    {
        if(table[i+1][k]==NEF)
          //  table[i][k]=b[i][ar[i]]+painting(ar,i+1,k,n,temp);
          table[i+1][k]=painting(ar,i+1,k,n,temp);
        return table[i+1][k]+b[i][ar[i]];
    }
    else
    {
        if(table[i+1][k-1]==NEF)
            table[i+1][k-1]=painting(ar,i+1,k-1,n,temp);
        if(table[i+1][k]==NEF)
            table[i+1][k]=painting(ar,i+1,k,n,temp);
        return max(table[i+1][k-1]+temp[i],table[i+1][k]+b[i][ar[i]]);
    }

}
int main()
{
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++)
    {
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int i=0;i<1005;i++)
        { for(int j=0;j<1005;j++)
                table[i][j]=NEF;}
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int ar[n+1];
        for(int i=1;i<=n;i++)
            scanf("%d",&ar[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                scanf("%d",&b[i][j]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                scanf("%d",&c[i][j]);
        }
        int temp[n+1];
        for(int i=1;i<=n;i++)
        {
            int maxm=NEF;
            for(int j=1;j<=m;j++)
            {
                if(b[i][j]-c[i][j]>maxm)
                    maxm=b[i][j]-c[i][j];
            }
            temp[i]=maxm;
        }
        int maxmn=painting(ar,1,k,n,temp);
        cout<<maxmn<<endl;
    }
    return 0;
}
