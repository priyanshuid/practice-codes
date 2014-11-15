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
int ar[100005];
long long segTree[200000];
long long buildTree(int ar[],long long segTree[],int indx,int s_indx,int e_indx)
{
	if(s_indx==e_indx)
	{
		segTree[indx]=ar[s_indx];
		return segTree[indx];
	}
	else
	{
		int mid=(s_indx+e_indx)/2;
		segTree[indx]=(long long)pow(buildTree(ar,segTree,2*indx+1,s_indx,mid),2)+(long long)pow(buildTree(ar,segTree,2*indx+1,s_indx,mid),2);
		return segTree[indx];
	}
}
long long query(long long segTree[],int l,int r,int s_indx,int e_indx,int indx)
{
	if(l<=s_indx && r>=s_indx)
		return segTree[indx];
	else if(s_indx<l || e_indx>r)
		return 0;
	else
	{
		int mid=(s_indx+e_indx)/2;
		return query(segtree,l,r,s_indx,mid,2*indx+1)+query(segTree,l,r,mid+1,e_indx,2*indx+2);				
	}
}
void updateEqualX(long long segTree[],int l,int r,int s_indx,int e_indx,int indx)
{
	
}
