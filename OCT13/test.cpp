#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct apair
{
	int x,y;
};
apair make_pair(int a,int b)
{
	apair p;
	p.x=a;
	p.y=b;
	return p;
}
bool cmp_x(apair p1,apair p2)
{
	if(p1.x < p2.x)
		return true;
	else 
		return false;
}
bool cmp_y(apair p1,apair p2)
{
	if(p1.y < p2.y)
		return true;
	else
		return false;
}
int first_indx_x(vector <apair>px,int p);
int first_indx_y(vector <apair>py,int p);
int b_search(vector <apair> ar,int n,apair val);
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		int n;
		scanf("%d",&n);
		vector <apair> px;
		vector <apair> py;
		for(int i=0;i<n;i++)
		{
			int a,b;			
			scanf("%d %d",&a,&b);
			px.push_back(make_pair(a,b));
			py.push_back(make_pair(a,b));
			
		}
		sort(px.begin(),px.end(),cmp_x);
		sort(py.begin(),py.end(),cmp_y);		
		int count=0;
		int count_x=1;
		int count_y=1;
		int indx_x,indx_y;			
		int i,j;
		for(int i=1;i<n;i++)
		{
			if(px[i].x!=px[i-1].x)
				count_x++;
		}
		for(int i=1;i<n;i++)
		{
			if(py[i].y!=py[i-1].y)
				count_y++;
		}
		count=(count_x>count_y)?count_y:count_x;
		printf("%d\n",count);

	}
	return 0;
}
int b_search(vector <apair> ar,int n , apair val)
{

	for(int i=0;i<n;i++)
	{
		if(ar[i].x==val.x && ar[i].y==val.y)
		return i;
	}
	return -1;	
	/*int en=n-1;
	int mid= (st + en)/2;	
	while(st<=en)
	{
		mid=(st+en)/2;
		if(ar[mid].x==val.x && ar[mid].y==val.y)
			return mid;
		else if(ar[mid].x < val.x)
			st=mid+1; 
		else if(ar[mid].x > val.x)
			en=mid-1;
	}
	return -1;*/
}
int first_indx_x(vector <apair>px,int p)
{
	for(int i=0;i<px.size();i++)
	{
		if(px[i].x==p)
		return i;
	}
}
int first_indx_y(vector <apair>py,int p)
{
	for(int i=0;i<py.size();i++)
	{
		if(py[i].y==p)
		return i;
	}
}
				
			
