#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#define unsigned long long ull
#define MAXN 1000000
using namespace std;
int sm[101][101];
int minm(int a,int b)
{
	int val;
	val=a<b?a:b;
	return val;
}
int mixSum(int ar[],int st,int ed)
{
	int sum=0;
	for(int i=st;i<=ed;i++)
	{
		sum=(sum+ar[i]);
	}

	return sum%100;
}
int matrixMulRes(int ar[],int n)
{
	for(int i=0;i<n;i++)
		sm[i][i]=0;
	int temp=1;
	for(int i=n-2;i>=0;i--)
	{
		for(int j=n-temp++;j<n;j++)
		{
			if(i==j)
			sm[i][j]=0;
			sm[i][j]=MAXN;
			for(int k=i;k<j;k++)
			{
				sm[i][j]=minm(sm[i][j],sm[i][k]+sm[k+1][j]+mixSum(ar,i,k)*mixSum(ar,k+1,j));
			}
		}
	}
	return sm[0][n-1];
}
int main()
{
		int n;
		while(scanf("%d",&n)!=EOF)
		{
		memset(sm,0,sizeof(sm));
		int ar[n];
		for(int i=0;i<n;i++)
			scanf("%d",&ar[i]);
		int res=matrixMulRes(ar,n);
		printf("%d\n",res);
	//	for(int i=0;i<n;i++)
	//	{
	//		for(int j=0;j<n;j++)
	//		{
	//			cout<<sm[i][j]<<" ";
	//		}
	//		cout<<endl;
	//	}
		}
	return 0;	
}


