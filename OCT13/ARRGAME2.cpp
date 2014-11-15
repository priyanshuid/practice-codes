#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int bsearch(int y[],int n,int val);
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		int n;
		scanf("%d",&n);
		int x[n];
		int y[n];
		long int count=0;
		int count_1=0;
		int count_2=0;
		int count_3=0;
		int count_4=0;
		for(int i=0;i<n;i++)
			scanf("%d",&x[i]);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&y[j]);
			if(y[j]==3)
				count_3++;
			if(y[j]==4)
				count_4++;
			if(y[j]==2)
				count_2++;
			if(y[j]==1)
				count_1++;
		}
		int *st_y=&y[0];
		int *en_y=&y[n];
		sort(st_y,en_y);
		//for(int i=0;i<n;i++)
	//		cout<<x[i]<<" ";
	//		cout<<endl;
	//	for(int j=0;j<n;j++)
	//		cout<<y[j]<<" ";
	//		cout<<endl;
		for(int i=0;i<n;i++)
		{			
			if(x[i]>3)
			{
				int pos=bsearch(y,n-1,x[i]+1);				
				if(pos!=-1)
				{				
					while(pos>0 && x[pos-1]==x[pos] && x[pos]>x[i])
						pos--;
					//cout<<pos<<endl;
					count+=n-pos;
					count+=count_1;
				}
			}
			else
			{
				if(x[i]==3)			
				{
					count+= n-count_3;
				}
				if(x[i]==2)
				{
					count+=n-count_3 -count_2-count_4;
				}
			}
		}
		double val=(double)count/n;
		printf("%.6lf\n",val);
	}
	return 0;
}
int bsearch(int y[],int n,int val)
{
	int mid=n/2;
	int st=0;
	int en=n;	
	while(st<=en)
	{
		mid=(st+en)/2;		
		if(y[mid] > val)
			en=mid-1;
		else if( y[mid] < val) 
			st=mid+1;
		else
			return mid;		
	}
	if(y[mid]>=val)
		return mid;
	else return -1;
}
