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
#define MOD 1000000007
using namespace std;
unsigned mul(unsigned long long a,unsigned long long b)
{
	if(b==0)
		return 1;
	else if(b==1)
		return a%MOD;
	else if(b%2==0)
		return mul((a*a)%MOD,b/2);
	else
		return (a*mul((a*a)%MOD,b/2))%MOD;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		int n;
		scanf("%d",&n);
		unsigned long long val=0;
		int count=0;
		while(n!=0)
		{
			unsigned long long v=(unsigned long long)n%2;
			val+=(unsigned long long)ceil(pow(10,count)*v);
			count++;
			n=n/2;
		}
		unsigned long long two=2;
		unsigned long long ans=mul(two,val);
		unsigned long long fin_ans=((ans%MOD)*(ans%MOD))%MOD;
		printf("%llu\n",fin_ans);
	}
	return 0;
}


