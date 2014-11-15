#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	string p;
		getline(cin,p);
	for(int q=0;q<t;q++)
	{
		
		string s;
		getline(cin,s);
		int ar[26];
		for(int p=0;p<26;p++)
		ar[p]=0;
		for(int i=0;i<s.length();i++)
		{
			if((int)s.at(i)>=65 && (int)s.at(i)<=90)
			{
				ar[s.at(i)-65]=1;
			}
			else if((int)s.at(i)>=97 && (int)s.at(i)<=122)
			{
				ar[s.at(i)-97]=1;
			}
		}
		int pos=100;
		for(int g=0;g<26;g++)
		{
			if(ar[g]==0)
			{
				pos=g;
				break;
			}
		}
		if(pos!=100)
		cout<<(char)(pos+65)<<endl;
		else
		cout<<'~'<<endl;
		
	}
	return 0;
}

























