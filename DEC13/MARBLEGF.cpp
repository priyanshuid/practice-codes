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
long long  ar[1000000];
long long segTree[2100000];
long long  construct_segTree(long long  ar[],int st,int se,long long segTree[],int index);
long long query_Sum(long long segTree[],int st,int se,int l,int r,int index);
void update_Add(long long segTree[],int st,int se,int pos_of_insertion,int val, int index);
int main()
{
	int n;
	int q;
	cin>>n>>q;	
	for(int i=0;i<n;i++)
		scanf("%lld",&ar[i]);
	long long ra=construct_segTree(ar,0,n-1,segTree,0);
	char s[16];
	int l=0,r=0;
	for(int i=0;i<q;i++)
	{
	 	scanf("%s",&s);
	 	scanf("%d",&l);
	 	scanf("%d",&r);
	 	if(s[0]=='S')
	 	{
	 		long long  sum=query_Sum(segTree,0,n-1,l,r,0);
	 		printf("%lld\n",sum);
	 	}
	 	else if(s[0]=='G')
	 	{
	 		int indx=l,val=r;
			 update_Add(segTree,0,n-1,indx,val,0);
	 	}
	 	else if(s[0]=='T')
	 	{
	 		int indx=l,val=-r;
	 		update_Add(segTree,0,n-1,indx,val,0);
	 	}
	}
	return 0;
}
long long construct_segTree(long long ar[],int st,int se,long long segTree[],int index)
{
	if(st==se)
	{
		segTree[index]=ar[se];
		return ar[se];
	}
	else
	{
		int mid=st+(se-st)/2;
		segTree[index]=construct_segTree(ar,st,mid,segTree,2*index+1)+construct_segTree(ar,mid+1,se,segTree,2*index+2);
		return segTree[index];
	}
}
long long query_Sum(long long segTree[],int st,int se,int l,int r,int index)
{
	if(l<=st && r>=se)
		return (long long)segTree[index];
	else if(st>r || se <l)
		return 0;
	else
	{
		int mid=st+(se-st)/2;
		return (long long)(query_Sum(segTree, st, mid,l,r,2*index+1)+query_Sum(segTree,mid+1,se,l,r,2*index+2));
	}
}
void update_Add(long long segTree[],int st,int se,int pos_of_insertion,int val, int index)
{
	if(pos_of_insertion <st || pos_of_insertion>se)
		return ;
	else
	{
		segTree[index]+=val;
		if(st!=se)
		{
			int mid=st+ (se-st)/2;
			update_Add(segTree,st,mid,pos_of_insertion,val,2*index+1);
			update_Add(segTree,mid+1,se,pos_of_insertion,val,2*index+2);
		}
	}
}
