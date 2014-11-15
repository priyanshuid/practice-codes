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
long long mulmod(long long base,long long power,long long S,long long L)
{
	long long val=1;
	while(power)
	{
		if(power%2==0)
			{
				power/=2;
				base=base*base;
			}
		else 
		{
			power/=2;
			val=val*base;
			base=base*base;
			
		}
		if(S*val>=L)
			return 1;
	}
	if(S*val>=L)
		return 1;
		else return 0;
//	if(a>=L)
//		flag=1;
//	if(b<=1)
//		return a;
//	else if(b%2==0)
//		return mulmod(a*a,b/2,L);
//	else return a*mulmod(a*a,b/2,L);
}
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		long long L,D,S,C;
		cin>>L>>D>>S>>C;
		double val1;
		if(D==1)
		{
			if(S>=L)
				cout<<"ALIVE AND KICKING"<<endl;
			else cout<<"DEAD AND ROTTING"<<endl;
		}	
		else
			{
				val1=S*pow(1+C,D-1);
				if(val1>=L)
				cout<<"ALIVE AND KICKING"<<endl;
		else cout<<"DEAD AND ROTTING"<<endl;
			}
	//	cout<<val1<<endl;
	}
	return 0;
}

