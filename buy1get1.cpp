#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s;
		cin>>s;
		string::iterator p=s.begin(),r=s.end();
		sort(p,r);
		int count=0,flag=0;
		while(p!=s.end())
		{
			count++;
			if(*(p+1)==*p)
				p++;
			p++;
		}
	cout<<count<<endl;
	}
	return 0;	
}
