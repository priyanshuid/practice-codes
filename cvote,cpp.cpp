#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
struct cont
{
	string name;
	string country;
	int count;
};
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	cont ar[n];
	string vts[m];
	string temp[n];
	for(int i=0;i<n;i++)
		{
			scanf("%s %s",&ar[i].name,&ar[i].country);
			ar[i].count=0;
		}
	for(int i=0;i<m;i++)
		scanf("%s",&vts[i]);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(vts[i].compare(ar[j].name))
			{
				ar[j].count++;
				break;
			}
		}
	}
	int max=ar[0].count;
	for(int i=0;i<n;i++)
	{
		if()
	}
	return 0;
	
}
