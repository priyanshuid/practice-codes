#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n,count=0;
		scanf("%d",&n);
		int ar[n];
		for(int j=0;j<n;j++)
		scanf("%d",&ar[j]);
		int *beg=&ar[0],*end=&ar[n];
		sort(beg,end);
		for(int j=0;j<n;j++)
		count=count+ar[j];
		count=count-n*ar[0];
		printf("%d\n",count);
	}
	return 0;
}
