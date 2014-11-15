#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	string ar[t];
	string v;
	getline(cin,v);
	for(int i=0;i<t;i++)
		getline(cin,ar[i]);
	for(int i=0;i<t;i++)
	{
		string h="";
		for(int j=0;j<ar[i].length();j++)
		{
			if(!(((int)ar[i].at(j)>96 && (int)ar[i].at(j)<123) || (ar[i].at(j)==' ')))
			{
				if(!((j<ar[i].length()-1)&&(ar[i].at(j)==':' && (ar[i].at(j+1)!='('||ar[i].at(j+1)!=')'))))
				h=h+ar[i].at(j);
				else
				j++;
			}
		}
		cout<<h<<endl;
	}
	return 0;
}
