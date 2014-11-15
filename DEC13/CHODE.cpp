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
		string inp;
		int hash[26];
		memset(hash,0,sizeof(hash));
			cin>>inp;
		string waste="";
		getline(cin,waste);
		string cypher="";
		getline(cin,cypher);
		int ii=0;
		while(ii<cypher.length())
		{
			char temp=cypher.at(ii);
		//	lower_cypher+=tolower(cypher.at(i));
		if(temp >=65 && temp <=90)
				hash[(int)temp+32-97]++;
			else if(temp >=97 && temp<=122)
				hash[(int)temp-97]++;
			ii++;
		}
		int ar[26];
		int indx=25;
		for(int i=0;i<26;i++)
		{
			int max=0;
			int max_j=0;
			for(int j=0;j<26;j++)
			{
				if(hash[j]>=max && hash[j]>0)
				{
					max_j=j;
					max=hash[j];
				}
			}
			if(max>0)
			{
			ar[indx--]=max_j;
			hash[max_j]=-1;
			}
		}
		indx=0;
		for(int i=0;i<26;i++)
		{
			if(hash[i]==0)
			ar[indx++]=i;
		}
		map <char,char> my_map;
		for(int i=0;i<26;i++)
		{
			my_map.insert(pair <char, char> ((char)(ar[i]+97),inp.at(i)));
		}
	//	for(int i=0;i<26;i++)
	//	cout<<my_map[inp[i]]<<inp.at(i)<<endl;
		string ans="";
		for(int i=0;i<cypher.length();i++)
		{
			if((int)cypher.at(i)>=97 & (int)cypher.at(i)<=122)
			{
				ans+=my_map[cypher.at(i)];
			}
			else if((int)cypher.at(i)>=65 && (int)cypher.at(i)<=90)
			{
				ans+=(char)((int)my_map[(char)(cypher.at(i)+32)]-32);
			}
			else
			ans+=cypher.at(i);
		}
		printf("%s\n",ans.c_str());
	}
	return 0;
}

