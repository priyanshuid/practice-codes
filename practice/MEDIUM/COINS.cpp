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
unsigned long table[50000000];
int ptr=-1;
unsigned long calculate(unsigned long);
int main()
{
	unsigned long n;
	memset(table,sizeof(table),0);
	while(scanf("%lu",&n)!=EOF)
	{
		unsigned long sum=calculate(n);
		printf("%lu\n",sum);
	}
}
unsigned long calculate(unsigned long n)
{
	if(n<=6)
		return n;
	else
	{
		unsigned long n1=n/2;
		unsigned long n2=n/3;
		unsigned long n3=n/4;
		if(n>50000000-1)	
			return max(n,max(n1,calculate(n1))+max(n2,calculate(n2))+max(n3,calculate(n3)));
		else
		{
			if(table[n1]==0)
				table[n1]=max(n1,calculate(n1));
			if(table[n2]==0)
				table[n2]=max(n2,calculate(n2));
			if(table[n3]==0)
				table[n3]=max(n3,calculate(n3));
				return max(n,table[n1]+table[n2]+table[n3]);
		}
	}
	
}
