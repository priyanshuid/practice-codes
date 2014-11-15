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
		string n,n1,n2;
		cin>>n;
		n1=n.substr(0,n.length()/2);
		if(n.length()%2!=0)
			n2=n.substr(n.length()/2+1,n.length()-1);
		else
			n2=n.substr(n.length()/2,n.length()-1);
		int f1[26],f2[26];
		for(int i=0;i<26;i++)
			{
				f1[i]=0;
				f2[i]=0;
			}
		for(int i=0;i<n1.length();i++)
		{
			char m=n1.at(i);
			int a=(int)m-97;
			f1[a]++;
		}
		for(int i=0;i<n2.length();i++)
		{
			char m=n2.at(i);
			int a=(int)m-97;
			f2[a]++;
		}
		int flag=1;
		for(int i=0;i<26;i++)
		{
			if(f1[i]!=f2[i])
		    {
		    	flag=0;
		    	break;
		    }
		}
		if(flag==1)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}

