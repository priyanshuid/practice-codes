#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
struct node 
{
	int i,j,val;
};
int main()
{
	int t;
	cin>>t;
	string f;
	getline(cin,f);
	for(int i=0;i<t;i++)
	{
		int g=0;
		string s;
		getline(cin,s);
		int n;
		stringstream ss( s );
		ss>>n;
		int ar[n];
		for(int i=0;i<n;i++)
			ss>>ar[i];
		int *st=&ar[0],*en=&ar[n];
		sort(st,en);
		int sum[n/2];
		for(int i=0;i<n/2;i++)
		{
			sum[i]=ar[i]+ar[n-i-1];
		}
		int max=sum[0];
		int min=sum[0];
		for(int i=0;i<n/2;i++)
		{
			if(max<sum[i])
			max=sum[i];
			if(min>sum[i])
			min=sum[i];
		}
		cout<<max-min<<endl;
	}
}


