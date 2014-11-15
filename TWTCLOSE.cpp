#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <memory>
#include <cstring>
#include <sstream>
#include <math.h>
#include <map>
#define unsigned long long ull
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	string f;
	getline(cin,f);
	char ar[n];
	memset(ar,'0',sizeof(ar));
	int count=0;
	for(int i=0;i<k;i++)
	{
		string s;
		int n1;
		getline(cin,s);
		stringstream ss(s);
		ss>>s;
		if(s=="CLICK")
		{
			ss>>n1;
			if(ar[n1-1]=='1')
			{
				ar[n1-1]='0';
				count--;
			}
			else
			{
				ar[n1-1]='1';
				count++;
			}
		}
		else if(s=="CLOSEALL")
		{
			count=0;
			memset(ar,0,sizeof(ar));
		}
		printf("%d\n",count);
	}
	return 0;
}

