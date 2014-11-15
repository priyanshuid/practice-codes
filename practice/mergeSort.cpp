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
void mergeThem(int ar[],int ar1[],int ar2[]);
void mergeSort(int ar[])
{
	int n=sizeof(ar)/sizeof(int);
	if(n>1)
	{
		int k=n/2;
		int ar1[k];
		int ar2[n-k];
		for(int i=0;i<k;i++)
			ar1[i]=ar[i];
		for(int i=0;i<n-k;i++)
			ar2[i]=ar[k+i];
		mergeSort(ar1);
		mergeSort(ar2);
		mergeThem(ar,ar1,ar2);
	}
}
void mergeThem(int ar[],int ar1[],int ar2[])
{
	int j=0;
	int p1=sizeof(ar1)/sizeof(int);
	int p2=sizeof(ar2)/sizeof(int);
	int c1=0,c2=0;  //counts for keeping track of the no. of the elements in each array taken care of//
	while (c1<p1 && c2<p2)
	{
		if(ar1[c1]<ar2[c2])
			ar[j++]=ar1[c1++];
		else
			ar[j++]=ar2[c2++];
	}
	while(c1<p1)
	{
		ar[j++]=ar1[c1++];
	}
	while(c2<p2)
	{
		ar[j++]=ar2[c2++];
	}
}
int main()
{
	int ar[10];
	for(int i=0;i<10;i++)
		scanf("%d",&ar[i]);
	mergeSort(ar);
	for(int i=0;i<10;i++)
		printf("%d ",ar[i]);
	return 0;
}

