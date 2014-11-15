#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
string func(string a,string b);
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		string a,b;
		cin>>a>>b;
		string c=func(a,b);
		cout<<c<<endl;
	}
	return 0;
}
string func(string a,string b)
{
	if(a.length()==0 || b.length()==0)
		return "";
	else if(a.at(0)==b.at(0))
		return (a.at(0)+func(a.substr(1),b.substr(1)));
	else
			return max(func(a,b.substr(1)),func(a.substr(1),b));
}
