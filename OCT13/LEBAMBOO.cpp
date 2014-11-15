#include <iostream>
#include <stdio.h>
using namespace std;
int min_diff(int ar1[],int ar2[],int n);
bool check(int ar1[],int ar2[],int n);
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		int n;
		scanf("%d",&n);
		int input[n];
		int temp[n];
		int temp1[n];
		int wanted[n];
		bool flag=false;
		for(int i=0;i<n;i++)
		{
				scanf("%d",&input[i]);
				temp[i]=input[i];
		}
		for(int i=0;i<n;i++)
			scanf("%d",&wanted[i]);
		int count=0;
		if(n==1	 &&  wanted[0]>input[0])
			printf("-1\n");		
		else
		{
			while(!(check( temp , wanted ,n )==true || flag==true))
			{
				int pos=min_diff(temp , wanted , n);
				temp[pos]--;
				for(int i=0;i<n;i++)
				{
					if(i!=pos)
					temp[i]++;
				}
								
				if(count==0)
				for(int v=0;v<n;v++)
					temp1[v]=temp[v];
				if(check(temp , input,n) == true || ( count!=0 && check(temp,temp1,n)==true))
					flag=true;
				count++;
				if(count>=100000)
				{
					count=-1;
					break;
				}
			}
			if(flag==true)
				printf("-1\n");
			else
				printf("%d\n",count);
		}
	}
	return 0;
}
int min_diff(int ar1[],int ar2[],int n)
{
	int min_dif=ar2[0]-ar1[0];
	int indx=0;	
	for(int i=1;i<n;i++)
	{
		int diff=ar2[i]-ar1[i];
		if(diff < min_dif)
		{
			diff=min_dif;
			indx=i;
		}
	}
	return indx;
}
bool check(int ar1[],int ar2[],int n)
{
	for(int i=0;i<n;i++)
	{	if(ar1[i]!=ar2[i])
			return false;
	}
	return true;
}	
			
