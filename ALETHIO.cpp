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
	char s[1000];
	scanf("%s",&s);
	int k=0;
	while(s[k])
	k++;
 	int max=0;
	int count=0;
	string a="";
	for(int j=0;j<k;j++)
	{
		int i=j;
		int flag=0;
		while(flag!=1)
		{	
		
			if(s[i]>='0' && s[i]<='9' && count<=1)
					 a=a+s[i];
				else if(s[i]>='A' && s[i]<='Z')
					{
						if(count==0)
						a=a+s[i];
						count++;
					}	
			else if(count>1 || i==k)
			{
				count=0;
				for(int j1=0;j1<a.length()-1;j1++)
				{
					if(a.at(j1)>='A' && a.at(j1)<='Z')
					a.at(j1)='9';
				}
			int sum=0;
		//	cout<<a<<endl;
			for(int j1=a.length()-1;j1>=0;j1--)
			{
				sum+=((int)a.at(j1)-48)*(pow(10,a.length()-1-j1));
			}
			if(sum>max)
				{
					max=sum;
					
				}
				a="";
				flag=1;		
			}
			i++;
		}
	}
	cout<<max;
}


