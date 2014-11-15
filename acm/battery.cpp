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
	int n,k;
	while(scanf("%d %d",&n,&k)==2)
	{
		int ar[2*n*k];
		for(int i=0;i<2*n*k;i++)
		scanf("%d",&ar[i]);
		sort(ar,ar+2*n*k);
		int max=0;
		for(int i=0;i<2*n;i=i+2)
		{
			int diff=ar[i+1]-ar[i];
			if(diff>max)
			{
				max=diff;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}

