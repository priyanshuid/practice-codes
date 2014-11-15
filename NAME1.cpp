#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		char a[40000],b[40000];
		string c;
		scanf("%s%s",&a,&b);
		int k;
		scanf("%d",&k);
		for(int i=0;i<k;i++)
		{
			string d;
			cin>>d;
			c+=d;
		}
		int ar1[26],ar2[26];
		for(int i=0;i<26;i++)
		{
			ar1[i]=0;
			ar2[i]=0;
		}
		for(int i=0;i<strlen(a);i++)
		{
			int v=(int)a[i];
			ar1[v-97]++;
		}
		for(int i=0;i<strlen(b);i++)
		{
			int v=(int)b[i];
			ar1[v-97]++;
		}
		for(int i=0;i<c.length();i++)
		{
			int v=(int)c.at(i);
			ar2[v-97]++;
		}
		int flag=0;
		for(int i=0;i<26;i++)
		{
			if(ar1[i]<ar2[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		cout<<"NO\n";
		else
		cout<<"YES\n";	
	}
	return 0;
}
