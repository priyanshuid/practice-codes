/*This Program Finds A Path From The Given Starting Point To The Given Destination Point And Returns Appropriate Message If Path Does Not Exists*/
/*
     On Summer May-03-2013
	 Reference- Application Of Graph Theory By Vinod Chandra
	 */
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
		{	
			cout<<"No. Of Cities-";
				int k;
				cin>>k;
			int cc[k][k];
			cout<<"No. Of Paths-";
				int n;
				cin>>n;
			for(int i=0;i<k;i++)
			{
				for(int j=0;j<k;j++)
				cc[i][j]=0;
			}
			for(int i=0;i<n;i++)
			{
				int a,b;
				cin>>a>>b;
				cc[a-1][b-1]++;
			}
			vector <int> t;
			vector <int> p;
			cout<<"Starting Node To Find Path-";
				int v1;
				cin>>v1;
				v1--;
			cout<<"Ending Node Of The Path-";
				int v2;
				cin>>v2;
				v2--;
			t.push_back(v1);
			int init=v1;
			p.push_back(-1);
			vector <int>::iterator p1;
			p1=t.end()-1;
			int counter=0;
			while(counter<=k-1)
			{
				for(int j=0;j<k;j++)
				{
					int flag=0;
					if(cc[v1][j]>0)
					{
						for(int i=0;i<t.size();i++)
						{
							if(t[i]==j)
							flag=1;
						}
						if(flag==0)
						{
							t.push_back(j);
							p.push_back(v1);
						}
					}
				}
				counter++;
				p1=t.end()-1;
				if(v1<k-1)
					v1++;
				else
					v1=0;
			}
		/*	for(int i=0;i<t.size();i++)
				cout<<t[i]<<" ";
				cout<<endl;
			for(int i=0;i<p.size();i++)
				cout<<p[i]<<" ";*/
			int pflag=0;
			int pa=0;
			for(pa=0;pa<t.size();pa++)
			{
				if(t[pa]==v2)
				{
					pflag=1;
					break;
				}
			}
			if(pflag==0)
				cout<<"No Path Exists Between The Given Pair"<<endl;		
			else
			{
				vector<int> way;
				int pos=pa;
				way.push_back(t[pos]);
				int flag=1;
				while(true)
				{
					way.push_back(p[pos]);
					int i;
					for(i=t.size()-1;i>=0;i--)
					{
						if(t[i]==p[pos])
						break;
					}
					pos=i;
					if(pos==0)
						break;
				}	
				for(int i=way.size()-1;i>=0;i--)
				cout<<way[i]+1<<"--->";
				cout<<"END";
			}
		}
	return 0;
}
