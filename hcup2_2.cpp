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
//	getline(cin,v);
	for(int i=0;i<t;i++)
		getline(cin,ar[i]);
	for(int i=0;i<t;i++)
	{
		string h=ar[i];
		for(int p=h.length()-1;p>=0;p--)
		{
			if(h.at(p)==')')
			{
				for(int j=p;j>=0;j--)
				{
					if((h.at(j)=='(' && (j==0 ||h.at(j-1)!=':')))
					{
						h.erase(h.begin()+p);
						h.erase(h.begin()+2);
						cout<<h;
						break;
					}
				}
			
			}
		}
	}
}
