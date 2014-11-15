#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;
int table[500][500];
int knapsack(int w[],int v[],int MW,int i,int n)
{
    if(i>n)
    {
        table[MW][i]=0;
        return table[MW][i];
    }

    else if( w[i]>MW)
    {
        if(table[MW][i+1]==0)
        table[MW][i+1]=knapsack(w,v,MW,i+1,n);
        return table[MW][i+1];
    }
    else
    {
        if(table[MW-w[i]][i+1]==0)
            table[MW-w[i]][i+1]=knapsack(w,v, MW - w[i],i+1,n);
        if(table[MW][i+1]==0)
            table[MW][i+1]=knapsack(w,v,MW,i+1,n);
            return max(table[MW-w[i]][i+1]+v[i],table[MW][i+1]);
    }
}
int main()
{
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++)
    {
        memset(table, 0, sizeof(table));
        int n;
        cin>>n;
        int v[n];
        int w[n];
        for(int i=0;i<n;i++)
            cin>>v[i]>>w[i];
        int max_weight;
            cin>>max_weight;
        int val=knapsack(w,v,max_weight,0,n-1);
        cout<<val<<endl;
    }
    return 0;
}
