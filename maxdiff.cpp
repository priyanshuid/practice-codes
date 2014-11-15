#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		int n,k;
		cin>>n>>k;
		int ar[n];
		for(int i=0;i<n;i++)
			scanf("%d",&ar[i]);
		int *start=&ar[0];
		int *end=&ar[n];
		sort(start,end);
		if(k>n/2)
		k=n-k;
		int sum1=0,sum2=0;
		for(int i=0;i<n;i++)
		{
			if(i>=k)
				sum1+=ar[i];
			else
				sum2+=ar[i];
		}
		int diff=sum1-sum2;
		printf("%d\n",diff);
	}
	return 0;
}
