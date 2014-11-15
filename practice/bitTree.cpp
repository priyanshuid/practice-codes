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
int ar[100];
int bitTree[200];
int positionOfLastBit(int idx)
{
	if(idx==0)
		return 0;
	int k=0;
	int i=0;
	while(idx!=0)
	{
		k += pow(10,i++)*(idx % 2);
		idx=idx/2;
	}
	int count=0;
	while(k!=0)
	{
		if(k%10==1)
			return count;
		k=k/10;
		count++;
	}
}
void buildTree(int ar[],int bitTree[],int n)
{
	for(int idx=1;idx<=n;idx++)
	{
		int pos=positionOfLastBit(idx);
		for(int i=idx- (int)pow(2,pos)+1;i<=idx;i++)
			bitTree[idx]+=ar[i];
	}
}
int summation(int idx)
{
	int sum=0;
	while(idx>0)
	{
		sum+=bitTree[idx];
		idx-=(idx & -idx);
	}
	return sum;
}
int query(int l, int r)
{
	int sum1=summation(l);
	int sum2=summation(r);
	return sum2-sum1;
}
void updateTree(int idx,int val,int n)
{
	while(idx<=n)
	{
		bitTree[idx]+=val;
		idx+=(idx & -idx);
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>ar[i];
		memset(bitTree,0, sizeof(bitTree));
		buildTree(ar,bitTree,n);
		for(int i=1;i<=n;i++)
			cout<<bitTree[i]<<" ";
			cout<<endl;
		cout<<"Enter the no. of queries"<<endl;
		int qq;
		cin>>qq;
		for(int i=0;i,qq;i++)
		{
			int l,r;
			cin>>l>>r;
			int val=query(l,r);
			cout<<val<<endl;
		}
	return 0;
}

