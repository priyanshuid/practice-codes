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
	int n;
	scanf("%d",&n);
	long long int ar[n];
	int flag=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&ar[i]);
		if(ar[i]>1)
			flag=1;
	
	}
 	long long int sum=0;
 	if(flag==1)
 	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				sum+= (int)(ar[i] & ar[j]);
			}
		}
		cout<<sum<<endl;
	}
	else 
	{
		long long count=0;
		for(int i=0;i<n;i++)
		{
			if(ar[i]==1)
			{
				count++;
			}
		}
		sum=(long long int) ((count*(count-1))/2);
		cout<<sum<<endl;
	}
	return 0;
}

