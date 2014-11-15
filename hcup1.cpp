#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream in;
ofstream out;
int main()
{
	int t;
	in.open("beautiful_stringstxt.txt");
	out.open("output.txt");
	in>>t;
	string ar[t];
	string hj;
	getline(in,hj);
	for(int i=0;i<t;i++)
	getline( in ,ar[i]);
	for(int i=0;i<t;i++)
	{
		string h="";
		for(int j=0;j<ar[i].length();j++)
		{
			if(((int)ar[i].at(j)>96  && (int)ar[i].at(j)<123  ) || ((int)ar[i].at(j)> 64 && (int)ar[i].at(j)< 91 ))
			h=h+ar[i].at(j);
		}
		for( int j=0;j<h.length();j++)
		{
			h.at(j)=tolower(h.at(j));
		}
		int sum=0, flag=26;
		while(h.length()!=0)
		{
			int count=1,maxcount=0;
			char maxcount_cht;
			for(int j=0;j<h.length();j++)
			{
			
				count=1;
				for(int b=0; b < h.length();b++)
				{
					if(j!=b && h.at(j)== h.at(b))
					count++;
				}
				if(count >= maxcount)
				{
					maxcount=count;
					maxcount_cht=h.at(j);
				}
			}
			sum=sum+maxcount*flag;
			flag--;
			string d="";
			for(int p=0;p<h.length();p++)
			{
				if(h.at(p)!=maxcount_cht)
				d=d+h.at(p);
			}
			h=d;
						
		}	
	out<<"Case #"<<i+1<<": "<<sum<<endl;
	}
	in.close();
	out.close();
}
