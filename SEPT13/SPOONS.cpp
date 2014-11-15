#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
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
		long long int n;
		scanf("%lld",&n);
		double m=0;
		if(n==2)
			cout<<2<<endl;
		else
		{
			long long ans=0;
			long long sqt=1+8*n;
			ans=(long long)((ceil)((double)(((floor)(sqrt(sqt)))+1)/2));
			long long k=(ans*(ans-1))/2;
			long long l=((ans-1)*(ans-2))/2;
			if(n>k)
				ans+=1;
			else if(n<l)
				ans-=1;
			cout<<ans<<endl;
		}
	}
	return 0;
}
