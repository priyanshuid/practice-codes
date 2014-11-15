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
int b_search(int ar[],int n,int val);
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		int n;
		cin>>n;
		int ar[n];
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
		}
		int k;
		cin>>k;
		int val=ar[k-1];
		sort(ar,ar+n);
		if(n==1)
			cout<<1<<endl;
		else
		{
			int pos=b_search(ar,n,val);
			cout<<pos+1<<endl;
		}
	}
	return 0;
}
int b_search(int ar[],int n,int val)
{
	int mid;
	int st=0;
	int en=n-1;
	while(st<=en)
	{
		mid=(en-st)/2+st;
		if(ar[mid]>val)
			en=mid-1;
		else if(ar[mid]<val)
			st=mid+1;
			else return mid;
			
	}
	return -1;
}

