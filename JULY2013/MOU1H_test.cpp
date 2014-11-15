#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <memory.h>
#include <cstring>
#include <math.h>
#include <map>
#define unsigned long long ull
using namespace std;
vector <int> v;
int main()
{
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
			scanf("%d",&ar[i]);
			v.push_back(ar[i]);
		 }
		int count=0;
		int temp[100000];
		if(n==1)
			printf("1\n");
		else
		{	
			set <int> sha;
			while(v.size()>=1)
			{
				sha.clear();
				memset(temp,0,sizeof(temp));
				int val=0;
				for(int i=0;i<v.size()-1;i++)
				{
					temp[i]=(v[i+1]-v[i]);
					val++;
					sha.insert(v[i+1]-v[i]);
				}
				v.clear();
				for(int i=0;i<val;i++)
				{
					v.push_back(temp[i]);
				}
				count=(count+sha.size())%1000000009;
			}
			if(v[0]!=0)
			count++;
			printf("%d\n",count);
		}
	}
	return 0;
}
