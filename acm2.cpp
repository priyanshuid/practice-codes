#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		int n;
		scanf("%d",&n);
		int ar[n];
		for(int i=0;i<n;i++)
			scanf("%d",&ar[i]);
		sort(ar,ar+n);
		int size=3;
		long long sum=ar[0]+ar[1]+ar[2];
		int counter=0;
		for(int i=3;i<n;i++)
		{
			if(sum<=ar[i])
			{
				counter++;
				sum+=ar[i];
			}	
			else
			{
				size=size+counter+1;
				counter=0;
				sum+=ar[i];
			}
		}
		if(size==3)
		{
			if(ar[0]+ar[1]<=ar[2])
				size=-1;
		}
		printf("%d\n",size);
	}
	return 0;
}	
		
