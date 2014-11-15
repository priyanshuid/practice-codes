#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <fstream>
#include <memory.h>
#include <cstring>
#include <math.h>
#include <tr1/unordered_map>
#define unsigned long long ull
using namespace std;


vector <int> v;
int main()
{
	int t;
	ifstream inp1("inp.txt");
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		int n;
		scanf("%d",&n);	
		int ar[n];
		v.clear();
		for(int i=0;i<n;i++)
		{
			//scanf("%d",&ar[i]);
			inp1>>ar[i];
			v.push_back(ar[i]);
		}	
		int count=0;
		vector <int> temp;
		tr1::unordered_map <int,bool> m;
		if(n==1)
		cout<<"1\n"<<endl;
		else
		{
			while(v.size()!=1)
			{
				temp.clear();
				m.clear();
				for(int i=0;i<v.size()-1;i++)
				{
					temp.push_back(v[i+1]-v[i]);
					pair<int,bool> vv (v[i+1]-v[i],true);
					m.insert(vv);
				}
				tr1::unordered_map<int,bool>::const_iterator g; 
			//	for(g=m.begin();g!=m.end();g++)
				//cout<<g->first<<" "<<g->second<<endl;				
				v.clear();
				for(int i=0;i<temp.size();i++)
				{
					v.push_back(temp[i]);
				/*	if(m[temp[i]]==true)
					{
						if(count>=1000000009)
						count=(count+1)%1000000009;
						count++;
						m[temp[i]]=false;
					}*/
				/*	tr1::unordered_map<int, bool> :: const_iterator got;
						got=m.find(temp[i]);
					if(got!=m.end())
					{
						if(got->second==true)
						{
						if(count>=1000000009)
						count=(count+1)%1000000009;
						count++;
						}
						
					}*/
					
						
						
				}
				count=(count+m.size())%1000000009;
			}
			if(v[0]!=0)
				count++;
			printf("%d\n",count);
		}
	}
	return 0;
}

