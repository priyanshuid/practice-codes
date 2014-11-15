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
void max_so_far_function(int ar[],int n,long long result_array[])
{
	long long msf=-1000000001;
	long long meh=0;
	for(int i=0;i<n;i++)
	{
		meh=meh+ar[i];
		msf=max(msf,meh);
		if(meh<=0)
			meh=0;
		result_array[i]=msf;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		int ar[n];
		for(int i=0;i<n;i++)
			scanf("%d",&ar[i]);
		long long sum_left[n];
		long long sum_right_temp[n];
		int rev[n];
		for(int i=0;i<n;i++)
			rev[i]=ar[n-1-i];
		max_so_far_function(ar,n,sum_left);
		max_so_far_function(rev,n,sum_right_temp);
		int count_forward=0;
		int count_backward=n-1;
		long long sum_right[n];
		for(int i=0;i<n;i++)
			sum_right[i]=sum_right_temp[n-1-i];
		long long max_sum=-2000000001;
		for(int i=0;i<n;i++)
		{
			if(i+k+1<n)
			{
			long long sum=sum_left[i]+sum_right[i+k+1];
			if(sum>max_sum)
				max_sum=sum;
			}
		}
		cout<<max_sum<<endl;
	}
	return 0;
}
