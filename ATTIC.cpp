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
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		char s[1000000];
		scanf("%s",&s);
		int k=0;
		while(s[k])
		k++;
		string a="";
		int count=0;
		int len=0;
		int max=0;
		for(int i=0;i<k;i++)
		{
			if(s[i]=='.')
				len++;
			else
			{
				if(max<len)
					{
					max=len;
					count++;
					}
					
				len=0;
				
			}
			
		}
		printf("%d\n",count);
	}
}

