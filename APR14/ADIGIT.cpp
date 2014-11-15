#include <iostream>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <string>
using namespace std;
int ar[10][100005];
char arr[100005];
void preprocess(int n)
{
    ar[(int)arr[0]-48][0]=1;
    for(int i=1;i<n;i++)
    {
        int v=(int)arr[i]-48;
        //cout<<v<<endl;
        for(int j=0;j<10;j++)
        {
            if(j==v)
                ar[j][i]=ar[j][i-1]+1;
            else ar[j][i]=ar[j][i-1];
        }
    }
  /*  for(int i=0;i<10;i++)
    {
        for(int j=0;j<n;j++)
            cout<<ar[i][j]<<" ";
            cout<<endl;
    }*/
}
int main()
{
    int n,m;
    memset(ar , 0 , sizeof(ar));
    scanf("%d %d", &n, &m);
    scanf("%s",arr);
    preprocess(n);
    for(int j=0;j<m;j++)
    {
        int k;
        scanf("%d", &k);
        k--;
        int v=(int)arr[k]-48;
        if(k==0)
            printf("%d\n",0);
        else
        {
            int sum1=0, sum2=0;
            int count1=0, count2=0;
            for(int i=0;i<v;i++)
            {
                sum1+=ar[i][k]*i;
                count1+=ar[i][k];
            }
            for(int i=v+1;i<10;i++)
            {
                sum2+=ar[i][k]*i;
                count2+=ar[i][k];
            }
            int sum= count1*v - sum1;
            sum= sum+ sum2 - count2*v;
            printf("%d\n",  sum);
        }
    }
    return 0;
}
