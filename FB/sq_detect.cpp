#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <string.h>
#include <fstream>

using namespace std;
int main()
{
	ifstream cin1;
	ofstream cout1;
	cin1.open("square_detector.txt");
	cout1.open("output.txt");
	int t;
	cin1>>t;
	for(int t1=0;t1<t;t1++)
	{
		int n;
		cin1>>n;
		char ar[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin1>>ar[i][j];
			}
		}
		int st_i=0,st_j=0;
		int breaker=0;
		for(st_i=0;st_i<n;st_i++)
		{
		
				for(st_j=0;st_j<n;st_j++)
				{
					if(ar[st_i][st_j]=='#')
					{
						breaker=1;
						break;
					}
				}
			if(breaker==1)
			break;
		}
		int en_i=st_i;
		while(en_i<n && ar[en_i][st_j]=='#')
			en_i++;
			en_i--;
		int flag1=1;
		for(int i=st_i;i<=en_i;i++)
		{
			for(int j=st_j;j<=st_j+en_i-st_i;j++)
			{
				if(ar[i][j]!='#')
				{
					flag1=0;
					break;
			}
			if(flag1==0)
			break;
			}	
		}
		if(flag1==1)
		{	
			for(int i=st_i;i<=en_i;i++)
			{
				for(int j=st_j;j<=st_j+en_i-st_i;j++)
				{
					ar[i][j]='.';
				}
			}
			int flag=1;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				
				{
					if(ar[i][j]=='#')
					{
						flag=0;
						break;
					}
				}
				if(flag==0)
				break;
			}
			string g="";
			if(flag==1)
				g="YES";
			else
				g="NO";
			cout1<<"Case #"<<t1+1<<":"<<g<<endl;
		}
		else
		{
			cout1<<"Case #"<<t1+1<<":"<<"NO"<<endl;
		}
	}
	return 0;
}

