#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>
#include <algorithm>
#define MOD 1000000007
using namespace std;
class frnd_list
{
	public: 	 
			int a,b;
			frnd_list(int a1,int b1)
			{
				a=a1;
				b=b1;
			}
};
void qsort(vector <frnd_list> &v1,int start, int end);
int psort(vector <frnd_list> &v1,int start,int end);
int compareints(int *a,int *b)
{
	return (*a-*b);
}
void swap(frnd_list &a,frnd_list &b);
int main()
{
	int t;
	cin>>t;
	for(int c1=0;c1<t;c1++)
	{
		int n,m ;
		cin>>n>>m;
		vector<frnd_list> v1;
		vector<int> count(n,1);
		vector<int>::iterator c;
		c=count.begin();
		for(int i=0; i<m ;i++)
			{
				int n1,n2;
				scanf("%d %d",&n1,&n2);
				count[n1-1]=0;
				count[n2-1]=0;
				v1.push_back(frnd_list(n1,n2));
			}
		while(v1.size())
		{
			qsort(v1,0,v1.size()-1);
			vector<int> temp;
			temp.push_back(v1[0].a);
			temp.push_back(v1[0].b);
			vector<frnd_list>::iterator p=v1.begin();
			v1.erase(p);
			for(int i=0;i<temp.size();i++)
			{
				p=v1.begin();
				int ub=v1.size()-1,lb=0,mid;
				mid=(ub+lb)/2;
				int flg=0;
				while(lb <= ub && flg==0)
				{
					mid=(ub+lb)/2;
					if(temp[i]<v1[mid].a)
						ub=mid-1;
					else if(temp[i]>v1[mid].a)
						lb=mid+1;
					else
					{
						flg=1;
						vector<int>::iterator t1=temp.begin();
						vector<int>::iterator t2=temp.end();
						sort(t1,t2);
						int ub1=temp.size()-1,lb1=0,mid1,flag=0;
						mid1=(ub1+lb1)/2;
						while(lb1<=ub1 && flag==0)
						{
							mid1=(ub1+lb1)/2;
							if(v1[mid].b>temp[mid1])
								lb1=mid1+1;
							else if(temp[mid1]>v1[mid].b)
								ub1=mid1-1;
							else
								{
									flag=1;
								}
						}
						if(flag==0)
							temp.push_back(v1[mid].b);
						v1.erase(p);
					}
						p++;
				}
			}
		*c=temp.size()%MOD;
		c++;
		}
		
	
		
		long long int mul=1;
		int sum=0;
		for(int i=0;i<count.size();i++)
			{
				if(count[i]!=0)
				{
					mul=((mul%MOD)*(count[i]%MOD))%MOD;
					sum=sum+1;
				}
			}
			cout<<sum<<" "<<mul<<endl;
	}
}
void qsort(vector <frnd_list> &v1,int start, int end)
{
	int p;
	if(start<end)
	{
		p=psort(v1,start,end);
		qsort(v1,start,p-1);
		qsort(v1,p+1,end);
	}
}
int psort(vector <frnd_list> &v1,int start,int end)
{
	int p=start;
	frnd_list k=v1[start];
	for(int i=start+1;i<=end;i++)
	{
		if(v1[i].a <= k.a)
		{
			p++;
			swap(v1[i],v1[p]);
			
		}
		
	}
	swap(v1[p],v1[start]);
	return p;
}
void swap(frnd_list &a,frnd_list &b)
{
	frnd_list temp=a;
	a=b;
	b=temp;
}
