#include <iostream>
#include <stdio.h>			
using namespace std;
void func_max(long long int *ar,int n,long long int *S)
{
	long long int msf=-1000000001;
	long long int meh=0;
	for(int i=0;i<n;i++)
	{
		meh=meh+ar[i];
		msf=max(msf,meh);
		if(meh>0)
			meh=meh;
		else
			meh=0;
		S[i]=msf;
	}
}
void func_min(long long int *ar,int n,long long int *S)
{
	long long int msf=-1000000001;
	long long int meh=0;
	for(int i=0;i<n;i++)
	{
		meh=meh+ar[i];
		msf=max(msf,meh);
		if(meh>0)
			meh=meh;
		else
			meh=0;
		S[i]=-msf;
	}
	
}
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		int n;
		cin>>n;
		long long int ar[n],rev[n];
		for(int i=0;i<n;i++)
			{
				cin>>ar[i];
				rev[n-i-1]=ar[i];
			}
			long long int left_max[n],left_min[n],right_max[n],right_min[n];
			func_max(ar,n,left_max);
			func_max(rev,n,right_max);
			for(int i=0;i<n;i++)
			{
				ar[i]=-ar[i];
				rev[i]=-rev[i];
			}
			func_min(ar,n,left_min);
			func_min(rev,n,right_min);
			for(int i=0;i<n/2;i++)
			{
				long long int temp=left_min[i];
				left_min[i]=left_min[n-i-1];
				left_min[n-i-1]=temp;
				long long temp1=left_max[i];
				left_max[i]=left_max[n-i-1];
				left_max[n-i-1]=temp1;
			}
		/*	for(int i=0;i<n;i++)
				cout<<left_max[i]<<" ";
				cout<<endl;
			for(int i=0;i<n;i++)
				cout<<right_max[i]<<" ";
				cout<<endl;
			for(int i=0;i<n;i++)
				cout<<left_min[i]<<" ";
				cout<<endl;
			for(int i=0;i<n;i++)
				cout<<right_min[i]<<" ";
				cout<<endl;*/
			
			long long int max1=-1000000001;
			for(int i=0;i<n-1;i++)
			{
				long long int sum1=right_max[i]>left_min[i+1]?right_max[i]-left_min[i+1]:(-right_max[i]+left_min[i+1]);
				long long int sum2=right_min[i]>left_max[i+1]?right_min[i]-left_max[i+1]:(-right_min[i]+left_max[i+1]);
		//		cout<<sum1<<" "<<sum2<<endl;
				long long int cur=max(sum1,sum2);
				if(cur>max1)
				max1=cur;	
			}
			cout<<max1<<endl;
	}
	return 0;
}	


