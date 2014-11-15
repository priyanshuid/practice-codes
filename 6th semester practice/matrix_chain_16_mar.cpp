#include <iostream>
#include <stdio.h>
#include <math.h>
#define INF 100000000
using namespace std;
int table[1000][1000];
int s[1000][1000];
int matrix_mult(int ar[],int n)
{
    for(int i=1;i<=n;i++)
        table[i][i]=0;
    int temp=1;
    for(int i=n-1;i>=1;i--)
    {
        for(int j=n-temp;j<=n;j++)
        {
            if(i==j)
                table[i][j]=0;
            else
            {
                for(int k=i;k<j;k++)
                {
                    int val=table[i][k] + table[k+1][j] + ar[i-1]*ar[k]*ar[j];
                    if(val>table[i][j])
                    {
                        table[i][j]=val;
                        s[i][j]=k;
                    }
                }
            }
        }
    }
    return table[1][n];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            table[i][j]=INF;
    }
    int ar[n+1];
    for(int i=1;i<=n;i++)
        cin>>ar[i];
    cout<<matrix_mult(ar,n)<<endl;
    return 0;
}
