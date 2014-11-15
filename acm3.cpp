#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		char ar[n][m];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%c",&ar[i][j]);
			}
		}
		for(int i=n;i>=1;i--)
		{
			for(int j=n;j>=1;j--)
			{
				for(int p1=0;p1<i;p1++)
				{
					for(int p2=0;p2<j;p2++)
					{
						
					}
				}
				for(int p3=0;p3<i;p3++)
						{
							for(int p4=0;p4<j;p4++)
							{
						
