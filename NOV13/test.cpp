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
bool sieve[1000005];
int primes[78500];
int top=-1;
void prime_generator()
{
	memset(sieve,true,sizeof(sieve));
	sieve[0]=false;
	sieve[1]=false;
	for(int i=2;i<=sqrt(1000005)+1;i++)
	{
		if(sieve[i]==true)
		{
			for(int j=i*i;j<1000005;j=j+i)
			{
				sieve[j]=false;	
			}
		}
	}
	for(int i=2;i<1000005;i++)
	{
		if(sieve[i]==true)
			primes[++top]=i;
	}
}
int main()
{
	int t;
	prime_generator();
	for(int i=0;i<100;i++)
	cout<<primes[i]<<"  ";
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		
		long long l,r;
		scanf("%lld %lld",&l,&r);
		int no_of_sqrs=0;
		int st=floor(sqrt(l));
		int en=ceil(sqrt(r));
		no_of_sqrs=en-st;
		long long count=r-l+1;
		long long lim = sqrt(r);
    	int j,i;
    	i=0;
    	while(primes[i]<=lim && i<=top)
    	{
        	for(j=((l-1)/primes[i]+1)*primes[i];j<=r;j+=primes[i])
        	{
            	if(j!=primes[i])
            	{
                	count--;
            	}
        	}
    	i++;
    	cout<<primes[i]<<" "<<i<<endl;
    	}
    	
		cout<<count<<endl;
	}
	return 0;
}

