#include <iostream>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <algorithm>
#define INT_MAX 10000007
using namespace std;
int table[1000][1000];
int multiply(int ar[],int i,int j)
{
    if(table[i][j]<1000000)
        return table[i][j];
    if(j==i)
        table[i][j]=0;
    else
    {
        int q=0;
        for(int k=i;k<j;k++)
        {
            q=multiply(ar,i,k)+multiply(ar,k+1,j)+ar[i]*ar[k]*ar[j];
            if(q<table[i][j])
                table[i][j]=q;
        }
    }
    return table[i][j];
}
int main()
{
    int t;
    cin>>t;
    for(int  t1=0;t1<t;t1++)
    {
        memset(table,1000000,sizeof(table));
        int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++)
            cin>>ar[i];
       cout<<multiply(ar,0,n-1)<<endl;
    }
    return 0;
}
