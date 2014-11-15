#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <memory.h>
#include <cstring>
#include <math.h>
#include <map>
#include <fstream>
#define unsigned long long ull
using namespace std;
vector <int> v;
bool hash[700000000][2];
int main()
{
	ifstream in ("inp.txt");
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		int n;
		scanf("%d",&n);	
		int ar[n];
		v.clear();
		for(int i=0;i<n;i++)
		{
			
			//scanf("%d",&ar[i]);
			v.push_back(ar[i]);
		}	
		memset(hash,false,sizeof(hash));
		int count=0;
		vector <int> temp;
		while(v.size()!=1)
		{
			temp.clear();
			for(int i=0;i<v.size()-1;i++)
			{
				temp.push_back(v[i+1]-v[i]);
				if(v[i+1]-v[i]>=0)
				hash[(int)fabs(v[i+1]-v[i])][0]=true;
				else
				hash[(int)fabs(v[i+1]-v[i])][1]=true;
				
			}
			v.clear();
			for(int i=0;i<temp.size();i++)
			{
				v.push_back(temp[i]);
				if(hash[(int)fabs(temp[i])][0]==true)
				{
					count++;
					hash[(int)fabs(temp[i])][0]=false;
				}
				if(hash[(int)fabs(temp[i])][1]==true)
				{
					count++;
					hash[(int)fabs(temp[i])][1]=false;
				}			
			}
		}
	//	cout<<v[0];
		if(v[0]!=0)
		count++;
		cout<<count<<endl;
		
		
		
	}
}
