#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
bool s(char*x,char*y)
{
	return!*x||*y && s(*x-*y?x:x+1,y+1);
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		char a[26000],b[26000];
		scanf("%s%s",&a,&b);
		int a1=strlen(a);
		int b1=strlen(b);
		char *min, *max;
		if(a1<b1)
		{
			min=a;
			max=b;
		}
		else
		{
			min=b;
			max=a;
		}
		bool f=s(min,max);
		if(f==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
