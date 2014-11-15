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
long long mul(long long a,long long b)
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
	cin>>t;
	for(int i=0;i<t;i++)
	{
		long long n;
		scanf("%lld",&n);
		if(n==1)
			printf("1\n");
		else
		{
			long long two=2;
			long long ans=mul(two,n);
			ans-=1;
			printf("%ld\n",ans);
		}
	}
	return 0;
}

