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
int val(int **ar,int i,int j,int n,int m);
void change(int **ar,int i,int j,int n,int m);
int func(int **ar,int i,int j,int n,int m,int &sum)
{
	cout<<i<<" "<<j<<" " <<sum<<endl;
	for(int i1=0;i1<n;i1++)
		{
			for(int j1=0;j1<m;j1++)
			{cout<<ar[i1][j1];
		}
		cout<<endl;
	}
	cout<<"---------------"<<endl;
	if(i==n-1 && j<m-1)
	{
		sum=sum+val(ar,i,j,n,m);
	//	change(ar,i,j,n,m);
		return func(ar,i,j+1,n,m,sum);
	}
	else if(i<n-1 && j==m-1)
	{
		sum+=val(ar,i,j,n,m);
	//	change(ar,i,j,n,m);
		return func(ar,i+1,j,n,m,sum);
	}
	else if(i==n-1 && j==m-1)
	{
		cout<<val(ar,i,j,n,m);
		int h= sum+val(ar,n-1,m-1,n,m);
		
	//	change(ar,n-1,m-1,n,m);
		return h;
	}
	else
		{
			cout<<val(ar,i,j,n,m)<<endl;
			sum+=val(ar,i,j,n,m);
	//		change(ar,i,j,n,m);
		//	int sum2=val(ar,i+1,j,n,m);
		//	int sum3=val(ar,i,j+1,n,m);
		//	if(sum3>sum2)
		//	func(ar,i,j+1,n,m,sum1);
		//	else
		//	func(ar,i+1,j,n,m,sum1);	
			return min(func(ar,i+1,j,n,m,sum),func(ar,i,j+1,n,m,sum));
		}
}
int val(int **ar,int i,int j,int n,int m)
{
	int sum=0,k,l,p,q;
	if(i==0 && j==0)
	{
		k=0;l=1;p=0;q=1;
	}
	else if(i==0 && j!=0)
	{
		if(j!=m-1)
			{k=0;l=1;p=j-1;q=j+1;}
		else if(j==m-1)
			{
			k=0;l=1;p=m-2;q=m-1;}
	}
	else if(j==0 && i!=0)
	{
		if(i!=n-1)
			{
			k=i-1;l=i+1;p=j;q=j+1;}
		else if(i==n-1)
		
		{
			k=n-2;l=n-1;p=j;q=j+1;}
	}
	else if(i==n-1)
	{
		if(j!=m-1)	{
			k=n-2;l=n-1;p=j-1;q=j+1;}
		else if(j==m-1)
		{
			k=n-2;l=n-1;p=m-2;n=m-1;}
	}
	else
	{
		k=i-1;l=i+1;p=j-1;q=j+1;}
	for(int i1=k;i1<=l;i1++)
	{
		for(int j1=p;j1<=q;j1++)
		{
			if(abs(i-i1)+abs(j-j1)<=1 && ar[i1][j1]==1)
			{
				sum=1;
				ar[i][j]=0;
			}
		}
	}
return sum;
}
void change(int **ar,int i,int j,int n,int m)
{
	int sum=0,k,l,p,q;
	if(i==0 && j==0)
	{
		k=0;l=1;p=0;q=1;
	}
	else if(i==0 && j!=0)
	{
		if(j!=m-1)
			{k=0;l=1;p=j-1;q=j+1;}
		else if(j==m-1)
			{
			k=0;l=1;p=m-2;q=m-1;}
	}
	else if(j==0 && i!=0)
	{
		if(i!=n-1)
			{
			k=i-1;l=i+1;p=j;q=j+1;}
		else if(i==n-1)
		
		{
			k=n-2;l=n-1;p=j;q=j+1;}
	}
	else if(i==n-1)
	{
		if(j!=m-1)	{
			k=n-2;l=n-1;p=j-1;q=j+1;}
		else if(j==m-1)
		{
			k=n-2;l=n-1;p=m-2;n=m-1;}
	}
	else
	{
		k=i-1;l=i+1;p=j-1;q=j+1;}
	for(int i1=k;i1<=l;i1++)
	{
		for(int j1=p;j1<=q;j1++)
		{
			if(abs(i-i1)+abs(j-j1)<=1 && ar[i1][j1]==1)
			{
				ar[i1][j1]=0;
				
			}
		}
	}
}
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		int n,m;
		cin>>n>>m;
		int **ar;
		ar=new int *[n];
		for(int i=0;i<n;i++)
		{
			ar[i]=new int[m];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				char a;
				cin>>a;
				ar[i][j]=(int)a-48;
			}
		}
		int cost=0;
		cost =func(ar,0,0,n,m,cost);
		cout<<cost<<endl;
	}
}	



