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
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<int> v(a,a+n);
	sort(v.begin,v.end);
	for(int x=0;x<n;x++)
	{
		for(int y=0;y<n;y++)
		{
			if(!binary_search((x+1,n,(max(x,y)+abs(x-y)))||min(x,y)-abs(x-y)))
			cout<<v[x]<<v[y]<<(max(x,y)+abs(x-y)))<<(min(x,y)-abs(x,y));
			cout<<endl;
					}
	}
	}


