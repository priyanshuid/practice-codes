
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;

VI v[100010];
vector <int> minm;
bool vis[100010];
int val[100010];
void dfs(int n,int &min)	//a simple depth-first search
{
	vis[n]=true;
	if(val[n]>=0)
	{
		if(min>val[n])
		min=val[n];
	}
	for(int i=0;i<v[n].size();i++)
		if(!vis[v[n][i]])
			dfs(v[n][i],min);
	return;
}

int main()
{

		int a,b,n,m;
		scanf("%d%d",&n,&m);
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
			v[i].clear();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			a--;
			b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i=0;i<n;i++)
			scanf("%d",&val[i]);
		int gmin=10010;
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(!vis[i])
			{
				int min=10010;
				dfs(i,min);
				minm.push_back(min);
			//	cout<<min<<endl;
				if(gmin>min)
				gmin=min;
				count++;

			}
		}
		if(count==1)
		{
			printf("0\n");
		}
		else
		{
			int sum=0;
			int flag=0;
			for(int i=0;i<minm.size();i++)
			{
				if(minm[i]==10010)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			printf("-1\n");
			else
			{
				for(int i=0;i<minm.size();i++)
					sum+=gmin+minm[i];	
				printf("%d\n",(sum-2*gmin));
			}
		}
		return 0;
}
