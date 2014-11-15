#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <math.h>
#include <memory.h>
#include <map>
#define unsigned long long ull
using namespace std;
bool vis[100001];
int val[100001];
vector <int> minm;
vector <int> v[100001];
int dfs(int n)
{
	int min=100001;
	vis[n]=true;
	if(val[n]>=0)
	{
		if(val[n]<min)
		min=val[n];
	}
	for(int i=0;i<v[n].size();i++)
	{
		if(!vis[v[n][i]])
			dfs(v[n][i]);
	}
	 return min;
}
int main()
{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			--a;
			--b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i=0;i<n;i++)
			scanf("%d",&val[i]);
		int glob_min=100001;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
			v[i].clear();
		for(int i=0;i<n;i++)
		{
			if(!vis[i])
			{
				int min=100001;
				dfs(i);
				cout<<min<<endl;
				minm.push_back(min);
				if(min<glob_min)
					glob_min=min;
					for(int j=0;j<n;j++)
					cout<<vis[j]<<" ";
					cout<<endl;
			}
		}
		int sum=0;
		for(int i=0;i<minm.size();i++)
		cout<<minm[i]<<" ";
		cout<<endl;
		for(int i=0;i<minm.size();i++)
			sum+=glob_min+minm[i];
		printf("%d\n",sum-glob_min);
	
	return 0;
}

