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
	for(int i=0;i<t;i++)
	{
		int n,c,m,l_val,f_val;
		scanf("%d %d %d",&n,&c,&m);
		int val= (floor)(n/(float)c);
		l_val=val;
		while(l_val>=m)
		{
			f_val=(floor)(l_val/(float)m);
			l_val=f_val+l_val%m;
			val=val+f_val;			
		}
		cout<<val<<endl; 
	}
	return 0;
}


