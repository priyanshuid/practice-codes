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
#include <fstream>
using namespace std;
struct node
{
	vector <int> ar;
};
void solve(node buffer[][9],int fix[][9]);
void get_val(node &f,int fix[][9],int i,int j);
int main()
{
	ifstream inp;
	inp.open("input.txt");
	node buffer[9][9];
	int fix[9][9];
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		inp>>fix[i][j];
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
		for(int i1=0;i1<9;i1++)
		buffer[i][j].ar.push_back(i1+1);
		}
	}
	
	solve(buffer,fix);
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		cout<<fix[i][j]<<" ";
		cout<<endl;
	}
	
}
void solve(node buffer[][9],int fix[][9])
{
	int flag=0;
	while(flag!=2)
	{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(fix[i][j]==0)
			{
				get_val(buffer[i][j],fix,i,j);
				if(buffer[i][j].ar.size()==1)
				{
					fix[i][j]=buffer[i][j].ar[0];
				}
			}
		}
	}
	int vflag=1,count=0;
/*	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			
			if(fix[i][j]==0)
			{
				count++;
				flag=0;
				vflag=0;
				break;
			}
		}
		if(vflag==0)
		break;
	}
	if(count==0)
	flag=1;*/
	flag++;
	}
}
void get_val(node &f,int fix[][9],int i,int j)
{
	for(int i1=0;i1<9;i1++)
	{
		if(i1!=i)
		{
			for(int k=0;k<f.ar.size();k++)
			{
				if(f.ar[k]==fix[i1][j])
				f.ar.erase(f.ar.begin()+k);
				
				
			}
		
		}
	}
	for(int i1=0;i1<9;i1++)
	{
		if(i1!=j)
		{
			for(int k=0;k<f.ar.size();k++)
			{
				if(f.ar[k]==fix[i][i1])
				f.ar.erase(f.ar.begin()+k);
				
			}
		}
	}
	int cn,rn;
	if(i<3)
		cn=1;
	else if(i=3 && i<6)
		cn=2;
	else 
		cn=3;
	if(j<3)
		rn=1;
	else if(j>=3 && j<6)
		rn=2;
	else
		rn=3;	
	for(int i1=(cn-1)*3;i1<cn*3;i1++)
	{
		for(int j1=(rn-1)*3;j1<rn*3;j1++)
		{
			for(int k=0;k<f.ar.size();k++)
			{
				if(f.ar[k]==fix[i1][j1])
				f.ar.erase(f.ar.begin()+k);
			}
		}
	}		
}
