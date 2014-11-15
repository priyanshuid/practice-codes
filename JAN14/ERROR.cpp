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
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		string str;
		cin>>str;
		string temp;
		int flag=0;
		if(str.length()==1)
		{
			cout<<"Bad"<<endl;
			continue;
		}
		for(int i=0;i<str.length()-2;i++)
		{
			if(str.at(i)=='0' && str.at(i+1)=='1' && str.at(i+2)=='0')
				{
					flag=1;
					break;
				}
			if(str.at(i)=='1' && str.at(i+1)=='0' && str.at(i+2)=='1')
				{
					flag=1;
					break;
				}
		}
		if(flag==1)
		cout<<"Good"<<endl;
		else
		cout<<"Bad"<<endl;
	}
	return 0;
}

