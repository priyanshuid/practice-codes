#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>
#define MAXN 1000005
using namespace std;
int table[50][50];
void fill(int ar[],int n)
{
    int temp=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-temp;j<n;j++)
        {
            if(i==j)
                table[i][j]=ar[i];
            else
            {
                int min1=MAXN;
                for(int k=i;k<j;k++)
                {
                    if(table[i][k]<min1)
                        min1=table[i][k];
                }
                int min2=MAXN;
                for(int k=j;k>i;k--)
                {
                    if(table[k][j]<min2)
                        min2=table[k][j];
                }
                table[i][j]=min(min1,min2);
            }
        }
        temp++;
    }
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    memset(table,0,sizeof(table));
    for(int i=0;i<n;i++)
        scanf("%d",&ar[i]);
    fill(ar,n);
    int q;
    cin>>q;
    for(int q1=0;q1<q;q1++)
    {
        int v;
        int count=0;
        cin>>v;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {
                    if(table[i][j]==v)
                        count++;
                }
        }
        cout<<count<<endl;
    }
    return 0;
}
