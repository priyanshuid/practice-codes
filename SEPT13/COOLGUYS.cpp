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
long long gcd(long long a,long long b);
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		long long int n;
		long long int sum=0;
		scanf("%lld",&n);
	//	for(int j=1;j<=n;j++)		
	//		sum+=n/j;		
		long long int sqroot=sqrt(n);
		for(int j=1;j<=sqroot;j++)
			sum+=n/j;
		sum+=sum;
		sum=sum-sqroot*sqroot;
	//	cout<<sum<<endl;
		long long int denominator=n*n;
		long long int v=gcd(denominator,sum);
		long long int n1=(long long int)sum/v;
		long long int n2=(long long int)denominator/v;
		printf("%lld/%lld\n",n1,n2);
	}
	return 0;
}
long long int gcd(long long int a,long long int b)
{
	long long int temp;
	while(b!=0)
	{
		temp=b;
		b=a%temp;
		a=temp;
	}
	return a;
}


