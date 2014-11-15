#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#define MOD 1000000007
typedef unsigned long long ull;
using namespace std;
ull table[1001][11];
ull messi(int n,int m);
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
			for(int i=0;i<1001;i++)
			{
				for(int j=0;j<11;j++)
					table[i][j]=0;
			}
		int n,m;
		cin>>n>>m;
		ull ans=messi(n-1,m);
		cout<<ans<<endl;
	}
	return 0;
}
ull messi(int n,int m)
{
	if(n==1 && table[n][m]==0)
		{
			table[n][m]=m;
			return table[n][m];
		}
	else if(n==2 && table[n][m]==0)
		{
			table[n][m]=m*(m-1);
			return table[n][m];
		}
	else 
		{
			if(table [n-2][m]==0)
				table[n-2][m]=messi(n-2,m);
			if(table[n-1][m]==0)
				table[n-1][m]=messi(n-1,m);
			return ((((m*(table[n-2][m]%MOD))%MOD)%MOD) + ((((m-1)*(table[n-1][m]%MOD))%MOD)%MOD))%MOD;
		}
}
