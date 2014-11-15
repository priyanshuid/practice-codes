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
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		int n,m;
		cin>>n>>m;
		int p[m];
		for(int i=0;i<m;i++)
			cin>>p[i];
		int ar[102][102];
		int ci[n];
		int temp=0;
		for(int i=0;i<n;i++)
		{
			cin>>ci[temp];
			for(int j=0;j<ci[temp];j++)
				scanf("%d",&ar[i][j]);
			temp++;
		}
		int sum=0;
		for(int i=0;i<m;i++)
		{
			int room_no=p[i];
			int max=-1;
			int indx;
			for(int j=0;j<ci[p[i]];j++)
			{
				if(ar[room_no][j]>max)
					{
						max=ar[room_no][j];
						indx=j;
					}					
			}
			ar[room_no][indx]=0;
			sum+=max;
		}
		cout<<sum<<endl;
		
	}
	return 0;
}

