/*in this program the solution of a single iteration can be correct either by incrementing the first value of the last value of the considered 
subarray ,therefore calling the incrementing function recursively,we can calculate the minimum number of changes required to be done in order
to complete the job.*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
int algo(int ar[],int start,int end,int k,int m);
int maxm(int ar[],int start,int end);
bool required(int ar[],int start,int end,int m)
{
	int maxm=ar[start];
	for(int i=start;i<= end;i++)
	{
		if(ar[i]>maxm)
		maxm=ar[i];
	}
	int count=0;
	for(int i=start;i<= end;i++)
	{
		if(ar[i]==maxm)
		count++;
	}
	if(count==m)
	return true;
	return false;
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,k,m;
		cin>>n>>k>>m;
		int ar[n];
		for(int j=0;j<n;j++)
		cin>>ar[j];
		algo(ar,0,n,k,m);
	}
	return 0;
}
int algo(int ar[],int start,int end,int k,int m)
{
	for(int i=start;i<n-k+1;i++)
	{
		bool bol=required(ar,i,i+k,m);
		if(bol==true)
		
	}
}
int maxm(int ar[],int start,int end)
{
	
}

