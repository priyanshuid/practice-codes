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
	for(int i=0;i<t;i++)
	{
		int n,c,m;
		scanf("%d %d %d",&n,&c,&m);
		int val= (floor)(n/(float)c);
		int f_val=val+ (floor)(val/(float)m);
		cout<<f_val<<endl; 
	}
	return 0;
}


