#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <memory.h>
using namespace std;
int primes[10000];
bool sieve[31700];
int top=-1;
void initialise()
{
	memset(sieve,true,sizeof(sieve));
	sieve[0]=false;
	sieve[1]=false;
	for(int i=2;i<=sqrt(31700);i++)
	{
		if(sieve[i]==true)
		{
			for(int j=i*i;j<31700;j=j+i)
			{
				sieve[j]=false;
			}
		}
	}
	for(int i=0;i<31700;i++)
	{
		if(sieve[i]==true)
			primes[++top]=i;
	}
}
int main()
{
	initialise();
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		int m,n;
		cin>>m>>n;		
		bool pp[n-m+1];
		memset(pp,true,sizeof(pp));
		if(m==1)
		pp[0]=false;
		for(int i=2;i<=sqrt(n)+1;i++)
		{
			if(pp[i]==true)
			{
				int p=max(2,(m-1)/i+1);
				for(int j=p*i-m;j<=n-m;j=j+i)
				{
					pp[j]=false;
				}
			}
		}
		for(int i=0;i<n-m+1;i++)
		{
			if(pp[i]==true)
			printf("%d\n",m+i);
		}
	}
	return 0;
}
