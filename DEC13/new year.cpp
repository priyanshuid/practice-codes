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
int left(int ar[],int i);
int right(int ar[],int i);
void build_max_heap(int ar[],int n);
void max_heapify(int ar[],int i,int n);
int main()
{
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++)
		cin>>ar[i];
	build_max_heap(ar,n);
	return 0;
}
void build_max_heap(int ar[],int n)
{
	for(int i=n/2;i>=0;i--)
		max_heapify(ar,i,n);
}
void max_heapify(int ar[],int i,int n)
{
	if(left(ar,i)!=-1 && right(ar,i)!=-1)
	{
		int iwl=i;
		int l=2*i+1;
		int r=2*i+2;
		if(ar[r]> ar[l] && ar[r]>ar[i])
			iwl=r;
		else if(ar[l]>ar[r] && ar[l]>ar[i])
			iwl=l;
		if(iwl!=i)
		{
				swap(ar,i,iwl);
				max_heapify(ar,iwl,n);
		}
	}
	
}
