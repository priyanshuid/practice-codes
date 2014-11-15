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
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
	
	int n;
	int k;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&k);
	long long a=(long long)n*(n-1);
	a=a/2;
	cout<<a<<endl;
	}
	return 0;
}

