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
		scanf("%d",&n);
		scanf("%d",&k);
		int ar[n];
		for(int i=0;i<n;i++)
			scanf("%d",&ar[i]);
		sort(ar,ar+n);
		int min_diff=ar[k-1]-ar[0];
		for(int i=k;i<n;i++)
		{
			if(ar[i]-ar[i-k+1]<min_diff)
				min_diff=ar[i]-ar[i-k+1];
		}
		cout<<min_diff<<endl;
		return 0;
}

