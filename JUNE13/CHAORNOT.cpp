#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#include <stdlib.h>
#define unsigned long long ull
using namespace std;
int input()
{
int t=0;
char c;
		c=getchar_unlocked();
	while(c<'0' || c>'9')
		c=getchar_unlocked();
	while(c>='0' && c<='9')
	{
		t=(t<<3)+(t<<1)+c-'0';
		c=getchar_unlocked();
	}
	return(t);
}
int main()
{
	int m;
	m=input();
	if(m>=3)
	{
		int ar[m];
		for(int i=0;i<m;i++)
			ar[i]=input();
		int *st=&ar[0],*en=&ar[m];
		sort(st,en);
		int count=2;
		vector <int> list;
		list.push_back(ar[0]);
		list.push_back(ar[1]);
		int h;
		if(m<6435)
		h=m;
		else 
		h=6435;
         for(int i=2;i<h;i++)
         {
         	int flag=1;
			for(int j=0;j<list.size();j++)
         	{
         		for(int k=j+1;k<list.size();k++)
         		{
         				if(ar[i]-list[k]==list[k]-list[j])
         				{
         					flag=0;
         				}
         			
         		}
         	}
         	if(flag==1)
         	{
         		list.push_back(ar[i]);
         		count++;
         	}
        }
		if(count>2)
		{
			printf("%d\n",count);
			for(int i=0;i<count;i++)
			printf("%d ",list[i]);
		}
}
	else 
	cout<<0;
	return 0;
}


