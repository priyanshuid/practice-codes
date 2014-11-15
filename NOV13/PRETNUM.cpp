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
void prime_factors(vector <int>&prime_power,long long val);
int calculate(vector <int>&prime_power);
bool isPrime(int n);
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		long long int l,r;
		scanf("%lld %lld",&l,&r);
		int count=0;
		for (long long i=l;i<=r;i++)
		{
			vector<int> prime_power;
			prime_factors(prime_power,i);
			int num_div=calculate(prime_power);
			if(isPrime(num_div))
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
void prime_factors(vector <int>&prime_power,long long val)
{
	int i=0;
	long long pp=2;
	int count=0;
	prime_power.push_back(0);
	while(pp<=(long long)sqrt(val) && val!=1)
	{
		if(val%pp==0)
		{
			prime_power[i]=++count;
			val=(int)(val/pp);
		}
		else
		{
			prime_power.push_back(0);
			i++;
			count=0;
			if(pp==2)
				pp++;
			else
				pp=pp+2;
		}
	}
}
int calculate(vector <int>& prime_power)
{
	vector <int>::iterator p;
	int mul_sum=1;
	for(p=prime_power.begin();p<=prime_power.end();p++)
		mul_sum=mul_sum*(*p+1);
	return mul_sum;
}
bool isPrime(int val)
{
	int count=0;
	for(int i=2;i<=sqrt(val)+1;i++)
	{
		if(val%i==0)
		{
			count++;
		}
	}
	if(count==1)
		return true;
	else
		return false;	
}
