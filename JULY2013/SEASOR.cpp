#include <iostream>
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
using namespace std;
bool isSorted(int ar[],int n)
{
	bool fg=true;
	for(int i=0;i<n-1;i++)
	{
		if(ar[i]>ar[i+1])
		{
			fg=false;
			break;
		}
	}
	return fg;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int ar[n];
		for(int i=0;i<n;i++)
			scanf("%d",&ar[i]);
		int i=0;
		int j=0;
		int b=0;
		int v[(int)n*n/k+1000];
		while(!isSorted(ar,n))
		{
			if(i+k>n)
			{
			
				i=0;
				b++;
			}
			if(b==n-1)
			b=0;
			if(j>=(int)n*n/k+1000-1)
			break;
			int *start=&ar[i];
			int *end=&ar[min(i+k,n)];
			sort(start,end);
			if(i>=0 && i<=n-1)
			v[j++]=i+1;
			i=i+(int)k/5+b;
		//	for(int x=0;x<n;x++)
		//	cout<<ar[x]<<" ";
		//	cout<<endl;
			
		}
		printf("%d\n",j);
		for(int i=0;i<j;i++)
		{
			printf("%d ",v[i]);
		}
		printf("\n");
		
	}
	return 0;
}

