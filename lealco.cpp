#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int algo(int ar[],int m,int n,int k);
int main()
{
	int t;
	cin>>t;
	for(int p=0;p<t;p++)
	{
		int n,k,m;
		cin>>n>>k>>m;
		int ar[n],ar_cpy[n];
		for(int j=0;j<n;j++)
		{
			scanf("%d",&ar[j]);
			ar_cpy[j]=ar[j];
		}
		int count1=algo(ar,m,n,k);
		int *beg=&ar_cpy[0],*end=&ar_cpy[n];
		reverse(beg,end);
		int count2=algo(ar_cpy,m,n,k);
		if(count1<=count2)
		cout<<count1<<endl;
		else 
		cout<<count2<<endl;
	}
	return 0;
		
}


int algo(int ar[],int m,int n,int k)
{
		int count1=0;
		if(m==1 || m>k)
		{
			return -1;
		}
		else
		{
			for(int i=0;i<= n-k+1;i++)
			{
				int count=0;
				int max_m=ar[i];
				for(int j=i;j<i+k;j++)
				{
					if(max_m <= ar[j])				//finding maximum value
					max_m=ar[j];
				}
				for(int j=i;j<i+k;j++)
				{
					if(ar[j]==max_m)				//counting no. of terms equal to maxm value
					count++;			
				}
				if(count==m)
				{
					for(int j=i+k-1;j>=i;j--)
					{
						if(ar[j]==max_m)
						{
							count1++;				//incrementing value in array in case
							ar[j]++;
							break;
						}
					}
				}
			
			}
			
			
		}
	return count1;	
}
