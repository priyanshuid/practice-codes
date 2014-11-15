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
int main()
{
	int hash_for_x[11][300];
	int hash_for_y[11][300];
	int n;
	cin>>n;
	int ar[301][301];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&ar[i][j]);
		hash_for_x[ar[i][j]][i]=1;
		hash_for_y[ar[i][j]][j]=1;
		}
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int x1,y1,x2,y2;
		int counter=0;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		for(int i=1;i<11;i++)
		{
			for(int j=x1;j<=x2;j++)
			{
				if(hash_for_x[i][j]==1)
				{
					for(int k=y1;k<=y2;k++)
					{
						if(hash_for_y[i][k]==1)
						{
							counter++;
							goto label;
						}
					}
				}
			}
		label: ;
		}
		 
		cout<<counter<<endl;
	}
}

