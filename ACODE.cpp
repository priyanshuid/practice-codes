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
long long n[5005];
int main()
{
	string str;
	cin>>str;
	while (str!="0")
	{
		memset(n,0,sizeof(n));
		str=str+' ';
		n[0]=1;
		n[1]=1;
		for(int i=0;i<str.length()-1;i++)
		{
			if(str.at(i+1)=='0')
			{
				n[i+2]=n[i+1];
			}
			else if(str.at(i)=='0')
			{
				n[i+2]=n[i+1];
			}
			else if(str.at(i-1)<='2' && str.at(i-1)>'0')
			{
				n[i+2]=n[i]+n[i+1];
			}
			else
			n[i+2]=n[i+1];
		}
	
	//	for(int i=0;i<=str.length();i++)
	//	cout<<n[i]<<endl;
		cout<<n[str.length()]<<endl;
		cin>>str;
	}
	return 0;
}


