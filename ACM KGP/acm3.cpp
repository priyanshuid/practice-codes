#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <string>
#include <string.h>
using namespace std;
int func(string a,string b)
{
	int count=0;
	if(b.length()==0)
		return 0;
	for(size_t i=a.find(b);i != string::npos;i = a.find(b, i + 1))
	count++;
	return count;
}
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		int count = 0;
		string s="1";
		for(int i=2;i<=n;i++)
		{
			char v[100];
			sprintf(v, "%d",i);
			string f1=v;
			s+=f1;
		}
		char p[100];
		string f2="";
			sprintf(p, "%d",k);
			f2=p;
			string f=f2;
		count= func(s,f);
		printf("%d\n",count);
	}
	return 0;
}

