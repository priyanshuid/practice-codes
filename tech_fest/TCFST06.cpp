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
int main()
{

	int n,v,count_negative=0,count_positive=0,count=0;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++)
	{
		int v;
		scanf("%d",&v);
		ar[i]=v;
	}
	if(ar[0]==0)
	{
			ar[0]=-1;
			count++;
		}
	if(ar[n-1]==0)
	{
		ar[n-1]=1;count++;
	}
	if(ar[0]>0)
	{
		count++;
		ar[0]=-ar[0];
	}
	if(ar[n-1]<0)
	{
		count++;
		ar[n-1]=-ar[n-1];
	}
	int i=0,k=n-1;
	while(!(ar[i]>0))
		i++;
	while(!(ar[k]<0))
		k--;
	count_negative=0,count_positive=0;
	for(int j=i;j<=k;j++)
	{
		if(ar[j]<0)
			count_negative++;
		else if(ar[j]>0)
			count_positive++;
	}
	if(i<k)
		count+=(count_negative>count_positive)?count_positive:count_negative;
	/*for(int j=i;j<=k;j++)
	{
		if(ar[j]>0)
		{
			if(remaining_negative>=remaining_positive)count++;
			remaining_positive--;
		}
		else if(ar[j]<0)
		{
			
			if(remaining_positive>=remaining_negative)count++;
			remaining_negative--;
		}
	}*/
	for(int j=0;j<n;j++){

		if(ar[j]==0)
		count++;
	}
	
	cout<<count;
	return 0;
}

