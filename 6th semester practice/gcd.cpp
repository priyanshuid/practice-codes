#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int gcd(int a ,int b)
{
	if(a%b==0)
	    return b;
	else
	    gcd(b,a%b);
}
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		int a,b;
		cin>>a>>b;
		cout<<gcd(a,b)<<endl;
	}
	return 0;
}
