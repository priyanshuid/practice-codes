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
int a[17];
int marked[17];
int b[17];
double p[17];
double prob(int i,int n,bool a1)
{
	
	if(i==0)
	{
		return p[0]*prob(1,n,0)+(1-p[0])*prob(1,n,1);
	}
	else if(i>n)
	{
		return 1;
	}
	else
	{
		if(a1==0)
			marked[a[i-1]]=1;
		else
			marked[b[i-1]]=1;
			
		if(marked[a[i]]==0 && marked[b[i]]==0)
		{
				return p[i]*prob(i+1,n,0)+(1-p[i])*prob(i+1,n,1);
		}
		else if(!marked[a[i]])
		{
				return p[i]*prob(i+1,n,0);
		}
		else if(!marked[b[i]])
		{
			return (1-p[i])*prob(i+1,n,1);
		}
		else 
		{
			return 0;
		}
	}
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
			p[i]=(double)pr/100;
		}
		if(n>16)
		printf("0\n");
		else
		{
			double pr1=prob(0,n-1,0);
			std::cout.setf( std::ios::fixed, std:: ios::floatfield ); 
			std::cout.precision(6); 
			cout<<pr1<<endl;
		}
	}
}

