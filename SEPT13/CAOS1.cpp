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
#define unsigned long long ull
using namespace std;
int find_min(int a,int b,int c,int d)
{
	int ar[]={a,b,c,d};
	int min=ar[0];
	for(int i=1;i<4;i++)
	{
		if(ar[i]<min)
		min=ar[i];
	}
	return min;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		int rw,cn;
		scanf("%d %d",&rw,&cn);
		char ar[rw][cn];
		for(int i=0;i<rw;i++)
		{
			string str;
			int j=0;
			cin>>str;
			int l=str.length();
			while(j<l)
			ar[i][j++]=str.at(j);
		}
		int count=0;
		for(int i=0;i<rw;i++)
		{
			for(int j=0;j<cn;j++)
			{
			
				if(ar[i][j]=='^')
				{
					int l=0,r=0,t=0,b=0;
					int cl=j-1;
					int cr=j+1;
					int cb=i+1;
					int ct=i-1;
					while(cl>=0 && ar[i][cl]=='^')
					{
						l++;
						cl--;
					}
					while(cr<cn && ar[i][cr]=='^')
					{
						r++;
						cr++;
					}
					while(cb<rw && ar[cb][j]=='^')
					{
						b++;
						cb++;
					}
					while(ct>=0 && ar[ct][j]=='^')
					{
						t++;
						ct--;
					}
					int min=find_min(l,r,t,b);
					
					if(min>=2)
						count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}

