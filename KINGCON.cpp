#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		int n,m,k;
		cin>>n>>m>>k;
		vector <int> edge[n];
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d %d", &a,&b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		for(int i=0;i<n;i++)
			edge[i].push_back(-1);
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(edge[i][1]==-1)
			count++;
		}	
		int c1=n-count;
		c1*=k;
		cout<<c1<<endl;
		
	}
}
