#include <iostream>
#include <stdio.h>
#include <algorithm>
#define mod 1000000007
using namespace std;
typedef long long int int64_t;
typedef unsigned long long int ull;
ull mult(ull a,ull b,ull c)
{
	a=a%mod;
	b=b%mod;
	c=c%mod;
	ull x=(((a*b)%mod)*c)%mod;
	return x;
}
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
				{
					ull m=mult(a-2,b-1,c);
						cout<<m <<endl;
				}
			else
				{
					ull m=mult(a-2,c-1,b);
					cout<<m <<endl;
				}
		}
		else if(b>=a && b>=c)
		{
			if(a>=c)
			{
					ull m=mult(b-2,a-1,c);
					cout<< m <<endl;
				}
			else
			{
					ull m=mult(b-2,c-1,a);
					cout<< m <<endl;
				}
		}
		else
		{
			if(a>=b)
			{
					ull m=mult(c-2,a-1,b);
					cout<<m <<endl;
					
				}
			else
			{
					ull m=mult(c-2,b-1,a);
			
					cout<< m <<endl;
				}
		}
	
	}
	return 0;
}
