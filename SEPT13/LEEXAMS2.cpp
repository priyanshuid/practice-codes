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
int a[50];
int marked[17];
int b[50];
double p[50];
double prob(int i,int n)
{
	double fv=0;
	if(i>=n)
	{
		fv=1.0;
		for(int j=0;j<=n;j++)
		{
			if(marked[i]==0)
				fv=fv*p[i];
			else
				fv=fv*(1-p[i]);
		}
		cout<<fv<<endl;
		return fv;
	}

		
		bool ch1=1,ch2=1;
		for(int j=0;j<i;j++)
		{
			if(marked[j]==0)
			{
				if(a[i]==a[j])
				ch1=0;
				if(b[i]==a[j])
				ch2=0;
			}
			else
			{
				if(a[i]==b[j])
				ch1=0;
				if(b[i]==b[j])
				ch2=0;
				
			}
		}
		if(ch1==1)
		{
			marked[i]=0;
			fv+=prob(i+1,n);
		}
		if(ch2==1)
		{
			marked[i]=1;
			fv+=prob(i+1,n);
		}
	return fv;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(marked,0,sizeof(marked));
		memset(p,0.0,sizeof(p));
		int n;
		scanf("%d",&n);
		int pr;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&pr,&a[i],&b[i]);
			p[i]=(double)pr/100.0;
		}
		if(n>16)
		printf("0.0000000\n");
		else
		{
			double pr1=prob(0,n-1);
			cout<<pr1<<endl;
			std::cout.setf( std::ios::fixed, std:: ios::floatfield ); 
			std::cout.precision(6); 
			cout<<pr1<<endl;
		}
	}
}

