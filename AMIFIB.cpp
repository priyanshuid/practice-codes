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
int ar[100000000];
bool check(long long x)
{
    long long s = (long long)sqrt(x);
    return (s*s == x);
}
int main()
{
	ar[0]=0;ar[1]=1;
	for(int i=2;i<100000000;i++)
	{
		ar[i]=ar[i-1]+ar[i-2];
	}
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		char ar[10000];
		scanf("%s",&ar);
		int flag=0;
/*		for(int j=0;j<10000000;j++)
		{
			if(ar[j]==n)
			{
				cout<<"YES"<<endl;
				flag=1;
				break;
				}
		}*/
		
	//	cout<<fabs(sqrt1-v1)<<endl;
	//	cout<<fabs(sqrt2-v2);
	while()
	}
	return 0;
}


