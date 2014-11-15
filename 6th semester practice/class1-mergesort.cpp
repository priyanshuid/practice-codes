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
void merge(int ar[],int l,int q,int r);
void mergesort(int ar[],int l,int r)
{
	if(l<r)
	{
		int q=(l+r)/2;
		mergesort(ar,l,q);
		mergesort(ar,q+1,r);
		merge(ar,l,q,r);
	}
}
void merge(int ar[],int l,int q,int r)
{
	int s1=q-l+1;
	int s2=r-q;
	int ar1[s1];
	int ar2[s2];
	for(int i=0;i<s1;i++)
		ar1[i]=ar[i+l-1];
	for(int i=0;i<s2;i++)
		ar2[i]=ar[i+q];
	int i=0;
	int j=0;
	for(int k=0;k<s1+s2;k++)
	{
		if(ar1[i]<ar2[j])
		{
			ar[k]=ar1[i];
			i++;
		}
		else
		{
			ar[k]=ar2[j];
			j++;
		}
	}
}
int main()
{
	int ar[10];
	for(int i=0;i<10;i++)
			cin >> ar[i];
	mergesort(ar, 0,9);
	for(int i=0;i<10;i++)
		cout<<ar[i]<<" " ;
	return 0;
}
