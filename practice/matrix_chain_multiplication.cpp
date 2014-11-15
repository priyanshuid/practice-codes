#include <iostream>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <vector>
#define INF 1000000005
using namespace std;
int table[1000][1000];
int s[1000][1000];
int matrix_bottom_up(int ar[], int n)
{
    for(int i=1;i<=n;i++)
        table[i][i]=0;
    int temp=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=n-temp;j<=n;j++)
        {
            int minm=INF;
            for(int k=i;k<j;k++)
                minm=min(minm, table[i][k]+table[k+1][j]+ar[i-1]*ar[k]*ar[j]);
            table[i][j]=minm;

        }
        temp++;
    }
    return table[1][n];
}
int main()
{
    int n;
    cin>>n;
    memset(table, 0 , sizeof(table));
    int ar[n];
    for(int i=0;i<n;i++)
        scanf("%d", &ar[i]);
    cout<<matrix_bottom_up(ar,n)<<endl;
    return 0;
}
