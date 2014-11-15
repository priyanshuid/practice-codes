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
#define _int64 ll
using namespace std;
int main()
{
	int n,count=0;
	long long int  op_sum=0;
	vector <long long int>v;
	long long int sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		long long int k;
		scanf("%lld",&k);
		if(k<0)
		{
			v.push_back(k);
			count++;
			sum+=k;
		}
	}
	long long int x;
	scanf("%lld",&x);
	sort(v.begin(),v.end());
	int pos=x-1;
	if(x>=count)
	op_sum=-sum;
	else
	{
		op_sum-= x*v[pos];
		for(int i=pos-1;i>=0;i--)
			{
				op_sum=op_sum-(v[i]-v[pos]);
			}
	}
	printf("%lld",op_sum);
	
	return 0;	
}


