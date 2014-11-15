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
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		int n;
		cin>>n;
		int ar[n];
		for(int i=0;i<n;i++)
			scanf("%d",&ar[i]);
		int flag=(ar[0]>=0)?1:0;
		int flag1=0;
		if(flag==1)
		{
			for(int i=0;i<n;i++)
			{
				if(ar[i]<0)
				{
					flag1=1;
					break;			
				}
			}
		}
		else if(flag==0)
		{
			for(int i=0;i<n;i++)
			{
				if(ar[i]>0)
				{
					flag1=1;
					break;			
				}
			}
		}
		if(flag1==1)
		{
			
			int n1=max_start+1;
			int n2=n-max_end+1;
			int ar1[max_start+1];
			for(int i=0;i<=max_start;i++)
				ar1[i]=-ar[i];
			int S1[n1],T1[n1];
			S1[0] = ar1[0];
			T1[0] = 0;
			int max1 = S1[0];
			int max_start1 = 0, max_end1 = 0;
			for(int i=1;i<n1;i++)
			{
			
				if ( S1[i-1] > 0)
					{
						S1[i] = S1[i-1] + ar1[i];
						T1[i] = T1[i-1];
					}
				else
					{
						S1[i] = ar1[i];
						T1[i] = i;
					}
				if (S1[i] >max1)
					{
						max_start1 = T1[i];
						max_end1 = i;
						max1 = S1[i];
					}
			}
			max1=-max1;
			int ar2[n2];
			for(int i=max_end+1;i<n;i++)
				ar2[i]=-ar[i];
			int S2[n2],T2[n2];
			S2[0] = ar2[0];
			T2[0] = 0;
			int max2 = S2[0];
			int max_start2 = 0, max_end2 = 0;
			for(int i=1;i<n1;i++)
			{
			
				if ( S2[i-1] > 0)
					{
						S2[i] = S2[i-1] + ar2[i];
						T2[i] = T2[i-1];
					}
				else
					{
						S2[i] = ar2[i];
						T2[i] = i;
					}
				if (S2[i] >max2)
					{
						max_start2 = T2[i];
						max_end2 = i;
						max2 = S2[i];
					}
			}
			max2=-max2;
			cout<<max<<" "<<max1<<" "<<max2<<endl;
			
		}
	}
}


