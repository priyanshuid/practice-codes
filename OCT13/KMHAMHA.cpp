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
		vector <apair> qx;
		vector <apair> qy;
		for(int i=0;i<n;i++)
		{
			int a,b;			
			scanf("%d %d",&a,&b);
			px.push_back(make_pair(a,b));
			py.push_back(make_pair(a,b));
			qx.push_back(make_pair(a,b));
			qy.push_back(make_pair(a,b));
			
		}
		sort(px.begin(),px.end(),cmp_x);
		sort(py.begin(),py.end(),cmp_y);		
		int count=0;
		while(px.size()!=0 || py.size()!=0)
		{
			int count_x=1;
			int count_y=1;
			int max_x=0,max_y=0;
			int indx_x,indx_y;			
			int i,j;
			for(i=1;i<=px.size();i++)
			{
				if(i<px.size() && px[i].x == px[i-1].x)
					count_x++;
				else
				{	
					if(max_x<count_x)
					{	
						max_x=count_x;
						indx_x=i-1;
					}
				count_x=1;
				}	
			}

			for(j=1;j<=py.size();j++)
			{
				if(j<py.size() && py[j].y == py[j-1].y)
					count_y++;
				else 
				{
					if(max_y<count_y)
					{	
						max_y=count_y;
						indx_y=j-1;
					}
					count_y=1;
				}	
			}
			if(max_x>=max_y)
			{
				int fi=first_indx_x(px,px[indx_x].x);				
				for(int p=fi;p<=indx_x;p++)
				{						
					int pos=b_search(py,py.size(), px[p]);
					
						if(pos!=-1)
							py.erase(py.begin()+pos);
				//			py.erase(std::remove(py.begin(),py.end(),px[p]),py.end());
				}
					px.erase(px.begin()+fi,px.begin()+indx_x+1);
			}
			else
			{
				int fi=first_indx_y(py,py[indx_y].y);				
				for(int p=fi;p<=indx_y;p++)
				{					
					int pos=b_search(px,px.size(),py[p]);
					if(pos!=-1)
						px.erase(px.begin()+pos);
				//		  px.erase(std::remove(px.begin(),px.end(),py[p]),px.end());
					
				}
					py.erase(py.begin()+fi,py.begin()+indx_y+1);
			}
			count++;
			//cout<<px.size()<<" "<<py.size()<<endl;
		}
		int count1=0;
		while(qx.size()!=0 || qy.size()!=0)
		{
			int count_x=1;
			int count_y=1;
			int i=1,j=1;			
			for(i;i<qx.size();i++)
			{	
				if(qx[i].x!=qx[i-1].x)
				break;					
				
				count_x++;
			}
			for(j;j<qy.size();j++)
			{
				if(qy[j].y!=qy[j-1].y)
				break;
				
				count_y++;
			}
			if(count_x>=count_y)
			{
				for(int p=0;p<i;p++)
				{
					int pos=b_search(qy,qy.size(),qx[p]);
					if(pos!=-1)
						qy.erase(qy.begin()+pos);
				}
					qx.erase(qx.begin(),qx.begin()+i);
			}
			else
			{
				for(int p=0;p<j;p++)
				{
					int pos=b_search(qx,qx.size(),qy[p]);
					if(pos!=-1)
						qx.erase(qx.begin()+pos);
				}
					qy.erase(qy.begin(),qy.begin()+j);
			}
			count1++;
		}				
		if(count1<count)
			count=count1;		
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
				
			
