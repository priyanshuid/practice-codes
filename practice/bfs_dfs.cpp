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
using namespace std;
char color[10000];
int parent[10000];
bool visited[10000];
vector<int> ar[10000];
void bfs(int n)
{
	int q[10000];
	memset(color,'W',sizeof(color));
	int l=0,r=0;
	q[r]=n;
	color[n]='G';
	while(l<=r)
	{
		int elt=q[l];
		cout<<elt<<" ";
		l++;
		for(int i=0;i<ar[elt].size();i++)
		{
			if(color[ar[elt][i]]=='W')
			{
				q[++r]=ar[elt][i];
				color[ar[elt][i]]='G';
			}
		}
		color[elt]='B';
	}
}
void dfs(int n)
{
	visited[n]=true;
	for(int i=0;i<ar[n].size();i++)
	{
		if(visited[ar[n][i]]==false)
		{
			cout<<ar[n][i]<<" ";
			dfs(ar[n][i]);
		}
	}
}
int main()
{

	int n;
	memset(visited,false,sizeof(visited));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}
	int k;
	cin>>k;
	bfs(k);
	cout<<endl;
	dfs(k);
	return 0;
}
