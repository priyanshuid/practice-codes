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
		float d,u;
		int n;
		cin>>d>>u>>n;
		float defaultRate=d*u;
		int month[n];
		float ar[n][2];
		for(int i=0;i<n;i++)
			cin>>month[i]>>ar[i][0]>>ar[i][1];
		int max=0;
		/*for(int i=0;i<n;i++)
		{
			if(month[i]>max)
			max=month[i];
		}*/
		float val_min=defaultRate;
		int index=-1;
		for(int i=0;i<n;i++)
		{
			int pp=0;
			if(max%month[i]==0)
				pp=max/month[i];
			else
			    pp=(int)(max/month[i])+1;
			//float val=(pp)*ar[i][1]+ar[i][0]*u*month[i];
			float val=(float)ar[i][1]/month[i]+ar[i][0]*u;
			//cout<<val<<endl;
			if(val_min>val)
				{
					val_min=val;
					index=i;
				}
		}
	//	if(val_min>defaultRate)
	//	cout<<0<<endl;
	//	else
		cout<<index+1<<endl;
	}
}

