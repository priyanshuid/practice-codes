#include <iostream>
#include <stdio.h>
#include <algorithm>
#define mod 1000000007
typedef unsigned long long int ull;
using namespace std;
ull mult(ull a,ull b);
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ull a,b,c;
		cin>>a>>b>>c;
		if(a>=b && a>=c)
		{
			if(b>=c)
				cout<<((((a-2)%mod)*((b-1)%mod)*(c%mod))%mod) <<endl;
			else
				cout<<((((a-2)%mod)*((c-1)%mod)*(b%mod))%mod) <<endl;
		}
		else if(b>=a && b>=c)
		{
			if(a>=c)
			cout<<(((b-2)%mod)*((a-1)%mod)*(c%mod)%mod)<<endl;
			else
			cout<<(((b-2)%mod)*((c-1)%mod)*(a%mod)%mod)<<endl;
		}
		else
		{
			if(a>=b)
			cout<<(((c-2)%mod)*((a-1)%mod)*(b%mod)%mod)<<endl;
			else
			cout<<(((c-2)%mod)*((b-1)%mod)*(a%mod)%mod)<<endl;
		}
	
	}
	return 0;
}
ull mult(ull a,ull b)
{
	return ull(int64(a)*b%mod);
}
