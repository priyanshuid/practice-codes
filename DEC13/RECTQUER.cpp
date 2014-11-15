#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <string.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int ar[n+1][n+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		scanf("%d",&ar[i][j]);
	}
	int x1,y1,x2,y2;
	int q;
	cin>>q;
	for(int q1=0;q1<q;q1++)
	{
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int keep_y1=y1;
		set<int>hash;
		while(hash.size()<=10 && x1<=x2)
		{
			y1=keep_y1;
			while(hash.size()<=10 && y1<=y2)
			{
			hash.insert(ar[x1][y1]);
			y1++;
		}
		x1++;
		}
		cout<<hash.size()<<endl;
	}
	return 0;
}

