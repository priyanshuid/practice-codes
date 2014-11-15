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
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
			long long int n,k;
			long long int ans1=0,ans2=0;
			scanf("%lld %lld",&n,&k);
		if(k!=0)
		{
		
		if(n!=0)
		{
			 ans1=n%k;
			 ans2=n/k;		
		}
		else 
			ans1=n;
			printf("%lld %lld\n",ans2,ans1);
		}
		else
		printf("0 %lld\n",n);
	}
	return 0;
}


