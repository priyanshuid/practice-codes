#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <string.h>
using namespace std;
int main()
{
		int n,k;
		scanf("%d%d",&n,&k);
		int ar[n];
		for(int i=0;i<n;i++)
			scanf("%d",&ar[i]);
		sort(ar,ar+n);
		long min_diff=1000000000;
		for(int i=k-1;i<n;i++)
		{
			long sum=0;
			int count=k-1;
			for(int j=i-k+1;j<=i;j++)
			{
				sum+=count*ar[j];
				sum-=(k-1-count)*ar[j];
				count--;
			}
			sum=-sum;
			if(sum<min_diff)
				min_diff=sum;
		}
		printf("%ld\n",min_diff);
		return 0;
}

